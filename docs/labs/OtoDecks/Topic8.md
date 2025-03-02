---
layout: default
title: "Topic 8: The DeckGUI and DJAudioPlayer"
parent: Labs
nav_order: 8
---

# Topic 8: The DeckGUI and DJAudioPlayer

## Overview

Topic 8 focuses on improving the architecture of the OtoDecks application by creating dedicated classes for the audio player and GUI components. This topic introduces:

- Creating a DJAudioPlayer class to encapsulate audio playback functionality
- Implementing a DeckGUI class to represent a single deck interface
- Using composition to create reusable components
- Implementing communication between components
- Creating multiple decks for DJ mixing

## Implementation Details

### The DJAudioPlayer Class

The DJAudioPlayer class encapsulates all the audio playback functionality, making it reusable and easier to maintain.

#### Header File (DJAudioPlayer.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class DJAudioPlayer : public AudioSource {
public:
    DJAudioPlayer(AudioFormatManager& _formatManager);
    ~DJAudioPlayer();

    // AudioSource methods
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    // Player controls
    void loadURL(URL audioURL);
    void play();
    void stop();
    void setPosition(double posInSecs);
    void setPositionRelative(double pos);
    
    // Getters
    double getPositionRelative();
    
    // Audio processing
    void setGain(double gain);
    void setSpeed(double ratio);

private:
    AudioFormatManager& formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    ResamplingAudioSource resampleSource{&transportSource, false, 2};
};
```

#### Source File (DJAudioPlayer.cpp)

```cpp
#include "DJAudioPlayer.h"

DJAudioPlayer::DJAudioPlayer(AudioFormatManager& _formatManager) 
    : formatManager(_formatManager)
{
}

DJAudioPlayer::~DJAudioPlayer()
{
    // Clean up resources
    transportSource.setSource(nullptr);
    readerSource = nullptr;
}

void DJAudioPlayer::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void DJAudioPlayer::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    if (readerSource.get() == nullptr)
    {
        bufferToFill.clearActiveBufferRegion();
        return;
    }
    
    resampleSource.getNextAudioBlock(bufferToFill);
}

void DJAudioPlayer::releaseResources()
{
    transportSource.releaseResources();
    resampleSource.releaseResources();
}

void DJAudioPlayer::loadURL(URL audioURL)
{
    auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
    
    if (reader != nullptr)
    {
        std::unique_ptr<AudioFormatReaderSource> newSource(new AudioFormatReaderSource(reader, true));
        transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
        readerSource.reset(newSource.release());
    }
}

void DJAudioPlayer::play()
{
    transportSource.start();
}

void DJAudioPlayer::stop()
{
    transportSource.stop();
}

void DJAudioPlayer::setPosition(double posInSecs)
{
    transportSource.setPosition(posInSecs);
}

void DJAudioPlayer::setPositionRelative(double pos)
{
    if (readerSource.get() != nullptr)
    {
        double posInSecs = pos * transportSource.getLengthInSeconds();
        setPosition(posInSecs);
    }
}

double DJAudioPlayer::getPositionRelative()
{
    if (transportSource.getLengthInSeconds() > 0.0)
    {
        return transportSource.getCurrentPosition() / transportSource.getLengthInSeconds();
    }
    return 0.0;
}

void DJAudioPlayer::setGain(double gain)
{
    transportSource.setGain(gain);
}

void DJAudioPlayer::setSpeed(double ratio)
{
    resampleSource.setResamplingRatio(ratio);
}
```

### The DeckGUI Class

The DeckGUI class represents a single deck interface, containing buttons, sliders, and a DJAudioPlayer instance.

#### Header File (DeckGUI.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"

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
    
    // Audio Components
    DJAudioPlayer* player;
    AudioThumbnail audioThumbnail;
    
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
      audioThumbnail(1000, formatManagerToUse, cacheToUse)
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
    
    // Configure audio thumbnail
    audioThumbnail.addChangeListener(this);
    
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
    
    g.setColour(Colours::grey);
    g.fillRect(getLocalBounds().removeFromTop(200));
    
    g.setColour(Colours::orange);
    
    // Draw the waveform
    if (audioThumbnail.getNumChannels() > 0)
    {
        audioThumbnail.drawChannel(g, 
                                  getLocalBounds().removeFromTop(200), 
                                  0, 
                                  audioThumbnail.getTotalLength(), 
                                  0, 
                                  1.0f);
    }
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
    auto waveformArea = area.removeFromTop(200);
    
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
            player->loadURL(URL{File{file}});
            audioThumbnail.setSource(new FileInputSource(File{file}));
            break;
        }
    }
}

void DeckGUI::timerCallback()
{
    // Update the position slider
    positionSlider.setValue(player->getPositionRelative(), dontSendNotification);
    repaint();
}

void DeckGUI::loadFile()
{
    FileChooser chooser{"Select a file to play...", {}, "*.mp3;*.wav;*.aiff"};
    
    if (chooser.browseForFileToOpen())
    {
        player->loadURL(URL{chooser.getResult()});
        audioThumbnail.setSource(new FileInputSource(chooser.getResult()));
    }
}
```

