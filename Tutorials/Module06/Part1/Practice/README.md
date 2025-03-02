# Secure Message Practice Exercise

This exercise combines the key concepts of data hiding and encapsulation covered in Part 1:
- Data protection (like BankAccount example)
- Security features (like Password example)
- State management (like Logger example)

## Requirements

### 1. Data Protection
- Message content must be private
- Sender and recipient information must be protected
- All data access must be controlled
- Input validation required
- Error tracking needed

### 2. Security Features
- Username validation (non-empty, max length)
- Optional message encryption
- Access control based on sender/recipient
- Secure error messages (no information leakage)
- Activity logging

### 3. State Management
- Track message status (created, modified, encrypted)
- Maintain access log
- Record timestamps
- Handle state transitions
- Prevent invalid states

### 4. Required Methods

#### Constructor
```cpp
SecureMessage(const std::string& sender, const std::string& recipient);
```
- Validate both usernames
- Initialize timestamp
- Start access log
- Throw exception for invalid users

#### Message Management
```cpp
bool setContent(const std::string& content);
std::string getContent(const std::string& requestor) const;
bool enableEncryption();
bool disableEncryption();
```
- Validate all inputs
- Control access
- Handle encryption
- Track changes

#### Status Methods
```cpp
std::string getStatus() const;
std::string getLastError() const;
std::vector<std::string> getAccessLog() const;
```
- Format status clearly
- Provide error details
- Return access history

## Implementation Tips

1. **Data Validation**
   - Check username format
   - Validate message content
   - Verify access rights
   - Handle edge cases

2. **Error Handling**
   - Use descriptive error messages
   - Track last error
   - Return success/failure
   - Throw for constructor errors

3. **Security**
   - Simple encryption is fine (e.g., Caesar cipher)
   - Log access attempts
   - Protect sensitive data
   - Validate all operations

4. **Testing**
   - Use provided test file
   - Check all error cases
   - Verify access control
   - Test state transitions

## Example Usage

```cpp
try {
    // Create message
    SecureMessage msg("alice", "bob");
    
    // Set content
    if (!msg.setContent("Hello, Bob!")) {
        cout << "Failed: " << msg.getLastError() << endl;
        return 1;
    }
    
    // Enable encryption
    msg.enableEncryption();
    
    // Try unauthorized access
    string content = msg.getContent("eve");
    if (content.empty()) {
        cout << "Unauthorized access prevented" << endl;
    }
    
    // Show status
    cout << msg.getStatus() << endl;
    
} catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
}
```

## Evaluation Criteria

1. **Encapsulation**
   - Proper data hiding
   - Controlled access
   - State management
   - Error handling

2. **Security**
   - Access control
   - Data protection
   - Activity logging
   - Input validation

3. **Code Quality**
   - Clear organization
   - Good documentation
   - Error handling
   - State consistency

4. **Testing**
   - All tests pass
   - Edge cases handled
   - Error cases tested
   - States verified
