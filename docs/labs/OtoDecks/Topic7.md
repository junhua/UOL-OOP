---
layout: default
title: "Topic 7: JUCE buttons, sliders and audio"
parent: Labs
nav_order: 7
---

# Topic 7: JUCE buttons, sliders and audio

## Overview

Topic 7 builds upon the basic JUCE application structure introduced in Topic 6 by adding interactive UI controls (buttons and sliders) and implementing audio playback functionality. This topic focuses on:

- Adding and configuring UI controls (buttons and sliders)
- Implementing event listeners for user interactions
- Setting up audio playback using JUCE's audio components
- Understanding the JUCE audio architecture
- Creating a basic DJ deck interface

## Implementation Details

### Adding UI Controls

The first step is to add UI controls to the main component. This involves:

1. Declaring the UI components in the header file
2. Creating and configuring the components in the constructor
3. Positioning the components in the `resized()` method
4. Implementing event listeners for user interactions

#### MainComponent.h

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainComponent : public Component,
                      public Button::Listener,
                      public Slider::Listener
{
public:
    MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;
    void resized() override;

    // Button::Listener implementation
    void buttonClicked(Button* button) override;

    // Slider::Listener implementation
    void sliderValueChanged(Slider* slider) override;

private:
    // UI Components
    TextButton playButton{"PLAY"};
    TextButton stopButton{"STOP"};
    Slider volumeSlider;
    Slider speedSlider;
    Label volumeLabel{"", "Volume"};
    Label speedLabel{"", "Speed"};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
```

#### MainComponent.cpp

```cpp
#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Configure and add UI components
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(volumeSlider);
    addAndMakeVisible(speedSlider);
    addAndMakeVisible(volumeLabel);
    addAndMakeVisible(speedLabel);

    // Configure sliders
    volumeSlider.setRange(0.0, 1.0);
    volumeSlider.setValue(0.5);
    volumeSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    
    speedSlider.setRange(0.1, 3.0);
    speedSlider.setValue(1.0);
    speedSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);

    // Add listeners
    playButton.addListener(this);
    stopButton.addListener(this);
    volumeSlider.addListener(this);
    speedSlider.addListener(this);

    // Set component size
    setSize(600, 400);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // Layout the components
    const int margin = 10;
    const int buttonHeight = 30;
    const int sliderHeight = 30;
    const int labelWidth = 80;
    
    // Position the buttons
    playButton.setBounds(margin, margin, 100, buttonHeight);
    stopButton.setBounds(margin + 110, margin, 100, buttonHeight);
    
    // Position the volume slider and label
    volumeLabel.setBounds(margin, margin + buttonHeight + margin, labelWidth, sliderHeight);
    volumeSlider.setBounds(margin + labelWidth, margin + buttonHeight + margin, getWidth() - margin * 2 - labelWidth, sliderHeight);
    
    // Position the speed slider and label
    speedLabel.setBounds(margin, margin + buttonHeight + margin + sliderHeight + margin, labelWidth, sliderHeight);
    speedSlider.setBounds(margin + labelWidth, margin + buttonHeight + margin + sliderHeight + margin, getWidth() - margin * 2 - labelWidth, sliderHeight);
}

void MainComponent::buttonClicked(Button* button)
{
    if (button == &playButton)
    {
        std::cout << "Play button clicked" << std::endl;
        // Play audio (to be implemented)
    }
    else if (button == &stopButton)
    {
        std::cout << "Stop button clicked" << std::endl;
        // Stop audio (to be implemented)
    }
}

void MainComponent::sliderValueChanged(Slider* slider)
{
    if (slider == &volumeSlider)
    {
        std::cout << "Volume changed to " << slider->getValue() << std::endl;
        // Adjust volume (to be implemented)
    }
    else if (slider == &speedSlider)
    {
        std::cout << "Speed changed to " << slider->getValue() << std::endl;
        // Adjust speed (to be implemented)
    }
}
```

### Setting Up Audio Playback

To implement audio playback, we need to:

1. Add audio-related components to the MainComponent
2. Set up the audio format manager and audio transport source
3. Implement methods to load and play audio files

#### MainComponent.h (Updated)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainComponent : public Component,
                      public Button::Listener,
                      public Slider::Listener,
                      public Timer
{
public:
    MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;
    void resized() override;

    // Button::Listener implementation
    void buttonClicked(Button* button) override;

    // Slider::Listener implementation
    void sliderValueChanged(Slider* slider) override;
    
    // Timer implementation
    void timerCallback() override;

private:
    // UI Components
    TextButton playButton{"PLAY"};
    TextButton stopButton{"STOP"};
    TextButton loadButton{"LOAD"};
    Slider volumeSlider;
    Slider speedSlider;
    Label volumeLabel{"", "Volume"};
    Label speedLabel{"", "Speed"};
    
    // Audio Components
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    ResamplingAudioSource resampleSource{&transportSource, false, 2};
    
    // Methods for audio handling
    void loadFile();
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    void releaseResources();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
```

