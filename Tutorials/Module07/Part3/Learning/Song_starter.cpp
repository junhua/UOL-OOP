#include "Song_starter.h"

// TODO: Implement Song constructor
// Remember:
// 1. Use initialization list to:
//    - Call Media constructor with base class parameters
//    - Initialize Song's members (album, genre)
// 2. Print creation message in constructor body
// Example:
// Song::Song(string title, string artist, int duration,
//            string album, string genre)
//     : Media(title, artist, duration),
//       album(album), genre(genre) {
//     cout << "Creating song: " << title << " from " << album << endl;
// }

// TODO: Implement Song destructor
// Remember:
// 1. Mark as override
// 2. Print destruction message
// 3. Base class destructor will be called automatically

// TODO: Implement play() override
// Remember:
// 1. Mark as override
// 2. Call base class play() first
// 3. Check if now playing
// 4. Add Song-specific output
// Example:
// void Song::play() override {
//     Media::play();  // Call base first
//     if (getIsPlaying()) {
//         cout << "♪ Playing music: " << getTitle() << " - " << getArtist() << endl;
//     }
// }

// TODO: Implement displayInfo() override
// Remember:
// 1. Mark as override
// 2. Follow output format exactly
// 3. Use formatDuration() for time
// 4. Show current playing status

// TODO: Implement getType() override
// Remember:
// 1. Mark as override
// 2. Return "Song" as the type string

// TODO: Implement Song-specific getters
// - Keep const correctness
// Example:
// string Song::getAlbum() const {
//     return album;
// }
