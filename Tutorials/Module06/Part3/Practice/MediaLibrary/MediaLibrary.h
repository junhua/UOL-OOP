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
#include <numeric>
#include <functional>
#include <memory>

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
    
    // Validation methods
    bool isValidTitle(const std::string& title) const {
        if (title.empty()) {
            lastError = "Title cannot be empty";
            return false;
        }
        if (title.length() > 100) {
            lastError = "Title too long (max 100 characters)";
            return false;
        }
        return true;
    }
    
    bool isValidArtist(const std::string& artist) const {
        if (artist.empty()) {
            lastError = "Artist cannot be empty";
            return false;
        }
        if (artist.length() > 100) {
            lastError = "Artist name too long (max 100 characters)";
            return false;
        }
        return true;
    }
    
    bool isValidDuration(int seconds) const {
        if (seconds <= 0) {
            lastError = "Duration must be positive";
            return false;
        }
        if (seconds > 24 * 60 * 60) {  // 24 hours
            lastError = "Duration too long (max 24 hours)";
            return false;
        }
        return true;
    }
    
    bool isValidRating(double rating) const {
        if (rating < 0.0 || rating > 5.0) {
            lastError = "Rating must be between 0.0 and 5.0";
            return false;
        }
        return true;
    }
    
    bool isValidGenre(const std::string& genre) const {
        if (genre.empty()) {
            lastError = "Genre cannot be empty";
            return false;
        }
        return true;
    }
    
    bool isValidFilePath(const std::string& path) const {
        if (path.empty()) {
            lastError = "File path cannot be empty";
            return false;
        }
        return true;
    }
    
    // Generate a unique ID
    std::string generateId() const {
        static int counter = 0;
        return "MEDIA_" + std::to_string(++counter);
    }
    
public:
    // Constructor
    MediaItem(const std::string& title = "", 
              const std::string& artist = "", 
              int duration = 0,
              const std::string& genre = "",
              const std::string& filePath = "")
        : id(generateId()), 
          title(title), 
          artist(artist), 
          duration(duration), 
          genre(genre), 
          filePath(filePath), 
          rating(0.0), 
          playCount(0) {
        
        // Validate inputs
        if (!isValidTitle(title)) {
            this->title = "Unknown Title";
        }
        
        if (!isValidArtist(artist)) {
            this->artist = "Unknown Artist";
        }
        
        if (!isValidDuration(duration)) {
            this->duration = 0;
        }
        
        if (!isValidGenre(genre)) {
            this->genre = "Unknown";
        }
        
        if (!isValidFilePath(filePath)) {
            this->filePath = "";
        }
        
        // Initialize lastPlayed to epoch
        lastPlayed = std::chrono::system_clock::from_time_t(0);
    }
    
    // Getters
    std::string getId() const { return id; }
    
    std::string getTitle() const { return title; }
    
    std::string getArtist() const { return artist; }
    
    int getDuration() const { return duration; }
    
    std::string getGenre() const { return genre; }
    
    std::string getFilePath() const { return filePath; }
    
    double getRating() const { return rating; }
    
    int getPlayCount() const { return playCount; }
    
    std::chrono::system_clock::time_point getLastPlayed() const { return lastPlayed; }
    
    std::string getLastError() const { return lastError; }
    
    // Setters with validation
    bool setTitle(const std::string& newTitle) {
        if (!isValidTitle(newTitle)) {
            return false;
        }
        title = newTitle;
        return true;
    }
    
    bool setArtist(const std::string& newArtist) {
        if (!isValidArtist(newArtist)) {
            return false;
        }
        artist = newArtist;
        return true;
    }
    
    bool setDuration(int seconds) {
        if (!isValidDuration(seconds)) {
            return false;
        }
        duration = seconds;
        return true;
    }
    
    bool setGenre(const std::string& newGenre) {
        if (!isValidGenre(newGenre)) {
            return false;
        }
        genre = newGenre;
        return true;
    }
    
    bool setFilePath(const std::string& path) {
        if (!isValidFilePath(path)) {
            return false;
        }
        filePath = path;
        return true;
    }
    
    bool setRating(double newRating) {
        if (!isValidRating(newRating)) {
            return false;
        }
        rating = newRating;
        return true;
    }
    
    // Playback tracking
    void incrementPlayCount() {
        playCount++;
        lastPlayed = std::chrono::system_clock::now();
    }
    
    // Computed properties
    std::string getFormattedDuration() const {
        int minutes = duration / 60;
        int seconds = duration % 60;
        std::stringstream ss;
        ss << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
        return ss.str();
    }
    
    bool isRecentlyPlayed(int days = 7) const {
        if (lastPlayed == std::chrono::system_clock::from_time_t(0)) {
            return false;
        }
        
        auto now = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::hours>(now - lastPlayed).count();
        return diff <= days * 24;
    }
    
    // Utility methods
    std::string getDisplayName() const {
        return title + " by " + artist + " (" + getFormattedDuration() + ")";
    }
    
    bool matchesQuery(const std::string& query) const {
        std::string lowerQuery = query;
        std::transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), 
                      [](unsigned char c){ return std::tolower(c); });
        
        std::string lowerTitle = title;
        std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), 
                      [](unsigned char c){ return std::tolower(c); });
        
        std::string lowerArtist = artist;
        std::transform(lowerArtist.begin(), lowerArtist.end(), lowerArtist.begin(), 
                      [](unsigned char c){ return std::tolower(c); });
        
        std::string lowerGenre = genre;
        std::transform(lowerGenre.begin(), lowerGenre.end(), lowerGenre.begin(), 
                      [](unsigned char c){ return std::tolower(c); });
        
        return lowerTitle.find(lowerQuery) != std::string::npos ||
               lowerArtist.find(lowerQuery) != std::string::npos ||
               lowerGenre.find(lowerQuery) != std::string::npos;
    }
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
    
    // Validation methods
    bool isValidVolume(double vol) const {
        if (vol < 0.0 || vol > 100.0) {
            lastError = "Volume must be between 0.0 and 100.0";
            return false;
        }
        return true;
    }
    
    bool isValidPlaybackSpeed(double speed) const {
        if (speed < 0.25 || speed > 2.0) {
            lastError = "Playback speed must be between 0.25 and 2.0";
            return false;
        }
        return true;
    }
    
    bool isValidPlaylistName(const std::string& name) const {
        if (name.empty()) {
            lastError = "Playlist name cannot be empty";
            return false;
        }
        return true;
    }
    
    // Helper methods
    MediaItem* findItemById(const std::string& id) {
        auto it = std::find_if(items.begin(), items.end(),
                              [&id](const MediaItem& item) { return item.getId() == id; });
        return (it != items.end()) ? &(*it) : nullptr;
    }
    
    const MediaItem* findItemById(const std::string& id) const {
        auto it = std::find_if(items.begin(), items.end(),
                              [&id](const MediaItem& item) { return item.getId() == id; });
        return (it != items.end()) ? &(*it) : nullptr;
    }
    
