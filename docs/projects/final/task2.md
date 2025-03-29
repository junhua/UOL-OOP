---
layout: default
title: Digital Audio Processing
parent: Final Project
nav_order: 2
---

# Digital Audio Processing

This part involves sample code to implement professional audio processing features common in DJ software. Let's start by understanding digital audio processing concepts.

## Understanding Digital Audio Processing

Before implementing features, it's important to understand some fundamental concepts:

### Audio Signal Flow
In digital audio systems, audio flows through a chain of processors:
1. **Input Stage**: Reading from audio file or stream
   - Buffer management
   - Format conversion
   - Sample rate conversion if needed

2. **Pre-processing**: Preparing audio for effects
   - Normalization
   - Stereo width adjustment
   - Phase correction

3. **Effects Processing**: Audio manipulation
   - EQ and filters
   - Time-based effects (delay, reverb)
   - Dynamic effects (compression)

4. **Mixing Stage**: Combining signals
   - Volume control
   - Crossfading
   - Stereo panning

5. **Output Stage**: Final delivery
   - Limiting to prevent clipping
   - Dithering if needed
   - Buffer output

### Real-time Processing Constraints
DJ software must process audio in real-time with these considerations:

1. **Latency Management**:
   - Buffer size affects latency
   - Smaller buffers = lower latency but more CPU
   - Typical buffer sizes: 256-1024 samples
   - Target latency: <10ms for best response

2. **CPU Efficiency**:
   - Process must complete within buffer time
   - Example: at 44.1kHz, 512 samples = 11.6ms
   - Must process and deliver next buffer in time
   - Use efficient algorithms and optimization

3. **Thread Safety**:
   - Audio processing runs in high-priority thread
   - UI updates run in message thread
   - Need thread-safe parameter updates
   - Avoid locks in audio thread

## Audio Processing Features

### 1. Effect Chain System

The effect chain processes audio through multiple effects in sequence. Here's an efficient implementation:

```cpp
class EffectChain
{
public:
    // Initialize processors with audio settings
    // Called when sample rate or block size changes
    void prepare(const dsp::ProcessSpec& spec)
    {
        // Initialize each processor with audio specs
        // This ensures proper internal state setup
        eqLow.prepare(spec);   // Low shelf EQ
        eqMid.prepare(spec);   // Parametric mid EQ
        eqHigh.prepare(spec);  // High shelf EQ
        filter.prepare(spec);  // State variable filter
        delay.prepare(spec);   // Delay line
        reverb.prepare(spec);  // Reverb processor
    }
    
    // Process audio through the effect chain
    // Called for each block of audio samples
    void process(const dsp::ProcessContextReplacing<float>& context)
    {
        // Process through chain in optimal order:
        // 1. Frequency-based effects (EQ, filters)
        // 2. Time-based effects (delay, reverb)
        if (eqEnabled)
        {
            eqLow.process(context);   // Process low frequencies
            eqMid.process(context);   // Process mid frequencies
            eqHigh.process(context);  // Process high frequencies
        }
        
        if (filterEnabled)
            filter.process(context);   // Apply filter effect
            
        if (delayEnabled)
            delay.process(context);    // Add delay effect
            
        if (reverbEnabled)
            reverb.process(context);   // Add space/reverb
    }
    
    // Thread-safe parameter control methods
    void setEQLow(float gain) 
    { 
        // Convert from dB to linear gain
        eqLow.setGainDecibels(gain); 
    }
    
    void setFilterCutoff(float freq)
    {
        // Update filter frequency with smoothing
        auto& params = filter.state->getParameters();
        params.setCutOffFrequency(freq);
    }
    
private:
    // Audio processors using JUCE's DSP module
    dsp::IIR::Filter<float> eqLow;    // Low shelf EQ
    dsp::IIR::Filter<float> eqMid;    // Parametric EQ
    dsp::IIR::Filter<float> eqHigh;   // High shelf EQ
    dsp::IIR::Filter<float> filter;   // State variable filter
    dsp::DelayLine<float> delay;      // Delay effect
    dsp::Reverb reverb;               // Reverb effect
    
    // Effect enable flags
    bool eqEnabled = true;
    bool filterEnabled = false;
    bool delayEnabled = false;
    bool reverbEnabled = false;
};
```

### 2. Beat Detection System

Beat detection is crucial for tempo-sync features. Here's how to implement energy-based detection:

