#ifndef MEDIA_LIBRARY_H
#define MEDIA_LIBRARY_H

#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>

/**
 * @class MediaItem
 * @brief Represents a media item with metadata and playback tracking
 * 
 * This class demonstrates proper encapsulation with validation,
 * computed properties, and state management.
 */
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

/**
 * @class MediaLibrary
 * @brief Manages a collection of media items with playlists and preferences
 * 
 * This class demonstrates thread-safe property access, collection management,
 * and state tracking.
 */
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

#endif // MEDIA_LIBRARY_H