public:
    // Constructor
    MediaLibrary() 
        : volume(50.0), 
          playbackSpeed(1.0), 
          shuffle(false), 
          repeat(false) {}
    
    // Media management methods
    bool addItem(const MediaItem& item) {
        std::lock_guard<std::mutex> lock(mutex);
        
        // Check if item with same ID already exists
        if (findItemById(item.getId()) != nullptr) {
            lastError = "Item with ID " + item.getId() + " already exists";
            return false;
        }
        
        items.push_back(item);
        return true;
    }
    
    bool removeItem(const std::string& id) {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto it = std::find_if(items.begin(), items.end(),
                              [&id](const MediaItem& item) { return item.getId() == id; });
        
        if (it == items.end()) {
            lastError = "Item with ID " + id + " not found";
            return false;
        }
        
        // Remove from all playlists
        for (auto& playlist : playlists) {
            auto& itemIds = playlist.second;
            itemIds.erase(std::remove(itemIds.begin(), itemIds.end(), id), itemIds.end());
        }
        
        // Remove from playback history
        playbackHistory.erase(std::remove(playbackHistory.begin(), playbackHistory.end(), id), 
                             playbackHistory.end());
        
        // Remove the item
        items.erase(it);
        return true;
    }
    
    // Playlist methods
    bool createPlaylist(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!isValidPlaylistName(name)) {
            return false;
        }
        
        if (playlists.find(name) != playlists.end()) {
            lastError = "Playlist '" + name + "' already exists";
            return false;
        }
        
        playlists[name] = std::vector<std::string>();
        return true;
    }
    
    bool removePlaylist(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto it = playlists.find(name);
        if (it == playlists.end()) {
            lastError = "Playlist '" + name + "' not found";
            return false;
        }
        
        playlists.erase(it);
        return true;
    }
    
    bool addToPlaylist(const std::string& playlistName, const std::string& itemId) {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto playlistIt = playlists.find(playlistName);
        if (playlistIt == playlists.end()) {
            lastError = "Playlist '" + playlistName + "' not found";
            return false;
        }
        
        if (findItemById(itemId) == nullptr) {
            lastError = "Item with ID " + itemId + " not found";
            return false;
        }
        
        // Check if item is already in playlist
        auto& itemIds = playlistIt->second;
        if (std::find(itemIds.begin(), itemIds.end(), itemId) != itemIds.end()) {
            lastError = "Item already in playlist";
            return false;
        }
        
        itemIds.push_back(itemId);
        return true;
    }
    
    bool removeFromPlaylist(const std::string& playlistName, const std::string& itemId) {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto playlistIt = playlists.find(playlistName);
        if (playlistIt == playlists.end()) {
            lastError = "Playlist '" + playlistName + "' not found";
            return false;
        }
        
        auto& itemIds = playlistIt->second;
        auto it = std::find(itemIds.begin(), itemIds.end(), itemId);
        if (it == itemIds.end()) {
            lastError = "Item not in playlist";
            return false;
        }
        
        itemIds.erase(it);
        return true;
    }
    
    // Playback methods
    bool playItem(const std::string& itemId) {
        std::lock_guard<std::mutex> lock(mutex);
        
        MediaItem* item = findItemById(itemId);
        if (item == nullptr) {
            lastError = "Item with ID " + itemId + " not found";
            return false;
        }
        
        item->incrementPlayCount();
        playbackHistory.push_back(itemId);
        
        // Keep history at a reasonable size
        if (playbackHistory.size() > 100) {
            playbackHistory.erase(playbackHistory.begin());
        }
        
        return true;
    }
    
    // Search methods
    std::vector<MediaItem> search(const std::string& query) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        std::vector<MediaItem> results;
        for (const auto& item : items) {
            if (item.matchesQuery(query)) {
                results.push_back(item);
            }
        }
        
        return results;
    }
    
    std::vector<MediaItem> filterByGenre(const std::string& genre) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        std::vector<MediaItem> results;
        for (const auto& item : items) {
            if (item.getGenre() == genre) {
                results.push_back(item);
            }
        }
        
        return results;
    }
    
    // Preference methods
    bool setVolume(double vol) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!isValidVolume(vol)) {
            return false;
        }
        
        volume = vol;
        return true;
    }
    
    double getVolume() const {
        std::lock_guard<std::mutex> lock(mutex);
        return volume;
    }
    
    bool setPlaybackSpeed(double speed) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!isValidPlaybackSpeed(speed)) {
            return false;
        }
        
        playbackSpeed = speed;
        return true;
    }
    
    double getPlaybackSpeed() const {
        std::lock_guard<std::mutex> lock(mutex);
        return playbackSpeed;
    }
    
    void toggleShuffle() {
        std::lock_guard<std::mutex> lock(mutex);
        shuffle = !shuffle;
    }
    
    bool isShuffle() const {
        std::lock_guard<std::mutex> lock(mutex);
        return shuffle;
    }
    
    void toggleRepeat() {
        std::lock_guard<std::mutex> lock(mutex);
        repeat = !repeat;
    }
    
    bool isRepeat() const {
        std::lock_guard<std::mutex> lock(mutex);
        return repeat;
    }
    
    // Access methods
    const MediaItem& getItem(const std::string& id) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        const MediaItem* item = findItemById(id);
        if (item == nullptr) {
            static MediaItem emptyItem;
            lastError = "Item with ID " + id + " not found";
            return emptyItem;
        }
        
        return *item;
    }
    
    std::vector<MediaItem> getAllItems() const {
        std::lock_guard<std::mutex> lock(mutex);
        return items;
    }
    
    std::vector<std::string> getPlaylistNames() const {
        std::lock_guard<std::mutex> lock(mutex);
        
        std::vector<std::string> names;
        for (const auto& playlist : playlists) {
            names.push_back(playlist.first);
        }
        
        return names;
    }
    
    std::vector<MediaItem> getPlaylistItems(const std::string& playlistName) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto it = playlists.find(playlistName);
        if (it == playlists.end()) {
            lastError = "Playlist '" + playlistName + "' not found";
            return {};
        }
        
        std::vector<MediaItem> playlistItems;
        for (const auto& id : it->second) {
            const MediaItem* item = findItemById(id);
            if (item != nullptr) {
                playlistItems.push_back(*item);
            }
        }
        
        return playlistItems;
    }
    
    std::vector<MediaItem> getPlaybackHistory() const {
        std::lock_guard<std::mutex> lock(mutex);
        
        std::vector<MediaItem> history;
        for (auto it = playbackHistory.rbegin(); it != playbackHistory.rend(); ++it) {
            const MediaItem* item = findItemById(*it);
            if (item != nullptr) {
                history.push_back(*item);
            }
        }
        
        return history;
    }
    
    // Statistics methods
    int getTotalDuration() const {
        std::lock_guard<std::mutex> lock(mutex);
        
        int total = 0;
        for (const auto& item : items) {
            total += item.getDuration();
        }
        
        return total;
    }
    
    std::string getFormattedTotalDuration() const {
        int totalSeconds = getTotalDuration();
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        
        std::stringstream ss;
        if (hours > 0) {
            ss << hours << ":";
        }
        ss << std::setw(2) << std::setfill('0') << minutes << ":"
           << std::setw(2) << std::setfill('0') << seconds;
        
        return ss.str();
    }
    
    MediaItem getMostPlayed() const {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (items.empty()) {
            return MediaItem();
        }
        
        auto it = std::max_element(items.begin(), items.end(),
                                  [](const MediaItem& a, const MediaItem& b) {
                                      return a.getPlayCount() < b.getPlayCount();
                                  });
        
        return *it;
    }
    
    double getAverageRating() const {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (items.empty()) {
            return 0.0;
        }
        
        double sum = 0.0;
        int count = 0;
        
        for (const auto& item : items) {
            if (item.getRating() > 0.0) {
                sum += item.getRating();
                count++;
            }
        }
        
        return count > 0 ? sum / count : 0.0;
    }
    
    // Error handling
    std::string getLastError() const {
        std::lock_guard<std::mutex> lock(mutex);
        return lastError;
    }
};

#endif // MEDIA_LIBRARY_H
