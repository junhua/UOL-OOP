---
layout: default
title: Music Library System
parent: Final Project
nav_order: 3
---

# Music Library System

This part involves sample code in building a comprehensive music library system. Understanding data management, search algorithms, and user interface design is crucial for creating an effective library system.

## Understanding Music Library Architecture

### Data Management Principles

1. **Data Organization**
   - Hierarchical structure (artists → albums → tracks)
   - Metadata relationships
   - File system integration
   - Cache management

2. **Performance Considerations**
   - Memory vs. disk storage trade-offs
   - Index optimization
   - Lazy loading strategies
   - Background processing

3. **Data Persistence**
   - File formats (XML, JSON, SQLite)
   - Version control
   - Error recovery
   - Backup strategies

## Core Components

### 1. Track Information Management

The foundation of a music library is accurate track metadata. Here's a robust implementation:

```cpp
class TrackInfo
{
public:
    // Constructor with comprehensive metadata loading
    TrackInfo(const File& file)
    {
        loadBasicInfo(file);      // File system info
        loadAudioProperties(file); // Audio format details
        loadMetadata(file);       // ID3 tags, etc.
        analyzeBPM();             // Audio analysis
    }
    
private:
    // Load basic file information
    void loadBasicInfo(const File& file)
    {
        // Store file system information
        filePath = file.getFullPathName();
        fileName = file.getFileName();
        fileSize = file.getSize();
        lastModified = file.getLastModificationTime();
        
        // Extract relative path for portability
        relativePath = makeRelativePath(filePath);
    }
    
    // Load audio format properties
    void loadAudioProperties(const File& file)
    {
        // Create appropriate reader for file format
        std::unique_ptr<AudioFormatReader> reader(
            formatManager.createReaderFor(file));
            
        if (reader != nullptr)
        {
            // Store audio properties
            sampleRate = reader->sampleRate;
            numChannels = reader->numChannels;
            lengthInSeconds = reader->lengthInSamples / reader->sampleRate;
            bitDepth = reader->bitsPerSample;
            
            // Calculate approximate file bitrate
            bitrate = calculateBitrate(fileSize, lengthInSeconds);
        }
    }
    
    // Load metadata from tags
    void loadMetadata(const File& file)
    {
        // Handle different metadata formats
        if (auto* reader = dynamic_cast<MP3AudioFormat*>(
            formatManager.getFormat(file)))
        {
            // Extract ID3 metadata
            var metadata = reader->metadataValues;
            title = metadata["title"];
            artist = metadata["artist"];
            album = metadata["album"];
            genre = metadata["genre"];
            year = metadata["year"];
            
            // Extract additional DJ metadata if available
            bpm = metadata["bpm"];
            key = metadata["key"];
            energy = metadata["energy"];
        }
    }
    
    // Helper method for relative paths
    String makeRelativePath(const String& fullPath)
    {
        // Convert absolute path to relative for portability
        auto root = File::getSpecialLocation(
            File::userMusicDirectory);
        return root.getRelativePathFrom(File(fullPath));
    }
    
    // Member variables grouped by category
    // File system information
    String filePath;
    String fileName;
    String relativePath;
    int64 fileSize;
    Time lastModified;
    
    // Audio properties
    double sampleRate;
    int numChannels;
    double lengthInSeconds;
    int bitDepth;
    int bitrate;
    
    // Metadata
    String title;
    String artist;
    String album;
    String genre;
    String year;
    
    // DJ-specific data
    float bpm = 0.0f;
    int key = 0;
    float energy = 0.0f;
    Array<double> cuePoints;
    
    friend class Library;  // Allow Library class access
};
```

### 2. Search and Indexing System

An efficient search system is crucial for large libraries. Here's an optimized implementation:

