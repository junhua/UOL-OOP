#ifndef SONG_H
#define SONG_H

#include "Media_starter.h"

// TODO: Implement the Song class that inherits from Media
class Song {
private:
    // TODO: Add private members for:
    // - album (string)
    // - genre (string)
    
public:
    // TODO: Implement constructor
    // Parameters:
    // - All Media parameters (title, artist, duration)
    // - album: Album name
    // - genre: Music genre
    // Expected behavior:
    // 1. Initialize Media base class
    // 2. Initialize Song members
    // 3. Print creation message:
    //    "Creating song: [title] from [album]"
    
    // TODO: Implement destructor
    // Expected behavior:
    // 1. Print destruction message:
    //    "Destroying song: [title]"
    
    // TODO: Override play() method
    // Expected behavior:
    // 1. Call Media's play()
    // 2. If now playing, print:
    //    "♪ Playing music: [title] - [artist]"
    
    // TODO: Override displayInfo() method
    // Expected output format:
    // Song Information:
    // ================
    // Title: [title]
    // Artist: [artist]
    // Album: [album]
    // Genre: [genre]
    // Duration: [MM:SS]
    // Status: [Playing/Stopped]
    
    // TODO: Override getType() method
    // - Return "Song" as the media type
    
    // TODO: Implement Song-specific getters:
    // - getAlbum()
    // - getGenre()
};

#endif // SONG_H
