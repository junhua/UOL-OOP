---
layout: default
title: "Topic 10: TableListBox and TableListBoxModel"
parent: Labs
nav_order: 10
---

# Topic 10: TableListBox and TableListBoxModel

## Overview

Topic 10 completes the OtoDecks application by implementing a playlist component to manage multiple audio files. This topic focuses on:

- Creating a PlaylistComponent using JUCE's TableListBox
- Implementing a custom TableListBoxModel to manage playlist data
- Adding functionality to add, remove, and load tracks
- Implementing drag and drop for adding tracks to the playlist
- Integrating the playlist with the deck components

## Implementation Details

### The PlaylistComponent Class

The PlaylistComponent class is responsible for displaying and managing the playlist of audio tracks.

#### Header File (PlaylistComponent.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "DeckGUI.h"
#include <vector>
#include <string>

class PlaylistComponent : public Component,
                          public TableListBoxModel,
                          public Button::Listener,
                          public FileDragAndDropTarget
{
public:
    PlaylistComponent(DeckGUI* _deckGUI1, 
                     DeckGUI* _deckGUI2,
                     DJAudioPlayer* _playerForParsingMetaData);
    ~PlaylistComponent();

    void paint(Graphics&) override;
    void resized() override;

    // TableListBoxModel overrides
    int getNumRows() override;
    void paintRowBackground(Graphics&, int rowNumber, int width, int height, bool rowIsSelected) override;
    void paintCell(Graphics&, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    Component* refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, Component* existingComponentToUpdate) override;
    
    // Button::Listener implementation
    void buttonClicked(Button* button) override;
    
    // FileDragAndDropTarget implementation
    bool isInterestedInFileDrag(const StringArray& files) override;
    void filesDropped(const StringArray& files, int x, int y) override;

private:
    TableListBox tableComponent;
    std::vector<std::string> trackTitles;
    std::vector<std::string> trackPaths;
    std::vector<double> trackLengths;
    
    TextButton addButton{"ADD TO PLAYLIST"};
    TextButton removeButton{"REMOVE FROM PLAYLIST"};
    TextButton loadToDeck1Button{"LOAD TO DECK 1"};
    TextButton loadToDeck2Button{"LOAD TO DECK 2"};
    
    DeckGUI* deckGUI1;
    DeckGUI* deckGUI2;
    DJAudioPlayer* playerForParsingMetaData;
    
    void loadTrack(const String& path, DeckGUI* deckGUI);
    void addToPlaylist(const String& path);
    void removeFromPlaylist();
    double getTrackLength(const String& path);
    String getTrackTitle(const String& path);
    String secondsToMinutesString(double seconds);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlaylistComponent)
};
```

#### Source File (PlaylistComponent.cpp)

```cpp
#include "PlaylistComponent.h"

PlaylistComponent::PlaylistComponent(DeckGUI* _deckGUI1, 
                                   DeckGUI* _deckGUI2,
                                   DJAudioPlayer* _playerForParsingMetaData)
    : deckGUI1(_deckGUI1),
      deckGUI2(_deckGUI2),
      playerForParsingMetaData(_playerForParsingMetaData)
{
    // Configure and add UI components
    addAndMakeVisible(tableComponent);
    addAndMakeVisible(addButton);
    addAndMakeVisible(removeButton);
    addAndMakeVisible(loadToDeck1Button);
    addAndMakeVisible(loadToDeck2Button);
    
    // Configure table
    tableComponent.setModel(this);
    tableComponent.getHeader().addColumn("Track Title", 1, 200);
    tableComponent.getHeader().addColumn("Length", 2, 100);
    tableComponent.getHeader().addColumn("Deck 1", 3, 100);
    tableComponent.getHeader().addColumn("Deck 2", 4, 100);
    tableComponent.setMultipleSelectionEnabled(false);
    
    // Add listeners
    addButton.addListener(this);
    removeButton.addListener(this);
    loadToDeck1Button.addListener(this);
    loadToDeck2Button.addListener(this);
}

