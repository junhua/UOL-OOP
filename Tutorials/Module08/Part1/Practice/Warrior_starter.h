#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character_starter.h"

/**
 * @class Warrior
 * @brief Warrior character derived from Character
 * 
 * This class represents a warrior with high health and strong physical attacks.
 * It inherits from the Character base class and implements
 * all the required virtual methods.
 */
class Warrior : public Character {
private:
    // TODO: Add private member variables specific to Warrior
    // For example: weaponType, armorClass, etc.
    
public:
    /**
     * @brief Constructor
     * @param name The warrior's name
     * @param health The warrior's initial health (should be high)
     * @param power The warrior's power level
     * @param weaponType The type of weapon the warrior uses
     */
    // TODO: Implement constructor that initializes the base class and warrior-specific members
    
    /**
     * @brief Destructor
     */
    // TODO: Implement destructor that prints a message
    
    /**
     * @brief Get the warrior's weapon type
     * @return The weapon type as a string
     */
    // TODO: Implement a getter for the warrior-specific member(s)
    
    /**
     * @brief Attack action
     * 
     * Implement the warrior's attack behavior.
     * Warriors typically perform strong physical attacks.
     */
    // TODO: Override the attack method from the base class
    
    /**
     * @brief Defend action
     * 
     * Implement the warrior's defense behavior.
     * Warriors typically use shields or armor to absorb damage.
     */
    // TODO: Override the defend method from the base class
    
    /**
     * @brief Display warrior stats
     * 
     * This method should call the base class displayStats method
     * and then add warrior-specific information.
     */
    // TODO: Override the displayStats method from the base class
    
    /**
     * @brief Special ability: Rage
     * 
     * A warrior-specific method that temporarily increases attack power.
     */
    // TODO: Implement a warrior-specific method
};

#endif // WARRIOR_H