```cpp
class SearchEngine
{
public:
    // Index a track's metadata for searching
    void indexTrack(const TrackInfo& track)
    {
        // Index different fields with appropriate weights
        addToIndex(track.title, "title", track.filePath, 1.0f);  // Highest priority
        addToIndex(track.artist, "artist", track.filePath, 0.8f);
        addToIndex(track.album, "album", track.filePath, 0.6f);
        addToIndex(track.genre, "genre", track.filePath, 0.4f);   // Lower priority
    }
    
    // Search with field-specific weighting
    Array<String> search(const String& query, 
                        const String& field = "all")
    {
        Array<String> results;
        StringArray tokens;
        tokens.addTokens(query.toLowerCase(), true);
        
        // Process each search token
        for (auto& token : tokens)
        {
            if (field == "all")
            {
                // Search all fields with weights
                for (auto& [indexField, entries] : searchIndex)
                {
                    auto matches = findMatches(token, entries);
                    // Apply field weights to results
                    applyWeights(matches, indexField);
                    results.addArray(matches);
                }
            }
            else
            {
                // Search specific field
                auto it = searchIndex.find(field);
                if (it != searchIndex.end())
                {
                    auto matches = findMatches(token, it->second);
                    results.addArray(matches);
                }
            }
        }
        
        // Remove duplicates and sort by relevance
        sortByRelevance(results);
        results.removeDuplicates(true);
        return results;
    }
    
private:
    // Add searchable terms to index
    void addToIndex(const String& text, 
                    const String& field, 
                    const String& filePath,
                    float weight)
    {
        if (text.isEmpty())
            return;
            
        // Tokenize and index each word
        StringArray tokens;
        tokens.addTokens(text.toLowerCase(), true);
        
        for (auto& token : tokens)
        {
            // Store token with weight for relevance scoring
            searchIndex[field].add({token, filePath, weight});
        }
    }
    
    // Find matching entries with scoring
    Array<String> findMatches(const String& token,
                             const Array<IndexEntry>& entries)
    {
        Array<String> matches;
        
        for (auto& entry : entries)
        {
            if (entry.token.contains(token))
            {
                // Score match based on various factors
                float score = calculateScore(token, entry);
                matchScores.set(entry.filePath, score);
                matches.add(entry.filePath);
            }
        }
        
        return matches;
    }
    
    // Calculate relevance score
    float calculateScore(const String& query, const IndexEntry& entry)
    {
        float score = entry.weight;  // Start with field weight
        
        // Exact match bonus
        if (entry.token == query)
            score *= 2.0f;
        
        // Prefix match bonus
        if (entry.token.startsWith(query))
            score *= 1.5f;
        
        return score;
    }
    
    struct IndexEntry
    {
        String token;
        String filePath;
        float weight;
    };
    
    std::map<String, Array<IndexEntry>> searchIndex;
    HashMap<String, float> matchScores;
};
```

### 3. Playlist Management

A flexible playlist system with support for different organization methods:

```cpp
class Playlist
{
public:
    // Add track with automatic metadata update
    void addTrack(const String& filePath)
    {
        // Add track and update metadata
        tracks.add(filePath);
        updateMetadata(filePath);
        
        // Sort if auto-sort is enabled
        if (autoSort)
            sortTracks();
            
        // Notify listeners of change
        listeners.call(&Listener::playlistChanged);
    }
    
    // Remove track with cleanup
    void removeTrack(int index)
    {
        if (isPositiveAndBelow(index, tracks.size()))
        {
            // Store track for undo
            lastRemovedTrack = tracks[index];
            lastRemovedIndex = index;
            
            tracks.remove(index);
            listeners.call(&Listener::playlistChanged);
        }
    }
    
    // Support drag-and-drop reordering
    void moveTrack(int currentIndex, int newIndex)
    {
        if (isPositiveAndBelow(currentIndex, tracks.size()) &&
            isPositiveAndBelow(newIndex, tracks.size()))
        {
            auto track = tracks[currentIndex];
            tracks.remove(currentIndex);
            tracks.insert(newIndex, track);
            listeners.call(&Listener::playlistChanged);
        }
    }
    
    // Undo last removal
    bool undoRemove()
    {
        if (lastRemovedTrack.isNotEmpty())
        {
            // Re-insert at original position
            tracks.insert(lastRemovedIndex, lastRemovedTrack);
            lastRemovedTrack.clear();
            listeners.call(&Listener::playlistChanged);
            return true;
        }
        return false;
    }
    
    // Save playlist to XML
    std::unique_ptr<XmlElement> toXml() const
    {
        auto xml = std::make_unique<XmlElement>("PLAYLIST");
        xml->setAttribute("name", name);
        xml->setAttribute("created", created.toISO8601(true));
        
        // Store tracks and metadata
        for (auto& track : tracks)
        {
            auto* trackXml = new XmlElement("TRACK");
            trackXml->setAttribute("path", track);
            
            // Store additional track info
            if (auto info = metadata[track])
            {
                trackXml->setAttribute("added", info->dateAdded.toISO8601(true));
                trackXml->setAttribute("playCount", info->playCount);
            }
            
            xml->addChildElement(trackXml);
        }
        
        return xml;
    }
    
private:
    String name;
    Array<String> tracks;
    bool autoSort = false;
    
    // Track metadata
    struct TrackInfo
    {
        Time dateAdded;
        int playCount = 0;
    };
    
    HashMap<String, TrackInfo> metadata;
    
    // Undo support
    String lastRemovedTrack;
    int lastRemovedIndex = -1;
    
    ListenerList<Listener> listeners;
};
```

