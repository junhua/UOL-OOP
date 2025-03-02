#ifndef DATA_HIDING_H
#define DATA_HIDING_H

#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>

// TODO: Implement poor encapsulation example
// Demonstrate why public data members and lack of validation is problematic
class BankAccountPoor {
    // Add public members that demonstrate poor encapsulation
    // - Public balance
    // - Public account number
    // - Public frozen status
    // - Methods without validation
};

// TODO: Implement good encapsulation example
class BankAccountGood {
private:
    // TODO: Add private member variables
    // - Account balance (double)
    // - Account number (string)
    // - Frozen status (bool)
    // - Transaction history (vector<string>)
    // - Last error message (string)
    
    // TODO: Implement private helper methods
    // - isValidAmount: Check if amount is positive
    // - recordTransaction: Add transaction to history with timestamp
    
public:
    // TODO: Implement constructor
    // - Initialize account with number
    // - Set initial balance to 0
    // - Set frozen status to false
    
    // TODO: Implement deposit method
    // - Check if account is frozen
    // - Validate amount is positive
    // - Update balance
    // - Record transaction
    // - Return success/failure
    
    // TODO: Implement withdraw method
    // - Check if account is frozen
    // - Validate amount is positive
    // - Check sufficient funds
    // - Update balance
    // - Record transaction
    // - Return success/failure
    
    // TODO: Implement getter methods
    // - getBalance: Return current balance
    // - getAccountNumber: Return account number
    // - isFrozen: Return frozen status
    // - getTransactionHistory: Return copy of history
    // - getLastError: Return last error message
    
    // TODO: Implement account management methods
    // - freeze: Freeze account
    // - unfreeze: Unfreeze account
};

// TODO: Implement secure password management
class Password {
private:
    // TODO: Add private member variables
    // - Hashed password (string)
    // - Salt value (string)
    // - Minimum length requirement (size_t)
    // - Last error message (string)
    
    // TODO: Implement private helper methods
    // - generateSalt: Create random salt value
    // - hashPassword: Hash password with salt
    
public:
    // TODO: Implement constructor
    // - Set minimum password length
    // - Generate initial salt
    
    // TODO: Implement password management methods
    // - setPassword: Set new password with validation
    // - validatePassword: Check if password matches
    // - checkStrength: Score password strength
    // - meetsRequirements: Check password requirements
    // - getLastError: Return last error message
};

// TODO: Implement logging system
class Logger {
private:
    // TODO: Add private member variables
    // - Log entries (vector<string>)
    // - Maximum size (size_t)
    // - Current log level (enum class)
    // - Last error message (string)
    
    // TODO: Implement private helper methods
    // - levelToString: Convert level to string
    // - formatMessage: Format log entry with timestamp
    // - maintainSize: Keep log within size limit
    
public:
    // TODO: Implement constructor
    // - Set maximum log size
    // - Initialize empty log
    // - Set default log level
    
    // TODO: Implement logging methods
    // - info: Log info message
    // - warning: Log warning message
    // - error: Log error message
    // - setLevel: Change current log level
    
    // TODO: Implement log management methods
    // - getLogs: Return copy of log entries
    // - clearLogs: Clear all entries
    // - size: Return current number of entries
    // - getLastError: Return last error message
};

#endif // DATA_HIDING_H
