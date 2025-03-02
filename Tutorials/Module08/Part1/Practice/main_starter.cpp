#include <iostream>
#include <vector>
#include <memory>
#include "Character_starter.h"
#include "Warrior_starter.h"
// TODO: Include headers for other character classes (Mage, Rogue)

using namespace std;

/**
 * This program demonstrates polymorphism using a Character hierarchy.
 * It creates a collection of different character types and processes them
 * uniformly through their common base class interface.
 */
int main() {
    try {
        cout << "Game Character System Demo" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Create a vector of Character pointers to store different characters
        
        // TODO: Add a Warrior to the vector
        
        // TODO: Add a Mage to the vector
        
        // TODO: Add a Rogue to the vector
        
        // TODO: Process all characters polymorphically
        // For each character in the vector:
        //   - Display its stats
        //   - Make it attack
        //   - Make it defend
        
        cout << "\nDemonstrating character-specific abilities:" << endl;
        cout << string(50, '-') << endl;
        
        // TODO: Create individual character objects
        
        // TODO: Call character-specific methods
        // For example: warrior.rage(), mage.castSpell(), rogue.stealth()
        
        cout << "\nDemonstrating virtual destructors:" << endl;
        cout << string(50, '-') << endl;
        
        // TODO: Create a Character pointer to a new Warrior
        
        // TODO: Delete the pointer (should call both destructors)
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