PlaylistComponent::~PlaylistComponent()
{
}

void PlaylistComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
    
    g.setColour(Colours::grey);
    g.drawRect(getLocalBounds(), 1);
}

void PlaylistComponent::resized()
{
    // Layout the components
    auto area = getLocalBounds();
    
    // Position the buttons at the bottom
    auto buttonArea = area.removeFromBottom(30);
    addButton.setBounds(buttonArea.removeFromLeft(150));
    removeButton.setBounds(buttonArea.removeFromLeft(150));
    loadToDeck1Button.setBounds(buttonArea.removeFromLeft(150));
    loadToDeck2Button.setBounds(buttonArea.removeFromLeft(150));
    
    // Position the table
    tableComponent.setBounds(area);
}

int PlaylistComponent::getNumRows()
{
    return trackTitles.size();
}

void PlaylistComponent::paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected)
{
    if (rowIsSelected)
    {
        g.fillAll(Colours::orange);
    }
    else
    {
        g.fillAll(Colours::darkgrey);
    }
}

void PlaylistComponent::paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    if (rowNumber < getNumRows())
    {
        if (columnId == 1) // Track Title
        {
            g.drawText(trackTitles[rowNumber], 2, 0, width - 4, height, Justification::centredLeft, true);
        }
        else if (columnId == 2) // Length
        {
            g.drawText(secondsToMinutesString(trackLengths[rowNumber]), 2, 0, width - 4, height, Justification::centredLeft, true);
        }
    }
}

Component* PlaylistComponent::refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, Component* existingComponentToUpdate)
{
    if (columnId == 3 || columnId == 4) // Deck 1 or Deck 2 buttons
    {
        if (existingComponentToUpdate == nullptr)
        {
            TextButton* btn = new TextButton("Load");
            
            btn->setColour(TextButton::buttonColourId, Colours::green);
            btn->setColour(TextButton::textColourOffId, Colours::black);
            
            String id{std::to_string(rowNumber) + "," + std::to_string(columnId)};
            btn->setComponentID(id);
            
            btn->addListener(this);
            existingComponentToUpdate = btn;
        }
    }
    
    return existingComponentToUpdate;
}

void PlaylistComponent::buttonClicked(Button* button)
{
    if (button == &addButton)
    {
        FileChooser chooser{"Select files to add to playlist...", {}, "*.mp3;*.wav;*.aiff"};
        
        if (chooser.browseForMultipleFilesToOpen())
        {
            for (const File& file : chooser.getResults())
            {
                addToPlaylist(file.getFullPathName());
            }
        }
    }
    else if (button == &removeButton)
    {
        removeFromPlaylist();
    }
    else if (button == &loadToDeck1Button)
    {
        int selectedRow = tableComponent.getSelectedRow();
        if (selectedRow >= 0 && selectedRow < trackPaths.size())
        {
            loadTrack(trackPaths[selectedRow], deckGUI1);
        }
    }
    else if (button == &loadToDeck2Button)
    {
        int selectedRow = tableComponent.getSelectedRow();
        if (selectedRow >= 0 && selectedRow < trackPaths.size())
        {
            loadTrack(trackPaths[selectedRow], deckGUI2);
        }
    }
    else
    {
        // Handle cell buttons
        String id = button->getComponentID();
        auto tokens = StringArray::fromTokens(id, ",", "");
        
        if (tokens.size() == 2)
        {
            int rowNumber = tokens[0].getIntValue();
            int columnId = tokens[1].getIntValue();
            
            if (rowNumber >= 0 && rowNumber < trackPaths.size())
            {
                if (columnId == 3) // Deck 1
                {
                    loadTrack(trackPaths[rowNumber], deckGUI1);
                }
                else if (columnId == 4) // Deck 2
                {
                    loadTrack(trackPaths[rowNumber], deckGUI2);
                }
            }
        }
    }
}

