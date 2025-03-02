---
layout: default
title: "Topic 9: Waveform Display"
parent: Labs
nav_order: 9
---

# Topic 9: Waveform Display

## Overview

Topic 9 focuses on enhancing the OtoDecks application by implementing a dedicated WaveformDisplay component to visualize audio waveforms. This topic introduces:

- Creating a specialized WaveformDisplay class
- Using JUCE's AudioThumbnail for waveform visualization
- Implementing playhead tracking for visual feedback
- Handling user interactions with the waveform
- Improving the visual appearance of the application

## Implementation Details

### The WaveformDisplay Class

The WaveformDisplay class is responsible for visualizing the audio waveform and tracking the playback position.

#### Header File (WaveformDisplay.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class WaveformDisplay : public Component,
                        public ChangeListener
{
public:
    WaveformDisplay(AudioFormatManager& formatManagerToUse,
                   AudioThumbnailCache& cacheToUse);
    ~WaveformDisplay();

    void paint(Graphics&) override;
    void resized() override;

    // ChangeListener implementation
    void changeListenerCallback(ChangeBroadcaster* source) override;

    // File loading
    void loadURL(URL audioURL);
    
    // Playhead position
    void setPositionRelative(double pos);

private:
    AudioThumbnail audioThumbnail;
    bool fileLoaded;
    double position;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformDisplay)
};
```

#### Source File (WaveformDisplay.cpp)

```cpp
#include "WaveformDisplay.h"

WaveformDisplay::WaveformDisplay(AudioFormatManager& formatManagerToUse,
                               AudioThumbnailCache& cacheToUse)
    : audioThumbnail(1000, formatManagerToUse, cacheToUse),
      fileLoaded(false),
      position(0)
{
    // Register as a change listener for the audio thumbnail
    audioThumbnail.addChangeListener(this);
}

WaveformDisplay::~WaveformDisplay()
{
    // Unregister as a change listener
    audioThumbnail.removeChangeListener(this);
}

void WaveformDisplay::paint(Graphics& g)
{
    // Fill the background
    g.fillAll(Colours::black);
    
    // Draw the waveform
    g.setColour(Colours::lightgreen);
    
    if (fileLoaded)
    {
        // Draw the waveform
        audioThumbnail.drawChannel(g, 
                                  getLocalBounds(), 
                                  0, 
                                  audioThumbnail.getTotalLength(), 
                                  0, 
                                  1.0f);
        
        // Draw the playhead
        g.setColour(Colours::white);
        g.drawLine(position * getWidth(), 0, position * getWidth(), getHeight(), 2.0f);
    }
    else
    {
        // Draw a message if no file is loaded
        g.setFont(20.0f);
        g.drawText("No File Loaded", getLocalBounds(), Justification::centred, true);
    }
    
    // Draw a border
    g.setColour(Colours::grey);
    g.drawRect(getLocalBounds(), 1);
}

void WaveformDisplay::resized()
{
    // Nothing to do here
}

void WaveformDisplay::changeListenerCallback(ChangeBroadcaster* source)
{
    // Repaint when the audio thumbnail changes
    if (source == &audioThumbnail)
    {
        fileLoaded = audioThumbnail.getNumChannels() > 0;
        repaint();
    }
}

void WaveformDisplay::loadURL(URL audioURL)
{
    // Load the audio file into the thumbnail
    audioThumbnail.clear();
    fileLoaded = false;
    
    auto* reader = audioURL.createInputStream(false);
    if (reader != nullptr)
    {
        audioThumbnail.setSource(new URLInputSource(audioURL));
    }
}