## Implementation Tips

### 1. Asynchronous File Operations

Handle file operations in the background to keep the UI responsive:

```cpp
class LibraryScanner : public Thread
{
public:
    LibraryScanner() : Thread("LibraryScanner") 
    {
        // Initialize progress tracking
        progress = 0.0f;
        totalFiles = 0;
        processedFiles = 0;
    }
    
    void scanDirectory(const File& directory)
    {
        directoryToScan = directory;
        startThread();
    }
    
    void run() override
    {
        // First pass: count files
        Array<File> files;
        countFiles(directoryToScan);
        
        // Second pass: process files
        directoryToScan.findChildFiles(files, 
                                     File::findFiles, 
                                     true,  // Recursive
                                     "*.mp3;*.wav;*.aiff");  // Supported formats
                                     
        for (auto& file : files)
        {
            // Check for thread termination
            if (threadShouldExit())
                return;
                
            // Process file and update progress
            TrackInfo info(file);
            
            // Update progress atomically
            {
                const SpinLock::ScopedLockType lock(progressLock);
                processedFiles++;
                progress = float(processedFiles) / totalFiles;
            }
            
            // Notify on main thread
            MessageManager::callAsync([this, info]()
            {
                if (onTrackFound)
                    onTrackFound(info);
            });
        }
    }
    
    float getProgress() const
    {
        const SpinLock::ScopedLockType lock(progressLock);
        return progress;
    }
    
    std::function<void(const TrackInfo&)> onTrackFound;
    
private:
    void countFiles(const File& directory)
    {
        Array<File> files;
        directory.findChildFiles(files, 
                               File::findFiles, 
                               true, 
                               "*.mp3;*.wav;*.aiff");
        totalFiles = files.size();
    }
    
    File directoryToScan;
    SpinLock progressLock;
    float progress;
    int totalFiles;
    int processedFiles;
};
```

### 2. Performance Testing

Measure library performance with large datasets:

```cpp
class LibraryTests : public UnitTest
{
public:
    void runTest() override
    {
        beginTest("Search Performance");
        
        // Create large test library
        Library library;
        createTestLibrary(library, 10000);  // 10,000 tracks
        
        // Test search performance
        {
            Time start = Time::getCurrentTime();
            
            auto results = library.search("test");
            
            double duration = Time::getCurrentTime()
                             .toMilliseconds() - start.toMilliseconds();
                             
            // Should search 10,000 tracks in under 100ms
            expectLessThan(duration, 100.0);
        }
        
        // Test sorting performance
        {
            Time start = Time::getCurrentTime();
            
            library.sortTracks(Library::SortType::Artist);
            
            double duration = Time::getCurrentTime()
                             .toMilliseconds() - start.toMilliseconds();
                             
            // Should sort 10,000 tracks in under 500ms
            expectLessThan(duration, 500.0);
        }
    }
    
private:
    void createTestLibrary(Library& lib, int numTracks)
    {
        // Create test tracks with varied metadata
        Random random;
        
        for (int i = 0; i < numTracks; ++i)
        {
            TrackInfo track(File());
            track.title = "Test Track " + String(i);
            track.artist = "Artist " + String(random.nextInt(100));
            track.album = "Album " + String(random.nextInt(50));
            lib.addTrack(track);
        }
    }
};
```

## Design Considerations

### 1. Data Organization
- Choose appropriate data structures
- Plan indexing strategy
- Implement caching
- Handle file system changes

### 2. User Interface
- Provide sort options
- Support drag-and-drop
- Show loading progress
- Implement search filters

### 3. Error Handling
- Validate file operations
- Handle missing files
- Provide recovery options
- Log errors for debugging

## Key Points to Remember

1. **Performance**
   - Optimize search operations
   - Use background loading
   - Implement caching
   - Monitor memory usage

2. **User Experience**
   - Fast search response
   - Clear organization
   - Intuitive navigation
   - Visual feedback

3. **Data Management**
   - Reliable persistence
   - Efficient updates
   - Error recovery
   - Backup support

## Navigation

- [Back to Project Overview](index.html)
- [Previous: Digital Audio Processing](task2.html)
