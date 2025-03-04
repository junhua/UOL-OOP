---
layout: default
title: Task 2 - Advanced DJ Features
parent: Final Project
nav_order: 2
---

# Task 2: Advanced DJ Features

This task involves implementing advanced DJ features inspired by professional DJ software. You'll enhance the basic audio playback functionality with features that allow for creative mixing and performance.

## Understanding Professional DJ Features

Common features in professional DJ software include:
- Beat matching and sync
- Effects processing
- Loop controls
- Hot cues
- EQ and filters
- Beat grid visualization
- Advanced waveform display

## Step 1: Implementing Audio Effects

### Adding Effect Processing Capability

```cpp
class DJAudioPlayer
{
private:
    // Effect processors
    dsp::ProcessorChain<dsp::IIR::Filter<float>,      // Low/High-pass filter
                        dsp::Gain<float>,              // Volume
                        dsp::Reverb<float>> processor; // Reverb effect
    
public:
    void processBlock(AudioBuffer<float>& buffer)
    {
        // Wrap buffer in AudioBlock
        dsp::AudioBlock<float> block(buffer);
        dsp::ProcessContextReplacing<float> context(block);
        
        // Process audio through effect chain
        processor.process(context);
    }
    
    void setFilterCutoff(float frequency)
    {
        auto& filter = processor.get<0>();
        filter.coefficients = dsp::IIR::Coefficients<float>::makeLowPass(
            sampleRate, frequency);
    }
    
    void setReverbSettings(float roomSize, float damping)
    {
        auto& reverb = processor.get<2>();
        reverb.params.roomSize = roomSize;
        reverb.params.damping = damping;
    }
};
```

### Creating an Effects Section in DeckGUI

```cpp
class DeckGUI
{
private:
    // Effect controls
    Slider filterCutoffSlider;
    Slider reverbRoomSizeSlider;
    Slider reverbDampingSlider;
    
    void createEffectControls()
    {
        // Filter cutoff control
        filterCutoffSlider.setRange(20.0, 20000.0, 1.0);
        filterCutoffSlider.setSkewFactorFromMidPoint(1000.0);
        filterCutoffSlider.onValueChange = [this] {
            player->setFilterCutoff(filterCutoffSlider.getValue());
        };
        
        // Reverb controls
        reverbRoomSizeSlider.setRange(0.0, 1.0);
        reverbRoomSizeSlider.onValueChange = [this] {
            player->setReverbSettings(reverbRoomSizeSlider.getValue(),
                                    reverbDampingSlider.getValue());
        };
    }
};
```

## Step 2: Implementing Beat Detection

### Beat Analysis System

```cpp
class BeatDetector
{
public:
    void analyzeBuffer(const AudioBuffer<float>& buffer)
    {
        // Convert to mono if stereo
        float* monoData = new float[buffer.getNumSamples()];
        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            float sum = 0.0f;
            for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
                sum += buffer.getReadPointer(ch)[i];
            monoData[i] = sum / buffer.getNumChannels();
        }
        
        // Detect energy peaks
        for (int i = 1; i < buffer.getNumSamples() - 1; ++i)
        {
            if (monoData[i] > monoData[i-1] && 
                monoData[i] > monoData[i+1] &&
                monoData[i] > threshold)
            {
                beatPositions.add(i);
            }
        }
        
        delete[] monoData;
    }
    
    // Calculate BPM from beat positions
    float calculateBPM()
    {
        if (beatPositions.size() < 2)
            return 0.0f;
            
        // Calculate average time between beats
        float avgTimeBetweenBeats = 0.0f;
        for (int i = 1; i < beatPositions.size(); ++i)
        {
            avgTimeBetweenBeats += beatPositions[i] - beatPositions[i-1];
        }
        avgTimeBetweenBeats /= (beatPositions.size() - 1);
        
        // Convert to BPM
        return 60.0f * sampleRate / avgTimeBetweenBeats;
    }

private:
    Array<int> beatPositions;
    float threshold = 0.1f;
    double sampleRate = 44100.0;
};
```

## Step 3: Implementing Loop Controls

### Loop System

```cpp
class LoopSystem
{
public:
    void setLoopPoints(double startTime, double endTime)
    {
        loopStart = startTime;
        loopEnd = endTime;
        loopEnabled = true;
    }
    
    double getNextPlayPosition(double currentTime)
    {
        if (!loopEnabled)
            return currentTime;
            
        if (currentTime >= loopEnd)
            return loopStart + (currentTime - loopEnd);
            
        return currentTime;
    }
    
    void enableLoop(bool shouldEnable)
    {
        loopEnabled = shouldEnable;
    }
    
private:
    double loopStart = 0.0;
    double loopEnd = 0.0;
    bool loopEnabled = false;
};
```

