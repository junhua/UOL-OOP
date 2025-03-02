# Media Library Practice Exercise

This practice exercise will help you apply getter and setter patterns by implementing a comprehensive media library system.

## Files Overview

- `MediaLibrary_starter.h` - Class declaration file
- `MediaLibrary_starter.cpp` - Implementation file
- `media_library_test.cpp` - Test program demonstrating functionality

## Learning Objectives

- Implement property validation for media content
- Create computed properties for media statistics
- Design state management for playback history
- Develop lazy loading for media content
- Implement search and filtering functionality
- Apply thread safety for concurrent access

## Requirements

### 1. Media Content Management

Implement the `MediaItem` class with:
- Private data members for media details
- Validation for metadata
- Rating system
- Playback tracking

```cpp
class MediaItem {
private:
    std::string id;
    std::string title;
    std::string artist;
    int duration;  // in seconds
    std::string genre;
    std::string filePath;
    double rating;  // 0.0 to 5.0
    int playCount;
    std::chrono::system_clock::time_point lastPlayed;
    mutable std::string lastError;
    
    // TODO: Add validation methods
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement getters and setters with validation
    
    // TODO: Implement playback tracking
    
    // TODO: Implement rating system
};
```

### 2. Media Library System

Implement the `MediaLibrary` class with:
- Media collection management
- User preferences
- Playback history
- Search functionality

```cpp
class MediaLibrary {
private:
    std::vector<MediaItem> items;
    std::map<std::string, std::vector<std::string>> playlists;
    std::vector<std::string> playbackHistory;
    double volume;
    double playbackSpeed;
    bool shuffle;
    bool repeat;
    mutable std::mutex mutex;
    mutable std::string lastError;
    
    // TODO: Add helper methods for validation and management
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement media management methods
    
    // TODO: Implement playlist methods
    
    // TODO: Implement playback methods
    
    // TODO: Implement search methods
    
    // TODO: Implement preference methods
};
```

### 3. User Preferences

Implement user preference management with:
- Volume control
- Playback speed
- Shuffle mode
- Repeat mode
- Theme settings

## Implementation Steps

### Step 1: MediaItem Class

1. Implement the `MediaItem` class:
   - Add private member variables
   - Create validation methods
   - Implement getters and setters
   - Add playback tracking
   - Implement rating system

2. Key methods to implement:
   ```cpp
   bool setTitle(const std::string& title);
   bool setArtist(const std::string& artist);
   bool setDuration(int seconds);
   bool setRating(double rating);
   void incrementPlayCount();
   std::string getFormattedDuration() const;
   bool isRecentlyPlayed(int days = 7) const;
   std::string getLastError() const;
   ```

### Step 2: MediaLibrary Class

1. Implement the `MediaLibrary` class:
   - Add media collection management
   - Create playlist functionality
   - Implement playback history
   - Add search and filtering
   - Implement user preferences

2. Key methods to implement:
   ```cpp
   bool addItem(const MediaItem& item);
   bool removeItem(const std::string& id);
   std::vector<MediaItem> search(const std::string& query) const;
   std::vector<MediaItem> filterByGenre(const std::string& genre) const;
   bool createPlaylist(const std::string& name);
   bool addToPlaylist(const std::string& playlistName, const std::string& itemId);
   bool setVolume(double volume);
   bool setPlaybackSpeed(double speed);
   void toggleShuffle();
   void toggleRepeat();
   ```

### Step 3: Thread Safety

1. Implement thread-safe access:
   - Add mutex protection for shared resources
   - Create thread-safe getters and setters
   - Implement atomic operations
   - Ensure consistent locking

2. Key methods to implement:
   ```cpp
   const MediaItem& getItem(const std::string& id) const;
   std::vector<std::string> getPlaybackHistory() const;
   double getVolume() const;
   double getPlaybackSpeed() const;
   bool isShuffle() const;
   bool isRepeat() const;
   ```

### Step 4: Complete the Test Program

1. In `media_library_test.cpp`:
   - Create a media library
   - Add various media items
   - Create and manage playlists
   - Simulate playback
   - Test search functionality
   - Modify user preferences
   - Display library statistics

## Testing

1. Compile your program:
   ```bash
   g++ -o media_library media_library_test.cpp MediaLibrary_starter.cpp -std=c++17 -pthread
   ```

2. Run the program:
   ```bash
   ./media_library
   ```

3. Verify the output:
   - Check media item management
   - Verify playlist functionality
   - Test search and filtering
   - Confirm playback tracking
   - Validate user preferences
   - Check thread safety

## Expected Output

```
Media Library System
==================================================

Adding media items...
Added: "Bohemian Rhapsody" by Queen
Added: "Stairway to Heaven" by Led Zeppelin
Added: "Hotel California" by Eagles
Added: "Imagine" by John Lennon

Creating playlists...
Created playlist: "Rock Classics"
Added "Bohemian Rhapsody" to "Rock Classics"
Added "Stairway to Heaven" to "Rock Classics"
Added "Hotel California" to "Rock Classics"

Simulating playback...
Now playing: Bohemian Rhapsody by Queen (5:55)
Now playing: Stairway to Heaven by Led Zeppelin (8:02)
Now playing: Bohemian Rhapsody by Queen (5:55)

Playback history:
1. Bohemian Rhapsody by Queen
2. Stairway to Heaven by Led Zeppelin
3. Bohemian Rhapsody by Queen

Search results for "heaven":
- Stairway to Heaven by Led Zeppelin (8:02)

Filter by genre "Rock":
- Bohemian Rhapsody by Queen (5:55)
- Stairway to Heaven by Led Zeppelin (8:02)
- Hotel California by Eagles (6:30)

Setting user preferences...
Volume: 75%
Playback Speed: 1.25x
Shuffle: On
Repeat: Off

Library Statistics:
Total Items: 4
Total Duration: 23:27
Most Played: Bohemian Rhapsody by Queen (2 plays)
Average Rating: 4.5/5.0

Program completed successfully
```

## Tips

1. Use validation in all setters to maintain data integrity
2. Implement computed properties for derived values
3. Use const references for returning large objects
4. Add proper error handling and reporting
5. Ensure thread safety for concurrent access
6. Use meaningful operations instead of raw getters/setters

## Common Issues to Watch For

1. Insufficient validation
2. Missing error handling
3. Inconsistent state after failed operations
4. Performance issues with large collections
5. Thread safety problems
6. Memory leaks with dynamic resources

## Extension Challenges

If you complete the basic requirements, try these extensions:

1. Add media file loading and playback
2. Implement a recommendation system
3. Add user accounts and permissions
4. Create a persistent storage system
5. Implement a simple GUI interface

Good luck with your implementation!