```cpp
class BeatDetector
{
public:
    // Analyze audio block for beats using energy detection
    void analyzeAudioBlock(const AudioBuffer<float>& buffer)
    {
        const float* samples = buffer.getReadPointer(0);
        int numSamples = buffer.getNumSamples();
        
        // Calculate RMS energy of current block
        float energy = 0.0f;
        for (int i = 0; i < numSamples; ++i)
            energy += samples[i] * samples[i];
        energy = std::sqrt(energy / numSamples);
        
        // Use adaptive threshold for beat detection
        // This adjusts to varying audio levels
        if (energy > energyThreshold && !inPeak)
        {
            // Beat detected - calculate timing
            beatDetected(buffer.getNumSamples());
            inPeak = true;
        }
        else if (energy < energyThreshold * 0.5f)
        {
            // Reset peak detection when energy drops
            inPeak = false;
        }
        
        // Smoothly adapt threshold to current levels
        // 0.9 and 0.1 factors provide good balance
        energyThreshold = 0.9f * energyThreshold + 0.1f * energy;
    }
    
    // Calculate current tempo from beat timings
    float getBPM() const
    {
        if (beatIntervals.size() < 2)
            return 0.0f;
            
        // Calculate average interval between beats
        float avgInterval = 0.0f;
        for (auto interval : beatIntervals)
            avgInterval += interval;
        avgInterval /= beatIntervals.size();
        
        // Convert to BPM using formula:
        // BPM = (60 seconds * sample rate) / samples between beats
        return 60.0f * sampleRate / avgInterval;
    }
    
private:
    void beatDetected(int numSamples)
    {
        auto time = totalSamples;
        if (lastBeatTime >= 0)
        {
            // Calculate interval and store for BPM calculation
            auto interval = time - lastBeatTime;
            beatIntervals.push_back(interval);
            
            // Keep a moving window of intervals
            // This allows for tempo changes
            if (beatIntervals.size() > 8)
                beatIntervals.erase(beatIntervals.begin());
        }
        lastBeatTime = time;
        totalSamples += numSamples;
    }
    
    float energyThreshold = 0.0f;
    bool inPeak = false;
    double sampleRate = 44100.0;
    int64 lastBeatTime = -1;
    int64 totalSamples = 0;
    std::vector<int64> beatIntervals;
};
```

### 3. Loop System

A flexible loop system is essential for creative mixing. Here's an implementation:

```cpp
class LoopSystem
{
public:
    // Set loop points with validation
    void setLoopPoints(double startTime, double endTime)
    {
        if (startTime >= 0.0 && endTime > startTime)
        {
            loopStart = startTime;
            loopEnd = endTime;
            loopLength = endTime - startTime;
            enabled = true;
        }
    }
    
    // Calculate next playback position with loop handling
    double getNextPlayPosition(double currentTime)
    {
        if (!enabled)
            return currentTime;
            
        if (currentTime >= loopEnd)
        {
            // Handle loop point crossing
            // Maintain phase accuracy with overshoot calculation
            double overshoot = currentTime - loopEnd;
            return loopStart + overshoot;
        }
        
        return currentTime;
    }
    
    // Set beat quantization for loop points
    void setQuantization(int beats)
    {
        quantizeBeats = beats;
    }
    
    bool isEnabled() const { return enabled; }
    void setEnabled(bool shouldBeEnabled) { enabled = shouldBeEnabled; }
    
private:
    double loopStart = 0.0;    // Loop start time in seconds
    double loopEnd = 0.0;      // Loop end time in seconds
    double loopLength = 0.0;   // Cached loop length
    bool enabled = false;      // Loop enable state
    int quantizeBeats = 4;     // Quantization grid
};
```

## Implementation Tips

### 1. Audio Thread Safety

Audio processing must be thread-safe:

```cpp
class ThreadSafeProcessor
{
public:
    // Audio thread method
    void process(const AudioBuffer<float>& buffer)
    {
        // Use RAII lock for thread safety
        const ScopedLock sl(lock);
        // Process audio using current parameters
    }
    
    // UI thread method
    void updateParameters(const Parameters& newParams)
    {
        // Protect parameter updates
        const ScopedLock sl(lock);
        parameters = newParams;
    }
    
private:
    CriticalSection lock;      // Thread synchronization
    Parameters parameters;      // Shared state
};
```

### 2. Performance Testing

Test processing overhead to ensure real-time performance:

```cpp
class PerformanceTest : public UnitTest
{
public:
    void runTest() override
    {
        beginTest("Effect Chain Performance");
        
        // Setup test conditions
        EffectChain chain;
        AudioBuffer<float> buffer(2, 512);  // Stereo, 512 samples
        
        Time start = Time::getMillisecondCounterHiRes();
        
        // Process equivalent of 1 second of audio
        // At 44.1kHz, 512 samples = ~11.6ms
        // So need about 86 blocks for 1 second
        for (int i = 0; i < 100; ++i)  // Extra headroom
        {
            dsp::AudioBlock<float> block(buffer);
            dsp::ProcessContextReplacing<float> context(block);
            chain.process(context);
        }
        
        double duration = Time::getMillisecondCounterHiRes() - start;
        // Should process well under real-time requirement
        expectLessThan(duration, 10.0);
    }
};
```

## Design Considerations

### 1. Effect Chain Architecture
- Plan effect ordering for optimal sound
- Consider CPU impact of each effect
- Allow flexible routing options
- Implement smooth bypass switching

### 2. Beat Detection
- Choose appropriate analysis window size
- Handle varying tempos and genres
- Consider using multiple detection methods
- Implement confidence metrics

### 3. Loop Implementation
- Ensure sample-accurate transitions
- Handle tempo changes gracefully
- Support beat-synced loop lengths
- Enable seamless loop nesting

## Key Points to Remember

1. **Audio Quality**
   - Maintain clean signal path
   - Prevent digital clipping
   - Use appropriate bit depth
   - Apply proper dithering

2. **Performance**
   - Profile critical paths
   - Optimize inner loops
   - Use SIMD where possible
   - Monitor CPU usage

3. **User Experience**
   - Provide immediate feedback
   - Use clear visual indicators
   - Handle errors gracefully
   - Support common workflows

## Navigation

- [Back to Project Overview](index.html)
- [Previous: Custom Deck Control Interface](task1.html)
- [Next: Music Library System](task3.html)