void WaveformDisplay::setPositionRelative(double pos)
{
    // Update the playhead position
    if (pos != position)
    {
        position = pos;
        repaint();
    }
}
```

### Updating DeckGUI

The DeckGUI class is updated to use the WaveformDisplay component:

#### Header File (DeckGUI.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "WaveformDisplay.h"

class DeckGUI : public Component,
                public Button::Listener,
                public Slider::Listener,
                public FileDragAndDropTarget,
                public Timer
{
public:
    DeckGUI(DJAudioPlayer* player, 
            AudioFormatManager& formatManagerToUse,
            AudioThumbnailCache& cacheToUse);
    ~DeckGUI();

    void paint(Graphics&) override;
    void resized() override;

    // Button::Listener implementation
    void buttonClicked(Button* button) override;

    // Slider::Listener implementation
    void sliderValueChanged(Slider* slider) override;
    
    // FileDragAndDropTarget implementation
    bool isInterestedInFileDrag(const StringArray& files) override;
    void filesDropped(const StringArray& files, int x, int y) override;
    
    // Timer implementation
    void timerCallback() override;

private:
    // UI Components
    TextButton playButton{"PLAY"};
    TextButton stopButton{"STOP"};
    TextButton loadButton{"LOAD"};
    Slider volumeSlider;
    Slider speedSlider;
    Slider positionSlider;
    Label volumeLabel{"", "Volume"};
    Label speedLabel{"", "Speed"};
    Label positionLabel{"", "Position"};
    WaveformDisplay waveformDisplay;
    
    // Audio Components
    DJAudioPlayer* player;
    
    // Methods
    void loadFile();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckGUI)
};
```

#### Source File (DeckGUI.cpp)

```cpp
#include "DeckGUI.h"

DeckGUI::DeckGUI(DJAudioPlayer* _player, 
                AudioFormatManager& formatManagerToUse,
                AudioThumbnailCache& cacheToUse) 
    : player(_player),
      waveformDisplay(formatManagerToUse, cacheToUse)
{
    // Configure and add UI components
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);
    addAndMakeVisible(volumeSlider);
    addAndMakeVisible(speedSlider);
    addAndMakeVisible(positionSlider);
    addAndMakeVisible(volumeLabel);
    addAndMakeVisible(speedLabel);
    addAndMakeVisible(positionLabel);
    addAndMakeVisible(waveformDisplay);

    // Configure sliders
    volumeSlider.setRange(0.0, 1.0);
    volumeSlider.setValue(0.5);
    volumeSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    
    speedSlider.setRange(0.1, 3.0);
    speedSlider.setValue(1.0);
    speedSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    
    positionSlider.setRange(0.0, 1.0);
    positionSlider.setValue(0.0);
    positionSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);

    // Add listeners
    playButton.addListener(this);
    stopButton.addListener(this);
    loadButton.addListener(this);
    volumeSlider.addListener(this);
    speedSlider.addListener(this);
    positionSlider.addListener(this);
    
    // Start the timer for position updates
    startTimer(500);
}

DeckGUI::~DeckGUI()
{
    stopTimer();
}

void DeckGUI::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void DeckGUI::resized()
{
    // Layout the components
    const int margin = 10;
    const int buttonHeight = 30;
    const int sliderHeight = 30;
    const int labelWidth = 80;
    
    // Reserve space for the waveform
    auto area = getLocalBounds();
    waveformDisplay.setBounds(area.removeFromTop(200));
    
    // Position the buttons
    auto buttonArea = area.removeFromTop(buttonHeight + margin);
    playButton.setBounds(buttonArea.removeFromLeft(100).reduced(margin, 0));
    stopButton.setBounds(buttonArea.removeFromLeft(100).reduced(margin, 0));
    loadButton.setBounds(buttonArea.removeFromLeft(100).reduced(margin, 0));
    
    // Position the volume slider and label
    auto volumeArea = area.removeFromTop(sliderHeight + margin);
    volumeLabel.setBounds(volumeArea.removeFromLeft(labelWidth).reduced(margin, 0));
    volumeSlider.setBounds(volumeArea.reduced(margin, 0));
    
    // Position the speed slider and label
    auto speedArea = area.removeFromTop(sliderHeight + margin);
    speedLabel.setBounds(speedArea.removeFromLeft(labelWidth).reduced(margin, 0));
    speedSlider.setBounds(speedArea.reduced(margin, 0));
    
    // Position the position slider and label
    auto positionArea = area.removeFromTop(sliderHeight + margin);
    positionLabel.setBounds(positionArea.removeFromLeft(labelWidth).reduced(margin, 0));
    positionSlider.setBounds(positionArea.reduced(margin, 0));
}

void DeckGUI::buttonClicked(Button* button)
{
    if (button == &playButton)
    {
        player->play();
    }
    else if (button == &stopButton)
    {
        player->stop();
    }
    else if (button == &loadButton)
    {
        loadFile();
    }
}

void DeckGUI::sliderValueChanged(Slider* slider)
{
    if (slider == &volumeSlider)
    {
        player->setGain(slider->getValue());
    }
    else if (slider == &speedSlider)
    {
        player->setSpeed(slider->getValue());
    }
    else if (slider == &positionSlider)
    {
        player->setPositionRelative(slider->getValue());
    }
}

bool DeckGUI::isInterestedInFileDrag(const StringArray& files)
{
    // Check if any of the files are audio files
    for (const auto& file : files)
    {
        if (file.endsWith(".mp3") || file.endsWith(".wav") || file.endsWith(".aiff"))
        {
            return true;
        }
    }
    return false;
}

void DeckGUI::filesDropped(const StringArray& files, int x, int y)
{
    // Load the first audio file that was dropped
    for (const auto& file : files)
    {
        if (file.endsWith(".mp3") || file.endsWith(".wav") || file.endsWith(".aiff"))
        {
            URL fileURL = URL{File{file}};
            player->loadURL(fileURL);
            waveformDisplay.loadURL(fileURL);
            break;
        }
    }
}

void DeckGUI::timerCallback()
{
    // Update the position slider and waveform display
    double position = player->getPositionRelative();
    positionSlider.setValue(position, dontSendNotification);
    waveformDisplay.setPositionRelative(position);
}

void DeckGUI::loadFile()
{
    FileChooser chooser{"Select a file to play...", {}, "*.mp3;*.wav;*.aiff"};
    
    if (chooser.browseForFileToOpen())
    {
        URL fileURL = URL{chooser.getResult()};
        player->loadURL(fileURL);
        waveformDisplay.loadURL(fileURL);
    }
}
```