### Updating MainComponent

The MainComponent class is updated to use the DJAudioPlayer and DeckGUI classes:

#### Header File (MainComponent.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "DeckGUI.h"

class MainComponent : public AudioAppComponent
{
public:
    MainComponent();
    ~MainComponent();

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void paint(Graphics& g) override;
    void resized() override;

private:
    // Audio Components
    AudioFormatManager formatManager;
    AudioThumbnailCache thumbnailCache{100};
    
    // DJ Audio Players
    DJAudioPlayer player1{formatManager};
    DJAudioPlayer player2{formatManager};
    
    // Mixer
    MixerAudioSource mixerSource;
    
    // GUI Components
    DeckGUI deck1{&player1, formatManager, thumbnailCache};
    DeckGUI deck2{&player2, formatManager, thumbnailCache};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
```

#### Source File (MainComponent.cpp)

```cpp
#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Register audio formats
    formatManager.registerBasicFormats();
    
    // Add GUI components
    addAndMakeVisible(deck1);
    addAndMakeVisible(deck2);
    
    // Set up audio device manager
    setAudioChannels(0, 2);
    
    // Set component size
    setSize(800, 600);
}

MainComponent::~MainComponent()
{
    // Clean up audio resources
    shutdownAudio();
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    // Set up mixer
    mixerSource.addInputSource(&player1, false);
    mixerSource.addInputSource(&player2, false);
    
    // Prepare players
    player1.prepareToPlay(samplesPerBlockExpected, sampleRate);
    player2.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
    // Prepare mixer
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    mixerSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    // Release resources for players
    player1.releaseResources();
    player2.releaseResources();
    
    // Release resources for mixer
    mixerSource.releaseResources();
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // Layout the decks side by side
    auto area = getLocalBounds();
    deck1.setBounds(area.removeFromLeft(getWidth() / 2));
    deck2.setBounds(area);
}
```

## OOP Concepts Demonstrated

Topic 8 introduces several important object-oriented programming concepts:

### Composition

The implementation demonstrates composition by creating specialized classes for different aspects of the application:

- `DJAudioPlayer` encapsulates audio playback functionality
- `DeckGUI` encapsulates the user interface for a single deck
- `MainComponent` composes these components to create the complete application

This approach follows the principle of "composition over inheritance," where complex functionality is built by combining simpler components.

```cpp
// In MainComponent.h
DJAudioPlayer player1{formatManager};
DJAudioPlayer player2{formatManager};
DeckGUI deck1{&player1, formatManager, thumbnailCache};
DeckGUI deck2{&player2, formatManager, thumbnailCache};
```

### Dependency Injection

The implementation demonstrates dependency injection by passing dependencies to objects through their constructors:

```cpp
DeckGUI::DeckGUI(DJAudioPlayer* player, 
                AudioFormatManager& formatManagerToUse,
                AudioThumbnailCache& cacheToUse)
```

This approach makes the code more testable and flexible, as dependencies can be easily swapped out.

### Interface Segregation

The implementation demonstrates interface segregation by implementing only the interfaces that are needed:

```cpp
class DeckGUI : public Component,
                public Button::Listener,
                public Slider::Listener,
                public FileDragAndDropTarget,
                public Timer
```

Each interface provides a specific set of functionality, and the class implements only the interfaces it needs.

### Single Responsibility Principle

The implementation demonstrates the Single Responsibility Principle by giving each class a single responsibility:

- `DJAudioPlayer` is responsible for audio playback
- `DeckGUI` is responsible for the user interface
- `MainComponent` is responsible for coordinating the components

This makes the code more maintainable and easier to understand.

### Encapsulation

The implementation demonstrates encapsulation by hiding the implementation details of each class:

```cpp
private:
    AudioFormatManager& formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    ResamplingAudioSource resampleSource{&transportSource, false, 2};
```

The private members are hidden from other classes, and access is provided through public methods.

## Key Takeaways

1. **Modular Design**: Breaking down the application into smaller, focused classes improves code organization and maintainability.

2. **Composition**: Building complex functionality by combining simpler components is a powerful design approach.

3. **Dependency Injection**: Passing dependencies through constructors makes the code more testable and flexible.

4. **Interface Segregation**: Implementing only the interfaces that are needed makes the code more focused and easier to understand.

5. **Single Responsibility Principle**: Giving each class a single responsibility makes the code more maintainable and easier to understand.

## Next Steps

The next topic will build upon this foundation by implementing a waveform display to visualize the audio being played.

## Visual Elements

In the JUCE application, the main window would now have two decks side by side, each with:

- A waveform display at the top
- Three buttons: "PLAY", "STOP", and "LOAD"
- A volume slider with a label
- A speed slider with a label
- A position slider with a label

The user can load audio files into each deck, play and stop them independently, and adjust the volume, speed, and position of each deck. The waveform display shows the audio being played, and the position slider shows the current playback position.