### Integration with DJAudioPlayer

```cpp
class DJAudioPlayer
{
private:
    LoopSystem loopSystem;
    
public:
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override
    {
        if (readerSource.get() == nullptr)
        {
            bufferToFill.clearActiveBufferRegion();
            return;
        }
        
        double currentTime = transportSource.getCurrentPosition();
        double nextPosition = loopSystem.getNextPlayPosition(currentTime);
        
        if (nextPosition != currentTime)
            transportSource.setPosition(nextPosition);
            
        transportSource.getNextAudioBlock(bufferToFill);
    }
};
```

## Step 4: Implementing Beat Sync

### Tempo Matching System

```cpp
class TempoMatcher
{
public:
    void matchTempo(DJAudioPlayer* playerToSync, DJAudioPlayer* targetPlayer)
    {
        // Get BPM of both tracks
        float sourceBPM = playerToSync->getBPM();
        float targetBPM = targetPlayer->getBPM();
        
        if (sourceBPM == 0.0f || targetBPM == 0.0f)
            return;
            
        // Calculate required speed change
        float speedRatio = targetBPM / sourceBPM;
        
        // Apply speed change
        playerToSync->setSpeed(speedRatio);
    }
    
    void alignPhase(DJAudioPlayer* playerToSync, DJAudioPlayer* targetPlayer)
    {
        // Get nearest beat positions
        double sourcePos = playerToSync->getNextBeatPosition();
        double targetPos = targetPlayer->getNextBeatPosition();
        
        // Calculate phase difference
        double phaseDiff = targetPos - sourcePos;
        
        // Adjust position to align beats
        playerToSync->setPosition(playerToSync->getPosition() + phaseDiff);
    }
};
```

## Step 5: Implementing Advanced Waveform Display

### Enhanced WaveformDisplay

```cpp
class EnhancedWaveformDisplay : public WaveformDisplay
{
public:
    void paintFrequencyBands(Graphics& g)
    {
        auto bounds = getLocalBounds().toFloat();
        auto numBands = 3; // Low, Mid, High
        auto bandHeight = bounds.getHeight() / numBands;
        
        // Draw frequency bands with different colors
        for (int i = 0; i < audioThumb.getNumChannels(); ++i)
        {
            // Low frequencies
            g.setColour(Colours::red.withAlpha(0.6f));
            drawBand(g, bounds.removeFromTop(bandHeight), 0, 200);
            
            // Mid frequencies
            g.setColour(Colours::green.withAlpha(0.6f));
            drawBand(g, bounds.removeFromTop(bandHeight), 200, 2000);
            
            // High frequencies
            g.setColour(Colours::blue.withAlpha(0.6f));
            drawBand(g, bounds, 2000, 20000);
        }
    }
    
    void drawBeatMarkers(Graphics& g)
    {
        auto bounds = getLocalBounds().toFloat();
        g.setColour(Colours::white);
        
        for (auto& beatPos : beatPositions)
        {
            float x = beatPos * bounds.getWidth();
            g.drawLine(x, 0, x, bounds.getHeight(), 1.0f);
        }
    }
};
```

## Implementation Tips

1. **Audio Processing**:
   - Use JUCE's DSP module for effects
   - Process audio in small blocks
   - Minimize latency
   - Handle buffer underruns

2. **Beat Detection**:
   - Use energy-based detection
   - Implement phase vocoder for accuracy
   - Cache results for performance
   - Handle different tempos

3. **User Interface**:
   - Show real-time feedback
   - Implement smooth animations
   - Use clear visualizations
   - Provide accurate timing display

4. **Performance**:
   - Optimize audio processing
   - Cache computed values
   - Use efficient algorithms
   - Profile critical sections

## Key Points

1. **Audio Quality**:
   - Clean signal processing
   - Minimal artifacts
   - Smooth transitions
   - Proper gain staging

2. **Feature Integration**:
   - Coherent workflow
   - Consistent behavior
   - Reliable performance
   - Intuitive controls

3. **Professional Features**:
   - Industry-standard tools
   - Creative possibilities
   - Performance options
   - Quality output

4. **Code Structure**:
   - Modular design
   - Clean interfaces
   - Error handling
   - Documentation

## Navigation

- [Back to Project Overview](index.html)
- [Previous: Task 1 - Custom Deck Control Interface](task1.html)
- [Next: Task 3 - Music Library System](task3.html)
