#include <iostream>
#include "SecureMessage_starter.h"
using namespace std;

void testMessageCreation() {
    cout << "\n=== Testing Message Creation ===\n";
    
    try {
        // Test invalid users
        try {
            SecureMessage msg("", "bob");  // Empty sender
            cout << "Error: Should reject empty sender" << endl;
        } catch (const exception& e) {
            cout << "Successfully rejected empty sender" << endl;
        }
        
        try {
            SecureMessage msg("alice", "");  // Empty recipient
            cout << "Error: Should reject empty recipient" << endl;
        } catch (const exception& e) {
            cout << "Successfully rejected empty recipient" << endl;
        }
        
        // Test valid creation
        SecureMessage msg("alice", "bob");
        cout << "Successfully created message" << endl;
        cout << msg.getStatus() << endl;
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
}

void testMessageContent() {
    cout << "\n=== Testing Message Content ===\n";
    
    try {
        SecureMessage msg("alice", "bob");
        
        // Test empty content
        if (!msg.setContent("")) {
            cout << "Successfully rejected empty content" << endl;
        }
        
        // Test valid content
        if (msg.setContent("Hello, Bob!")) {
            cout << "Successfully set content" << endl;
        }
        
        // Test unauthorized access
        string content = msg.getContent("eve");
        if (content.empty()) {
            cout << "Successfully prevented unauthorized access" << endl;
        }
        
        // Test authorized access
        content = msg.getContent("bob");
        if (!content.empty()) {
            cout << "Successfully retrieved content: " << content << endl;
        }
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
}

void testEncryption() {
    cout << "\n=== Testing Encryption ===\n";
    
    try {
        SecureMessage msg("alice", "bob");
        msg.setContent("Secret message");
        
        // Test encryption
        if (msg.enableEncryption()) {
            cout << "Successfully enabled encryption" << endl;
            
            // Verify content is still accessible to authorized users
            string content = msg.getContent("bob");
            if (content == "Secret message") {
                cout << "Content correctly decrypted for recipient" << endl;
            }
            
            // Try disabling encryption
            if (msg.disableEncryption()) {
                cout << "Successfully disabled encryption" << endl;
            }
        }
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
}

void testAccessLog() {
    cout << "\n=== Testing Access Log ===\n";
    
    try {
        SecureMessage msg("alice", "bob");
        msg.setContent("Test message");
        
        // Generate some access events
        msg.getContent("eve");  // Unauthorized
        msg.getContent("bob");  // Authorized
        msg.enableEncryption();
        msg.getContent("alice"); // Authorized
        
        // Check log
        auto log = msg.getAccessLog();
        cout << "Access Log:" << endl;
        for (const auto& entry : log) {
            cout << entry << endl;
        }
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
}

int main() {
    testMessageCreation();
    testMessageContent();
    testEncryption();
    testAccessLog();
    return 0;
}