### Adding User Interaction to WaveformDisplay

To make the waveform display interactive, we can add the ability to click on the waveform to change the playback position:

#### Header File (WaveformDisplay.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class WaveformDisplay : public Component,
                        public ChangeListener
{
public:
    WaveformDisplay(AudioFormatManager& formatManagerToUse,
                   AudioThumbnailCache& cacheToUse);
    ~WaveformDisplay();

    void paint(Graphics&) override;
    void resized() override;
    void mouseDown(const MouseEvent& event) override;

    // ChangeListener implementation
    void changeListenerCallback(ChangeBroadcaster* source) override;

    // File loading
    void loadURL(URL audioURL);
    
    // Playhead position
    void setPositionRelative(double pos);
    
    // Set a callback function for position changes
    void setPositionCallback(std::function<void(double)> callback);

private:
    AudioThumbnail audioThumbnail;
    bool fileLoaded;
    double position;
    std::function<void(double)> positionCallback;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformDisplay)
};
```

#### Source File (WaveformDisplay.cpp)

```cpp
#include "WaveformDisplay.h"

WaveformDisplay::WaveformDisplay(AudioFormatManager& formatManagerToUse,
                               AudioThumbnailCache& cacheToUse)
    : audioThumbnail(1000, formatManagerToUse, cacheToUse),
      fileLoaded(false),
      position(0),
      positionCallback(nullptr)
{
    // Register as a change listener for the audio thumbnail
    audioThumbnail.addChangeListener(this);
}

WaveformDisplay::~WaveformDisplay()
{
    // Unregister as a change listener
    audioThumbnail.removeChangeListener(this);
}

void WaveformDisplay::paint(Graphics& g)
{
    // Fill the background
    g.fillAll(Colours::black);
    
    // Draw the waveform
    g.setColour(Colours::lightgreen);
    
    if (fileLoaded)
    {
        // Draw the waveform
        audioThumbnail.drawChannel(g, 
                                  getLocalBounds(), 
                                  0, 
                                  audioThumbnail.getTotalLength(), 
                                  0, 
                                  1.0f);
        
        // Draw the playhead
        g.setColour(Colours::white);
        g.drawLine(position * getWidth(), 0, position * getWidth(), getHeight(), 2.0f);
    }
    else
    {
        // Draw a message if no file is loaded
        g.setFont(20.0f);
        g.drawText("No File Loaded", getLocalBounds(), Justification::centred, true);
    }
    
    // Draw a border
    g.setColour(Colours::grey);
    g.drawRect(getLocalBounds(), 1);
}

void WaveformDisplay::resized()
{
    // Nothing to do here
}