bool PlaylistComponent::isInterestedInFileDrag(const StringArray& files)
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

void PlaylistComponent::filesDropped(const StringArray& files, int x, int y)
{
    // Add all dropped audio files to the playlist
    for (const auto& file : files)
    {
        if (file.endsWith(".mp3") || file.endsWith(".wav") || file.endsWith(".aiff"))
        {
            addToPlaylist(file);
        }
    }
}

void PlaylistComponent::loadTrack(const String& path, DeckGUI* deckGUI)
{
    URL fileURL = URL{File{path}};
    deckGUI->loadURL(fileURL);
}

void PlaylistComponent::addToPlaylist(const String& path)
{
    // Check if the track is already in the playlist
    for (const auto& trackPath : trackPaths)
    {
        if (trackPath == path)
        {
            return;
        }
    }
    
    // Add the track to the playlist
    trackTitles.push_back(getTrackTitle(path));
    trackPaths.push_back(path);
    trackLengths.push_back(getTrackLength(path));
    
    // Update the table
    tableComponent.updateContent();
}

void PlaylistComponent::removeFromPlaylist()
{
    int selectedRow = tableComponent.getSelectedRow();
    if (selectedRow >= 0 && selectedRow < trackPaths.size())
    {
        trackTitles.erase(trackTitles.begin() + selectedRow);
        trackPaths.erase(trackPaths.begin() + selectedRow);
        trackLengths.erase(trackLengths.begin() + selectedRow);
        
        // Update the table
        tableComponent.updateContent();
    }
}

double PlaylistComponent::getTrackLength(const String& path)
{
    // Load the track into the player to get its length
    URL fileURL = URL{File{path}};
    playerForParsingMetaData->loadURL(fileURL);
    
    // Return the length in seconds
    return playerForParsingMetaData->getLengthInSeconds();
}

String PlaylistComponent::getTrackTitle(const String& path)
{
    // Extract the file name from the path
    File file{path};
    return file.getFileNameWithoutExtension();
}

String PlaylistComponent::secondsToMinutesString(double seconds)
{
    // Convert seconds to minutes:seconds format
    int minutes = (int)seconds / 60;
    int remainingSeconds = (int)seconds % 60;
    
    return String(minutes) + ":" + (remainingSeconds < 10 ? "0" : "") + String(remainingSeconds);
}
```

### Updating DeckGUI

The DeckGUI class is updated to add a method for loading a URL:

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
    
    // Load a URL
    void loadURL(URL audioURL);

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
// Add the loadURL method to DeckGUI.cpp
void DeckGUI::loadURL(URL audioURL)
{
    player->loadURL(audioURL);
    waveformDisplay.loadURL(audioURL);
}
```

### Updating DJAudioPlayer

The DJAudioPlayer class is updated to add a method for getting the length of a track:

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
    double getLengthInSeconds();
    
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
// Add the getLengthInSeconds method to DJAudioPlayer.cpp
double DJAudioPlayer::getLengthInSeconds()
{
    return transportSource.getLengthInSeconds();
}
```

### Updating MainComponent

The MainComponent class is updated to include the PlaylistComponent:

#### Header File (MainComponent.h)

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "DeckGUI.h"
#include "PlaylistComponent.h"

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
    DJAudioPlayer playerForParsingMetaData{formatManager};
    
    // Mixer
    MixerAudioSource mixerSource;
    
    // GUI Components
    DeckGUI deck1{&player1, formatManager, thumbnailCache};
    DeckGUI deck2{&player2, formatManager, thumbnailCache};
    PlaylistComponent playlistComponent{&deck1, &deck2, &playerForParsingMetaData};

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
    addAndMakeVisible(playlistComponent);
    
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
    playerForParsingMetaData.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
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
    playerForParsingMetaData.releaseResources();
    
    // Release resources for mixer
    mixerSource.releaseResources();
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // Layout the components
    auto area = getLocalBounds();
    
    // Position the decks at the top
    auto decksArea = area.removeFromTop(300);
    deck1.setBounds(decksArea.removeFromLeft(getWidth() / 2));
    deck2.setBounds(decksArea);
    
    // Position the playlist at the bottom
    playlistComponent.setBounds(area);
}
```

