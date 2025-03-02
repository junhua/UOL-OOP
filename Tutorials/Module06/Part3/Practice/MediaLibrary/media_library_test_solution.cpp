#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include "MediaLibrary.h"

using namespace std;

/**
 * Test program for the MediaLibrary implementation
 * 
 * This program demonstrates:
 * 1. Creating and managing media items
 * 2. Creating and managing playlists
 * 3. Simulating playback
 * 4. Searching and filtering
 * 5. Managing user preferences
 * 6. Thread safety
 */
int main() {
    cout << "Media Library System" << endl;
    cout << "==================================================" << endl << endl;

    // Create a media library
    MediaLibrary library;

    // Add media items
    cout << "Adding media items..." << endl;
    
    MediaItem bohemianRhapsody("Bohemian Rhapsody", "Queen", 355, "Rock", "/music/bohemian_rhapsody.mp3");
    MediaItem stairwayToHeaven("Stairway to Heaven", "Led Zeppelin", 482, "Rock", "/music/stairway_to_heaven.mp3");
    MediaItem hotelCalifornia("Hotel California", "Eagles", 390, "Rock", "/music/hotel_california.mp3");
    MediaItem imagine("Imagine", "John Lennon", 183, "Pop", "/music/imagine.mp3");
    
    library.addItem(bohemianRhapsody);
    library.addItem(stairwayToHeaven);
    library.addItem(hotelCalifornia);
    library.addItem(imagine);
    
    cout << "Added: \"" << bohemianRhapsody.getTitle() << "\" by " << bohemianRhapsody.getArtist() << endl;
    cout << "Added: \"" << stairwayToHeaven.getTitle() << "\" by " << stairwayToHeaven.getArtist() << endl;
    cout << "Added: \"" << hotelCalifornia.getTitle() << "\" by " << hotelCalifornia.getArtist() << endl;
    cout << "Added: \"" << imagine.getTitle() << "\" by " << imagine.getArtist() << endl;
    cout << endl;

    // Create playlists
    cout << "Creating playlists..." << endl;
    
    library.createPlaylist("Rock Classics");
    cout << "Created playlist: \"Rock Classics\"" << endl;
    
    library.addToPlaylist("Rock Classics", bohemianRhapsody.getId());
    library.addToPlaylist("Rock Classics", stairwayToHeaven.getId());
    library.addToPlaylist("Rock Classics", hotelCalifornia.getId());
    
    cout << "Added \"" << bohemianRhapsody.getTitle() << "\" to \"Rock Classics\"" << endl;
    cout << "Added \"" << stairwayToHeaven.getTitle() << "\" to \"Rock Classics\"" << endl;
    cout << "Added \"" << hotelCalifornia.getTitle() << "\" to \"Rock Classics\"" << endl;
    cout << endl;

    // Simulate playback
    cout << "Simulating playback..." << endl;
    
    library.playItem(bohemianRhapsody.getId());
    cout << "Now playing: " << bohemianRhapsody.getTitle() << " by " 
         << bohemianRhapsody.getArtist() << " (" << bohemianRhapsody.getFormattedDuration() << ")" << endl;
    
    library.playItem(stairwayToHeaven.getId());
    cout << "Now playing: " << stairwayToHeaven.getTitle() << " by " 
         << stairwayToHeaven.getArtist() << " (" << stairwayToHeaven.getFormattedDuration() << ")" << endl;
    
    library.playItem(bohemianRhapsody.getId());
    cout << "Now playing: " << bohemianRhapsody.getTitle() << " by " 
         << bohemianRhapsody.getArtist() << " (" << bohemianRhapsody.getFormattedDuration() << ")" << endl;
    cout << endl;

    // Display playback history
    cout << "Playback history:" << endl;
    
    auto history = library.getPlaybackHistory();
    int count = 1;
    for (const auto& item : history) {
        cout << count++ << ". " << item.getTitle() << " by " << item.getArtist() << endl;
    }
    cout << endl;

    // Search for media
    cout << "Search results for \"heaven\":" << endl;
    
    auto searchResults = library.search("heaven");
    for (const auto& item : searchResults) {
        cout << "- " << item.getTitle() << " by " << item.getArtist() 
             << " (" << item.getFormattedDuration() << ")" << endl;
    }
    cout << endl;

    // Filter by genre
    cout << "Filter by genre \"Rock\":" << endl;
    
    auto rockSongs = library.filterByGenre("Rock");
    for (const auto& item : rockSongs) {
        cout << "- " << item.getTitle() << " by " << item.getArtist() 
             << " (" << item.getFormattedDuration() << ")" << endl;
    }
    cout << endl;

    // Set user preferences
    cout << "Setting user preferences..." << endl;
    
    library.setVolume(75.0);
    library.setPlaybackSpeed(1.25);
    library.toggleShuffle();
    
    cout << "Volume: " << library.getVolume() << "%" << endl;
    cout << "Playback Speed: " << library.getPlaybackSpeed() << "x" << endl;
    cout << "Shuffle: " << (library.isShuffle() ? "On" : "Off") << endl;
    cout << "Repeat: " << (library.isRepeat() ? "On" : "Off") << endl;
    cout << endl;

    // Display library statistics
    cout << "Library Statistics:" << endl;
    
    cout << "Total Items: " << library.getAllItems().size() << endl;
    cout << "Total Duration: " << library.getFormattedTotalDuration() << endl;
    
    MediaItem mostPlayed = library.getMostPlayed();
    cout << "Most Played: " << mostPlayed.getTitle() << " by " 
         << mostPlayed.getArtist() << " (" << mostPlayed.getPlayCount() << " plays)" << endl;
    
    // Set ratings for some items
    bohemianRhapsody.setRating(5.0);
    stairwayToHeaven.setRating(4.5);
    hotelCalifornia.setRating(4.0);
    
    // Update items in library
    library.removeItem(bohemianRhapsody.getId());
    library.removeItem(stairwayToHeaven.getId());
    library.removeItem(hotelCalifornia.getId());
    
    library.addItem(bohemianRhapsody);
    library.addItem(stairwayToHeaven);
    library.addItem(hotelCalifornia);
    
    cout << "Average Rating: " << fixed << setprecision(1) << library.getAverageRating() << "/5.0" << endl;
    cout << endl;

    cout << "Program completed successfully" << endl;
    return 0;
}