#### MainComponent.cpp (Updated)

```cpp
#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Configure and add UI components
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);
    addAndMakeVisible(volumeSlider);
    addAndMakeVisible(speedSlider);
    addAndMakeVisible(volumeLabel);
    addAndMakeVisible(speedLabel);

    // Configure sliders
    volumeSlider.setRange(0.0, 1.0);
    volumeSlider.setValue(0.5);
    volumeSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    
    speedSlider.setRange(0.1, 3.0);
    speedSlider.setValue(1.0);
    speedSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);

    // Add listeners
    playButton.addListener(this);
    stopButton.addListener(this);
    loadButton.addListener(this);
    volumeSlider.addListener(this);
    speedSlider.addListener(this);

    // Set up audio format manager
    formatManager.registerBasicFormats();
    
    // Start the timer for audio visualization
    startTimer(40);

    // Set component size
    setSize(600, 400);
}

MainComponent::~MainComponent()
{
    // Clean up audio resources
    transportSource.setSource(nullptr);
    readerSource = nullptr;
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // Layout the components
    const int margin = 10;
    const int buttonHeight = 30;
    const int sliderHeight = 30;
    const int labelWidth = 80;
    
    // Position the buttons
    playButton.setBounds(margin, margin, 100, buttonHeight);
    stopButton.setBounds(margin + 110, margin, 100, buttonHeight);
    loadButton.setBounds(margin + 220, margin, 100, buttonHeight);
    
    // Position the volume slider and label
    volumeLabel.setBounds(margin, margin + buttonHeight + margin, labelWidth, sliderHeight);
    volumeSlider.setBounds(margin + labelWidth, margin + buttonHeight + margin, getWidth() - margin * 2 - labelWidth, sliderHeight);
    
    // Position the speed slider and label
    speedLabel.setBounds(margin, margin + buttonHeight + margin + sliderHeight + margin, labelWidth, sliderHeight);
    speedSlider.setBounds(margin + labelWidth, margin + buttonHeight + margin + sliderHeight + margin, getWidth() - margin * 2 - labelWidth, sliderHeight);
}

void MainComponent::buttonClicked(Button* button)
{
    if (button == &playButton)
    {
        transportSource.start();
    }
    else if (button == &stopButton)
    {
        transportSource.stop();
    }
    else if (button == &loadButton)
    {
        loadFile();
    }
}

void MainComponent::sliderValueChanged(Slider* slider)
{
    if (slider == &volumeSlider)
    {
        transportSource.setGain(slider->getValue());
    }
    else if (slider == &speedSlider)
    {
        resampleSource.setResamplingRatio(slider->getValue());
    }
}

void MainComponent::timerCallback()
{
    // Update audio visualization (to be implemented)
    repaint();
}

void MainComponent::loadFile()
{
    FileChooser chooser{"Select a file to play...", {}, "*.mp3;*.wav;*.aiff"};
    
    if (chooser.browseForFileToOpen())
    {
        auto file = chooser.getResult();
        auto* reader = formatManager.createReaderFor(file);
        
        if (reader != nullptr)
        {
            std::unique_ptr<AudioFormatReaderSource> newSource(new AudioFormatReaderSource(reader, true));
            transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
            readerSource.reset(newSource.release());
        }
    }
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    if (readerSource.get() == nullptr)
    {
        bufferToFill.clearActiveBufferRegion();
        return;
    }
    
    resampleSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    transportSource.releaseResources();
    resampleSource.releaseResources();
}
```

### Integrating with JUCE's Audio System

To integrate our audio playback with JUCE's audio system, we need to modify the MainComponent to inherit from AudioAppComponent:

#### MainComponent.h (Final)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainComponent : public AudioAppComponent,
                      public Button::Listener,
                      public Slider::Listener,
                      public Timer
{
public:
    MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;
    void resized() override;

    // Button::Listener implementation
    void buttonClicked(Button* button) override;

    // Slider::Listener implementation
    void sliderValueChanged(Slider* slider) override;
    
    // Timer implementation
    void timerCallback() override;
    
    // AudioAppComponent implementation
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

private:
    // UI Components
    TextButton playButton{"PLAY"};
    TextButton stopButton{"STOP"};
    TextButton loadButton{"LOAD"};
    Slider volumeSlider;
    Slider speedSlider;
    Label volumeLabel{"", "Volume"};
    Label speedLabel{"", "Speed"};
    
    // Audio Components
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    ResamplingAudioSource resampleSource{&transportSource, false, 2};
    
    // Methods for audio handling
    void loadFile();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
```

#### MainComponent.cpp (Final)

```cpp
#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Configure and add UI components
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);
    addAndMakeVisible(volumeSlider);
    addAndMakeVisible(speedSlider);
    addAndMakeVisible(volumeLabel);
    addAndMakeVisible(speedLabel);

    // Configure sliders
    volumeSlider.setRange(0.0, 1.0);
    volumeSlider.setValue(0.5);
    volumeSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    
    speedSlider.setRange(0.1, 3.0);
    speedSlider.setValue(1.0);
    speedSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);

    // Add listeners
    playButton.addListener(this);
    stopButton.addListener(this);
    loadButton.addListener(this);
    volumeSlider.addListener(this);
    speedSlider.addListener(this);

    // Set up audio format manager
    formatManager.registerBasicFormats();
    
    // Set up audio device manager
    setAudioChannels(0, 2);
    
    // Start the timer for audio visualization
    startTimer(40);

    // Set component size
    setSize(600, 400);
}

MainComponent::~MainComponent()
{
    // Clean up audio resources
    shutdownAudio();
    transportSource.setSource(nullptr);
    readerSource = nullptr;
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // Layout the components
    const int margin = 10;
    const int buttonHeight = 30;
    const int sliderHeight = 30;
    const int labelWidth = 80;
    
    // Position the buttons
    playButton.setBounds(margin, margin, 100, buttonHeight);
    stopButton.setBounds(margin + 110, margin, 100, buttonHeight);
    loadButton.setBounds(margin + 220, margin, 100, buttonHeight);
    
    // Position the volume slider and label
    volumeLabel.setBounds(margin, margin + buttonHeight + margin, labelWidth, sliderHeight);
    volumeSlider.setBounds(margin + labelWidth, margin + buttonHeight + margin, getWidth() - margin * 2 - labelWidth, sliderHeight);
    
    // Position the speed slider and label
    speedLabel.setBounds(margin, margin + buttonHeight + margin + sliderHeight + margin, labelWidth, sliderHeight);
    speedSlider.setBounds(margin + labelWidth, margin + buttonHeight + margin + sliderHeight + margin, getWidth() - margin * 2 - labelWidth, sliderHeight);
}

void MainComponent::buttonClicked(Button* button)
{
    if (button == &playButton)
    {
        transportSource.start();
    }
    else if (button == &stopButton)
    {
        transportSource.stop();
    }
    else if (button == &loadButton)
    {
        loadFile();
    }
}

void MainComponent::sliderValueChanged(Slider* slider)
{
    if (slider == &volumeSlider)
    {
        transportSource.setGain(slider->getValue());
    }
    else if (slider == &speedSlider)
    {
        resampleSource.setResamplingRatio(slider->getValue());
    }
}

void MainComponent::timerCallback()
{
    // Update audio visualization (to be implemented)
    repaint();
}