## OOP Concepts Demonstrated

Topic 10 introduces several important object-oriented programming concepts:

### Model-View-Controller (MVC) Pattern

The implementation demonstrates the Model-View-Controller pattern:

- **Model**: The playlist data (trackTitles, trackPaths, trackLengths)
- **View**: The TableListBox component
- **Controller**: The PlaylistComponent class

This separation of concerns makes the code more maintainable and easier to understand.

### Interface Implementation

The PlaylistComponent class implements multiple interfaces:

```cpp
class PlaylistComponent : public Component,
                          public TableListBoxModel,
                          public Button::Listener,
                          public FileDragAndDropTarget
```

This allows the class to provide different functionality to different parts of the system.

### Dependency Injection

The implementation continues to demonstrate dependency injection by passing dependencies to objects through their constructors:

```cpp
PlaylistComponent::PlaylistComponent(DeckGUI* _deckGUI1, 
                                   DeckGUI* _deckGUI2,
                                   DJAudioPlayer* _playerForParsingMetaData)
```

This makes the code more testable and flexible.

### Factory Method Pattern

The `refreshComponentForCell` method demonstrates the Factory Method pattern:

```cpp
Component* PlaylistComponent::refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, Component* existingComponentToUpdate)
{
    if (columnId == 3 || columnId == 4) // Deck 1 or Deck 2 buttons
    {
        if (existingComponentToUpdate == nullptr)
        {
            TextButton* btn = new TextButton("Load");
            // ...
            existingComponentToUpdate = btn;
        }
    }
    
    return existingComponentToUpdate;
}
```

This method creates and configures components for the table cells.

### Command Pattern

The implementation demonstrates the Command pattern through the use of buttons and callbacks:

```cpp
void PlaylistComponent::buttonClicked(Button* button)
{
    if (button == &addButton)
    {
        // ...
    }
    else if (button == &removeButton)
    {
        // ...
    }
    // ...
}
```

Each button represents a command that can be executed.

## Key Takeaways

1. **Table-Based UI**: JUCE's TableListBox and TableListBoxModel provide a powerful way to display and interact with tabular data.

2. **Component Reuse**: The PlaylistComponent reuses the DeckGUI and DJAudioPlayer components, demonstrating the power of component-based architecture.

3. **User Experience**: The playlist component enhances the user experience by allowing users to manage multiple audio files.

4. **Interface Implementation**: Implementing multiple interfaces allows a class to provide different functionality to different parts of the system.

5. **Design Patterns**: The implementation demonstrates several design patterns, including MVC, Factory Method, and Command.

## Conclusion

The OtoDecks application is now complete, with a fully functional playlist component that allows users to manage multiple audio files. The application demonstrates a wide range of object-oriented programming concepts and design patterns, making it a valuable learning resource for C++ and OOP.

## Visual Elements

In the JUCE application, the main window would now have:

- Two decks at the top, each with a waveform display, buttons, and sliders
- A playlist component at the bottom, with a table displaying track titles and lengths
- Buttons for adding and removing tracks from the playlist
- Buttons for loading tracks to each deck

The user can add tracks to the playlist by clicking the "ADD TO PLAYLIST" button or by dragging and dropping audio files onto the playlist. They can select a track in the playlist and load it to either deck by clicking the corresponding "LOAD TO DECK" button or the "Load" button in the table. They can also remove tracks from the playlist by selecting them and clicking the "REMOVE FROM PLAYLIST" button.
