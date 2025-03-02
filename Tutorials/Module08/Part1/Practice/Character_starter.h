#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

/**
 * @class Character
 * @brief Abstract base class for all game characters
 * 
 * This class defines the common interface for all characters in our game.
 * It provides pure virtual methods that all derived classes must implement,
 * as well as common functionality shared by all characters.
 */
class Character {
protected:
    // TODO: Add protected member variables for name, health, and power
    
public:
    /**
     * @brief Constructor
     * @param name The character's name
     * @param health The character's initial health
     * @param power The character's power level
     */
    // TODO: Implement constructor that initializes the member variables
    
    /**
     * @brief Virtual destructor
     * 
     * Virtual destructor is essential for proper cleanup of derived objects
     * when deleted through a base class pointer.
     */
    // TODO: Implement virtual destructor
    
    /**
     * @brief Get the character's name
     * @return The name as a string
     */
    // TODO: Implement a getter for the name
    
    /**
     * @brief Get the character's health
     * @return The health as an integer
     */
    // TODO: Implement a getter for the health
    
    /**
     * @brief Get the character's power
     * @return The power as an integer
     */
    // TODO: Implement a getter for the power
    
    /**
     * @brief Attack action
     * 
     * This is a pure virtual method that must be implemented by all derived classes.
     * Each character type will have its own attack behavior.
     */
    // TODO: Declare a pure virtual method for attack
    
    /**
     * @brief Defend action
     * 
     * This is a pure virtual method that must be implemented by all derived classes.
     * Each character type will have its own defense behavior.
     */
    // TODO: Declare a pure virtual method for defend
    
    /**
     * @brief Display character stats
     * 
     * This method displays common information about the character.
     * It can be overridden by derived classes to add more specific information.
     */
    // TODO: Implement a virtual method to display character stats
};

#endif // CHARACTER_H