void WaveformDisplay::mouseDown(const MouseEvent& event)
{
    // Calculate the relative position
    double clickPosition = event.x / (double)getWidth();
    
    // Call the position callback if it exists
    if (positionCallback != nullptr)
    {
        positionCallback(clickPosition);
    }
}

void WaveformDisplay::changeListenerCallback(ChangeBroadcaster* source)
{
    // Repaint when the audio thumbnail changes
    if (source == &audioThumbnail)
    {
        fileLoaded = audioThumbnail.getNumChannels() > 0;
        repaint();
    }
}

void WaveformDisplay::loadURL(URL audioURL)
{
    // Load the audio file into the thumbnail
    audioThumbnail.clear();
    fileLoaded = false;
    
    auto* reader = audioURL.createInputStream(false);
    if (reader != nullptr)
    {
        audioThumbnail.setSource(new URLInputSource(audioURL));
    }
}

void WaveformDisplay::setPositionRelative(double pos)
{
    // Update the playhead position
    if (pos != position)
    {
        position = pos;
        repaint();
    }
}

void WaveformDisplay::setPositionCallback(std::function<void(double)> callback)
{
    // Set the position callback
    positionCallback = callback;
}
```

### Updating DeckGUI to Use the Position Callback

The DeckGUI class is updated to set a position callback for the waveform display:

```cpp
DeckGUI::DeckGUI(DJAudioPlayer* _player, 
                AudioFormatManager& formatManagerToUse,
                AudioThumbnailCache& cacheToUse) 
    : player(_player),
      waveformDisplay(formatManagerToUse, cacheToUse)
{
    // ... (existing code)
    
    // Set the position callback
    waveformDisplay.setPositionCallback([this](double pos) {
        player->setPositionRelative(pos);
    });
    
    // ... (existing code)
}
```

## OOP Concepts Demonstrated

Topic 9 introduces several important object-oriented programming concepts:

### Separation of Concerns

The implementation demonstrates the Separation of Concerns principle by creating a dedicated WaveformDisplay class for visualizing audio waveforms. This separates the concerns of audio playback (DJAudioPlayer) and waveform visualization (WaveformDisplay).

```cpp
class WaveformDisplay : public Component,
                        public ChangeListener
{
    // ...
};
```

### Callback Functions

The implementation demonstrates the use of callback functions to handle user interactions:

```cpp
void setPositionCallback(std::function<void(double)> callback);
```

This allows the WaveformDisplay class to notify other components when the user clicks on the waveform, without needing to know which components are interested in this information.

### Event Handling

The implementation demonstrates event handling through the use of the ChangeListener interface:

```cpp
void changeListenerCallback(ChangeBroadcaster* source) override;
```

This allows the WaveformDisplay class to be notified when the audio thumbnail changes, so it can update its display.

### Composition

The implementation continues to demonstrate composition by adding the WaveformDisplay component to the DeckGUI class:

```cpp
private:
    // UI Components
    // ...
    WaveformDisplay waveformDisplay;
    // ...
};
```

### Encapsulation

The implementation demonstrates encapsulation by hiding the implementation details of the WaveformDisplay class:

```cpp
private:
    AudioThumbnail audioThumbnail;
    bool fileLoaded;
    double position;
    std::function<void(double)> positionCallback;
```

The private members are hidden from other classes, and access is provided through public methods.

## Key Takeaways

1. **Specialized Components**: Creating specialized components for specific tasks improves code organization and maintainability.

2. **Visual Feedback**: Providing visual feedback to the user enhances the user experience.

3. **User Interaction**: Allowing users to interact with the waveform display makes the application more intuitive.

4. **Callback Functions**: Using callback functions allows components to communicate without tight coupling.

5. **Event Handling**: Using event handling allows components to respond to changes in other components.

## Next Steps

The next topic will build upon this foundation by implementing a playlist component to allow users to manage multiple audio files.

## Visual Elements

In the JUCE application, the main window would now have two decks side by side, each with:

- A waveform display at the top, showing the audio waveform and a playhead indicating the current playback position
- Three buttons: "PLAY", "STOP", and "LOAD"
- A volume slider with a label
- A speed slider with a label
- A position slider with a label

The user can load audio files into each deck, play and stop them independently, and adjust the volume, speed, and position of each deck. The waveform display shows the audio being played, and the playhead moves to indicate the current playback position. The user can also click on the waveform to change the playback position.