void MainComponent::loadFile()
{
    FileChooser chooser{"Select a file to play...", {}, "*.mp3;*.wav;*.aiff"};
    
    if (chooser.browseForFileToOpen())
    {
        auto file = chooser.getResult();
        auto* reader = formatManager.createReaderFor(file);
        
        if (reader != nullptr)
        {
            std::unique_ptr<AudioFormatReaderSource> newSource(new AudioFormatReaderSource(reader, true));
            transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
            readerSource.reset(newSource.release());
        }
    }
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    if (readerSource.get() == nullptr)
    {
        bufferToFill.clearActiveBufferRegion();
        return;
    }
    
    resampleSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    transportSource.releaseResources();
    resampleSource.releaseResources();
}
```

## JUCE Audio Architecture

JUCE provides a comprehensive audio architecture for handling audio playback and processing. The key components used in our implementation are:

### AudioFormatManager

The `AudioFormatManager` is responsible for managing audio formats and creating readers for audio files. It provides methods to register audio formats and create readers for audio files.

```cpp
formatManager.registerBasicFormats();
```

### AudioFormatReaderSource

The `AudioFormatReaderSource` is responsible for reading audio data from a file. It wraps an `AudioFormatReader` and provides methods to read audio data from the file.

```cpp
std::unique_ptr<AudioFormatReaderSource> newSource(new AudioFormatReaderSource(reader, true));
```

### AudioTransportSource

The `AudioTransportSource` is responsible for controlling audio playback. It provides methods to start, stop, and seek audio playback, as well as control the gain (volume).

```cpp
transportSource.start();
transportSource.stop();
transportSource.setGain(slider->getValue());
```

### ResamplingAudioSource

The `ResamplingAudioSource` is responsible for resampling audio data. It allows us to change the playback speed without changing the pitch.

```cpp
resampleSource.setResamplingRatio(slider->getValue());
```

### AudioAppComponent

The `AudioAppComponent` is a base class for components that need to handle audio. It provides methods to set up audio channels, prepare for playback, get audio blocks, and release resources.

```cpp
setAudioChannels(0, 2);
```

## OOP Concepts Demonstrated

Topic 7 introduces several important object-oriented programming concepts:

### Multiple Inheritance

The `MainComponent` class demonstrates multiple inheritance by inheriting from multiple base classes:

```cpp
class MainComponent : public AudioAppComponent,
                      public Button::Listener,
                      public Slider::Listener,
                      public Timer
```

This allows `MainComponent` to inherit functionality from all these base classes, such as audio handling from `AudioAppComponent`, button event handling from `Button::Listener`, slider event handling from `Slider::Listener`, and timer functionality from `Timer`.

### Polymorphism

The implementation demonstrates polymorphism through method overriding. For example, the `MainComponent` class overrides methods from its base classes:

```cpp
// Button::Listener implementation
void buttonClicked(Button* button) override;

// Slider::Listener implementation
void sliderValueChanged(Slider* slider) override;

// Timer implementation
void timerCallback() override;

// AudioAppComponent implementation
void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
void releaseResources() override;
```

### Composition

The implementation demonstrates composition by including various components as member variables:

```cpp
// UI Components
TextButton playButton{"PLAY"};
TextButton stopButton{"STOP"};
TextButton loadButton{"LOAD"};
Slider volumeSlider;
Slider speedSlider;
Label volumeLabel{"", "Volume"};
Label speedLabel{"", "Speed"};

// Audio Components
AudioFormatManager formatManager;
std::unique_ptr<AudioFormatReaderSource> readerSource;
AudioTransportSource transportSource;
ResamplingAudioSource resampleSource{&transportSource, false, 2};
```

### Smart Pointers

The implementation uses smart pointers (`std::unique_ptr`) for memory management:

```cpp
std::unique_ptr<AudioFormatReaderSource> readerSource;
```

This ensures that the `AudioFormatReaderSource` object is automatically deleted when the `MainComponent` object is deleted, preventing memory leaks.

### Event-Driven Programming

The implementation demonstrates event-driven programming through the use of event listeners:

```cpp
// Add listeners
playButton.addListener(this);
stopButton.addListener(this);
loadButton.addListener(this);
volumeSlider.addListener(this);
speedSlider.addListener(this);
```

The `MainComponent` class registers itself as a listener for button and slider events, and implements the corresponding event handler methods.

## Key Takeaways

1. **UI Controls**: JUCE provides a wide range of UI controls, such as buttons, sliders, and labels, that can be easily added to a component.

2. **Event Handling**: JUCE uses an event-driven programming model, where components generate events and listeners respond to them.

3. **Audio Playback**: JUCE provides a comprehensive audio architecture for handling audio playback and processing.

4. **Multiple Inheritance**: C++ allows a class to inherit from multiple base classes, which can be useful for combining functionality from different sources.

5. **Smart Pointers**: Smart pointers provide automatic memory management, preventing memory leaks and making code more robust.

## Next Steps

The next topic will build upon this foundation by implementing the DJAudioPlayer and DeckGUI classes to create a more modular and reusable DJ deck interface.

## Visual Elements

In the JUCE application, the main window would now have:

- Three buttons at the top: "PLAY", "STOP", and "LOAD"
- A volume slider with a label below the buttons
- A speed slider with a label below the volume slider

When the "LOAD" button is clicked, a file chooser dialog would appear, allowing the user to select an audio file. Once a file is loaded, the user can play it by clicking the "PLAY" button, stop it by clicking the "STOP" button, adjust the volume using the volume slider, and adjust the playback speed using the speed slider.
