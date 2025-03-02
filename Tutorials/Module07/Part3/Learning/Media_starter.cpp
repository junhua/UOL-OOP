#include "Media_starter.h"

// TODO: Implement Media constructor
// Parameters:
// - title: Media title
// - artist: Media creator/artist
// - duration: Length in seconds
// Expected behavior:
// 1. Initialize all member variables
// 2. Set isPlaying to false
// 3. Print creation message:
//    "Creating media: [title]"

// TODO: Implement Media destructor
// Expected behavior:
// 1. Print destruction message:
//    "Destroying media: [title]"

// TODO: Implement play() method
// Expected behavior:
// 1. Check if not already playing
// 2. If not playing:
//    - Set isPlaying to true
//    - Print "Playing: [title]"

// TODO: Implement stop() method
// Expected behavior:
// 1. Check if currently playing
// 2. If playing:
//    - Set isPlaying to false
//    - Print "Stopped: [title]"

// TODO: Implement getter methods
// - Return corresponding member variables
// - Keep const correctness
// Example:
// string Media::getTitle() const {
//     return title;
// }

// TODO: Implement formatDuration() helper
// Algorithm:
// 1. Calculate minutes = duration / 60
// 2. Calculate seconds = duration % 60
// 3. Create formatted string:
//    - Convert minutes to string
//    - Add colon
//    - Add seconds with zero-padding
// Example: 125 -> "2:05"
