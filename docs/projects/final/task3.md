---
layout: default
title: Task 3 - Music Library System
parent: Final Project
nav_order: 3
---

# Task 3: Music Library System

This task involves creating a comprehensive music library system that allows users to manage their tracks effectively. The system will handle track metadata, implement search functionality, and provide playlist management features.

## Understanding the Music Library Requirements

A professional music library system needs:
- Track metadata management
- Search and filtering capabilities
- Playlist organization
- File format support
- Persistent storage

## Step 1: Track Metadata Management

### Track Information Class

```cpp
class TrackInfo
{
public:
    TrackInfo(const File& file)
    {
        // Read basic file information
        filePath = file.getFullPathName();
        title = file.getFileNameWithoutExtension();
        fileSize = file.getSize();
        
        // Read audio metadata
        AudioFormatReader* reader = formatManager.createReaderFor(file);
        if (reader != nullptr)
        {
            sampleRate = reader->sampleRate;
            lengthInSeconds = reader->lengthInSamples / reader->sampleRate;
            numChannels = reader->numChannels;
            
            // Read ID3 tags if available
            if (auto* mp3Reader = dynamic_cast<MP3AudioFormat*>(reader))
            {
                artist = mp3Reader->metadataValues["artist"];
                album = mp3Reader->metadataValues["album"];
                genre = mp3Reader->metadataValues["genre"];
                year = mp3Reader->metadataValues["year"];
            }
            
            delete reader;
        }
    }
    
    String getFormattedLength() const
    {
        int minutes = lengthInSeconds / 60;
        int seconds = lengthInSeconds % 60;
        return String::formatted("%d:%02d", minutes, seconds);
    }
    
private:
    String filePath;
    String title;
    String artist;
    String album;
    String genre;
    String year;
    int64 fileSize;
    double sampleRate;
    double lengthInSeconds;
    int numChannels;
};
```

### Track Database

```cpp
class TrackDatabase
{
public:
    void addTrack(const TrackInfo& track)
    {
        tracks.add(track);
        updateIndex(tracks.size() - 1);
    }
    
    Array<TrackInfo> search(const String& query)
    {
        Array<TrackInfo> results;
        
        // Search through index
        for (auto& entry : searchIndex)
        {
            if (entry.text.containsIgnoreCase(query))
                results.add(tracks[entry.trackIndex]);
        }
        
        return results;
    }
    
private:
    struct IndexEntry
    {
        String text;
        int trackIndex;
    };
    
    void updateIndex(int trackIndex)
    {
        auto& track = tracks[trackIndex];
        
        // Index various metadata fields
        addToIndex(track.getTitle(), trackIndex);
        addToIndex(track.getArtist(), trackIndex);
        addToIndex(track.getAlbum(), trackIndex);
        addToIndex(track.getGenre(), trackIndex);
    }
    
    void addToIndex(const String& text, int trackIndex)
    {
        auto words = StringArray::fromTokens(text, true);
        for (auto& word : words)
        {
            searchIndex.add({word.toLowerCase(), trackIndex});
        }
    }
    
    Array<TrackInfo> tracks;
    Array<IndexEntry> searchIndex;
};
```

## Step 2: Enhanced Playlist Component

### Playlist Table Model

```cpp
class PlaylistComponent : public Component,
                         public TableListBoxModel
{
public:
    PlaylistComponent()
    {
        // Setup table columns
        tableComponent.getHeader().addColumn("Title", 1, 200);
        tableComponent.getHeader().addColumn("Artist", 2, 150);
        tableComponent.getHeader().addColumn("Album", 3, 150);
        tableComponent.getHeader().addColumn("Duration", 4, 100);
        tableComponent.getHeader().addColumn("BPM", 5, 80);
        tableComponent.setMultipleSelectionEnabled(true);
        
        addAndMakeVisible(tableComponent);
    }
    
    int getNumRows() override
    {
        return trackDatabase.getNumTracks();
    }
    
    void paintRowBackground(Graphics& g, int rowNumber,
                          int width, int height,
                          bool rowIsSelected) override
    {
        if (rowIsSelected)
            g.fillAll(Colours::blue.withAlpha(0.2f));
        else if (rowNumber % 2)
            g.fillAll(Colours::grey.withAlpha(0.05f));
    }
    
    void paintCell(Graphics& g, int rowNumber, int columnId,
                  int width, int height,
                  bool rowIsSelected) override
    {
        auto track = trackDatabase.getTrack(rowNumber);
        String text;
        
        switch (columnId)
        {
            case 1: text = track.getTitle(); break;
            case 2: text = track.getArtist(); break;
            case 3: text = track.getAlbum(); break;
            case 4: text = track.getFormattedLength(); break;
            case 5: text = String(track.getBPM(), 1); break;
        }
        
        g.drawText(text, 2, 0, width - 4, height, Justification::centredLeft);
    }
};
```

