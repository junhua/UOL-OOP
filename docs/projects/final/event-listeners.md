---
layout: default
title: Additional Event Listeners
parent: Final Project
nav_order: 5
---

# Additional Event Listeners for OtoDecks

Here are several useful event listener examples that can enhance your DJ application:

## 1. Track Position Listener
Monitors playback position for waveform updates and time display:

```cpp
class PositionListener
{
public:
    virtual ~PositionListener() {}
    virtual void positionChanged(double newPosition) = 0;
};

class DeckGUI : public Component,
                public PositionListener
{
public:
    void positionChanged(double newPosition) override
    {
        // Update waveform display position
        waveformDisplay.setPlayPosition(newPosition);
        
        // Update time display
        updateTimeDisplay(newPosition);
        
        // Check for loop points
        checkLoopPoints(newPosition);
    }
};
```

## 2. Audio Level Listener
Monitors audio levels for VU meters and peak detection:

```cpp
class LevelListener
{
public:
    virtual ~LevelListener() {}
    virtual void levelChanged(float leftLevel, float rightLevel) = 0;
    virtual void peakDetected(int channel) = 0;
};

class VUMeter : public Component,
                public LevelListener
{
public:
    void levelChanged(float leftLevel, float rightLevel) override
    {
        // Update VU meter display
        leftChannel = leftLevel;
        rightChannel = rightLevel;
        repaint();
    }
    
    void peakDetected(int channel) override
    {
        // Flash peak indicator
        if (channel == 0)
            leftPeakFlash = true;
        else
            rightPeakFlash = true;
            
        startTimer(500); // Reset flash after 500ms
    }
};
```

## 3. Track Load Listener
Handles track loading events and metadata updates:

```cpp
class TrackLoadListener
{
public:
    virtual ~TrackLoadListener() {}
    virtual void trackLoaded(const File& file, const TrackInfo& info) = 0;
    virtual void loadFailed(const File& file, const String& error) = 0;
};

class DeckGUI : public Component,
                public TrackLoadListener
{
public:
    void trackLoaded(const File& file, const TrackInfo& info) override
    {
        // Update track information display
        titleLabel.setText(info.title, dontSendNotification);
        artistLabel.setText(info.artist, dontSendNotification);
        
        // Set BPM if available
        if (info.bpm > 0)
            bpmLabel.setText(String(info.bpm), dontSendNotification);
            
        // Update waveform display
        waveformDisplay.loadAudioData(file);
    }
    
    void loadFailed(const File& file, const String& error) override
    {
        // Show error message
        AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
                                       "Load Error",
                                       "Failed to load " + file.getFileName() + 
                                       "\n" + error);
    }
};
```

## 4. Beat Detection Listener
Receives notifications of detected beats for synchronization:

```cpp
class BeatListener
{
public:
    virtual ~BeatListener() {}
    virtual void beatDetected(double position, float confidence) = 0;
    virtual void bpmChanged(float newBPM) = 0;
};

class BeatDisplay : public Component,
                   public BeatListener
{
public:
    void beatDetected(double position, float confidence) override
    {
        // Flash beat indicator
        if (confidence > 0.5f)
        {
            beatFlash = true;
            startTimer(100); // Reset flash after 100ms
        }
        
        // Add beat marker to waveform
        addBeatMarker(position);
        repaint();
    }
    
    void bpmChanged(float newBPM) override
    {
        // Update BPM display
        bpmValue = newBPM;
        bpmLabel.setText(String(newBPM, 1), dontSendNotification);
        
        // Update beat grid spacing
        updateBeatGrid();
    }
};
```

## 5. Playlist Change Listener
Monitors changes to playlists for UI updates:

```cpp
class PlaylistListener
{
public:
    virtual ~PlaylistListener() {}
    virtual void playlistChanged() = 0;
    virtual void currentTrackChanged(int index) = 0;
};

class PlaylistComponent : public Component,
                         public PlaylistListener
{
public:
    void playlistChanged() override
    {
        // Update track list display
        trackList.updateContent();
        
        // Update playlist statistics
        updateStatistics();
        
        // Save playlist state
        savePlaylistState();
    }
    
    void currentTrackChanged(int index) override
    {
        // Highlight current track
        trackList.selectRow(index);
        
        // Ensure track is visible
        trackList.scrollToEnsureRowIsOnscreen(index);
        
        // Update transport controls state
        updateTransportControls();
    }
};
```

## Implementation Tips

1. **Listener Management**
   - Use JUCE's `ListenerList` for efficient listener handling
   - Remove listeners when components are destroyed
   - Consider weak references for long-lived listeners

2. **Thread Safety**
   - Ensure listeners are called on appropriate thread
   - Use `MessageManager` for UI updates from audio thread
   - Protect shared data with appropriate locks

3. **Performance**
   - Minimize work in listener callbacks
   - Consider batching frequent updates
   - Profile listener overhead in critical paths

4. **Error Handling**
   - Protect against listener exceptions
   - Provide meaningful error states
   - Handle listener removal gracefully

## Example Usage

Here's how to integrate multiple listeners:

```cpp
class DeckGUI : public Component,
                public PositionListener,
                public LevelListener,
                public TrackLoadListener,
                public BeatListener
{
public:
    DeckGUI()
    {
        // Register with various sources
        player.addPositionListener(this);
        player.addLevelListener(this);
        player.addTrackLoadListener(this);
        beatDetector.addListener(this);
    }
    
    ~DeckGUI()
    {
        // Clean up listeners
        player.removePositionListener(this);
        player.removeLevelListener(this);
        player.removeTrackLoadListener(this);
        beatDetector.removeListener(this);
    }
    
    // Implement listener methods...
};
```

These additional event listeners will help create a more responsive and feature-rich DJ application by providing proper handling of various events and state changes.

## Navigation

- [Back to Project Overview](index.html)
- [Back to Custom Deck Control Interface](task1.html)
- [Next: Advanced DJ Features](task2.html)
