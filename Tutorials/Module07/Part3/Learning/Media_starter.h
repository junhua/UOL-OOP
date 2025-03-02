#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>
#include <iomanip>

// TODO: Implement the Media base class
class Media {
protected:
    // TODO: Add protected members for:
    // - title (string)
    // - artist (string)
    // - duration (int, in seconds)
    // - isPlaying (bool)
    
public:
    // TODO: Implement constructor
    // - Initialize all members
    // - Set isPlaying to false
    // - Print creation message:
    //   "Creating media: [title]"
    
    // TODO: Implement virtual destructor
    // - Print destruction message:
    //   "Destroying media: [title]"
    
    // TODO: Implement virtual play() method
    // Expected behavior:
    // 1. Check if not already playing
    // 2. Set isPlaying to true
    // 3. Print "Playing: [title]"
    
    // TODO: Implement virtual stop() method
    // Expected behavior:
    // 1. Check if currently playing
    // 2. Set isPlaying to false
    // 3. Print "Stopped: [title]"
    
    // TODO: Implement pure virtual methods:
    // - displayInfo() const: Show media details
    // - getType() const: Return media type string
    
    // TODO: Implement getters:
    // - getTitle()
    // - getArtist()
    // - getDuration()
    // - getIsPlaying()
    
protected:
    // TODO: Implement helper method:
    // string formatDuration() const
    // - Convert duration to "MM:SS" format
    // - Handle proper zero-padding
    // Example: 125 seconds -> "2:05"
};

#endif // MEDIA_H
