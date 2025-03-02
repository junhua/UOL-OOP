#include <iostream>
#include <vector>
#include <iomanip>
#include "Media_starter.h"
#include "Song_starter.h"

using namespace std;

/**
 * This program demonstrates method overriding and polymorphism
 * using Media and Song classes.
 * 
 * Complete the Media_starter and Song_starter files, then use
 * this program to test your implementation.
 * 
 * Tasks:
 * 1. Implement Media base class:
 *    - Add member variables
 *    - Create virtual methods
 *    - Define pure virtual methods
 * 
 * 2. Implement Song derived class:
 *    - Add song-specific members
 *    - Override virtual methods
 *    - Add unique functionality
 */

int main() {
    cout << "Media Player System" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Test Media methods through Song object
    cout << "\nTesting Basic Media Operations:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create a Song
    // Song* song = new Song("Bohemian Rhapsody", "Queen", 354,
    //                      "A Night at the Opera", "Rock");
    
    // TODO: Test Media operations
    // - Display song info
    // - Play the song
    // - Stop the song
    // - Display updated status
    
    // TODO: Test polymorphic behavior
    cout << "\nTesting Polymorphism:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create a vector of Media pointers
    // vector<Media*> playlist;
    
    // TODO: Add different songs
    // - Add rock song
    // - Add pop song
    // - Add classical song
    
    // TODO: Process all media polymorphically
    // - Display all info
    // - Play each item
    // - Show playing status
    // - Stop each item
    // - Clean up properly
    
    // TODO: Test override behavior
    cout << "\nTesting Override Specifics:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create Media pointer to Song
    // Media* media = new Song(...);
    
    // TODO: Test virtual method behavior
    // - Call play()
    // - Call displayInfo()
    // - Call getType()
    // - Clean up
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