## Step 3: Implementing Search and Filter

### Search System

```cpp
class SearchBox : public Component,
                 public TextEditor::Listener
{
public:
    SearchBox()
    {
        searchInput.setTextToShowWhenEmpty("Search tracks...", 
                                         Colours::grey);
        searchInput.addListener(this);
        addAndMakeVisible(searchInput);
        
        addAndMakeVisible(filterTypeCombo);
        filterTypeCombo.addItem("All", 1);
        filterTypeCombo.addItem("Title", 2);
        filterTypeCombo.addItem("Artist", 3);
        filterTypeCombo.addItem("Album", 4);
        filterTypeCombo.addItem("Genre", 5);
    }
    
    void textEditorTextChanged(TextEditor&) override
    {
        if (onSearchChanged != nullptr)
            onSearchChanged(searchInput.getText(),
                          filterTypeCombo.getSelectedId());
    }
    
    std::function<void(const String&, int)> onSearchChanged;
    
private:
    TextEditor searchInput;
    ComboBox filterTypeCombo;
};
```

## Step 4: Implementing Persistence

### XML Storage System

```cpp
class LibraryPersistence
{
public:
    void saveLibrary(const TrackDatabase& database, const File& file)
    {
        XmlElement root("LIBRARY");
        
        for (auto& track : database.getTracks())
        {
            auto* trackXml = new XmlElement("TRACK");
            trackXml->setAttribute("path", track.getFilePath());
            trackXml->setAttribute("title", track.getTitle());
            trackXml->setAttribute("artist", track.getArtist());
            trackXml->setAttribute("album", track.getAlbum());
            trackXml->setAttribute("genre", track.getGenre());
            trackXml->setAttribute("year", track.getYear());
            trackXml->setAttribute("bpm", track.getBPM());
            
            root.addChildElement(trackXml);
        }
        
        root.writeToFile(file, "");
    }
    
    void loadLibrary(TrackDatabase& database, const File& file)
    {
        auto xml = XmlDocument::parse(file);
        if (xml != nullptr)
        {
            database.clear();
            
            forEachXmlChildElement(*xml, trackXml)
            {
                TrackInfo track(File(trackXml->getStringAttribute("path")));
                database.addTrack(track);
            }
        }
    }
};
```

## Implementation Tips

1. **Database Management**:
   - Use efficient data structures
   - Implement fast search algorithms
   - Cache commonly accessed data
   - Handle large libraries gracefully

2. **User Interface**:
   - Provide sorting options
   - Implement drag and drop
   - Show loading progress
   - Support keyboard navigation

3. **File Handling**:
   - Validate audio files
   - Handle missing files
   - Support multiple formats
   - Monitor file system changes

4. **Performance**:
   - Lazy load metadata
   - Use background processing
   - Implement virtual lists
   - Optimize memory usage

## Key Points

1. **Library Features**:
   - Comprehensive metadata
   - Fast search capability
   - Flexible organization
   - Persistent storage

2. **User Experience**:
   - Responsive interface
   - Clear organization
   - Easy navigation
   - Intuitive controls

3. **Data Management**:
   - Efficient storage
   - Fast retrieval
   - Data integrity
   - Error recovery

4. **Integration**:
   - Work with deck interface
   - Support drag and drop
   - Handle file operations
   - Maintain state

## Navigation

- [Back to Project Overview](index.html)
- [Previous: Task 2 - Advanced DJ Features](task2.html)
