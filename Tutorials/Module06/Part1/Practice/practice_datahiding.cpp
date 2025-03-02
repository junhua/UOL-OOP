#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <random>
using namespace std;

class SecureMessage {
private:
    string content;
    string encryptionKey;
    bool encrypted;
    mutable vector<string> accessLog;
    
    // Helper function to generate random key
    string generateKey(size_t length) {
        const string chars = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribution(0, chars.size() - 1);
        
        string key;
        for (size_t i = 0; i < length; ++i) {
            key += chars[distribution(generator)];
        }
        return key;
    }
    
    // Helper function to log access
    void logAccess(const string& action) const {
        time_t now = time(nullptr);
        string timestamp = ctime(&now);
        timestamp = timestamp.substr(0, timestamp.length() - 1);  // Remove newline
        
        stringstream ss;
        ss << "[" << timestamp << "] " << action;
        accessLog.push_back(ss.str());
    }
    
    // Helper function to encrypt/decrypt content
    string transform(const string& text, const string& key, bool encrypting) {
        string result = text;
        for (size_t i = 0; i < text.length(); ++i) {
            char& c = result[i];
            if (isalnum(c)) {
                char base = isdigit(c) ? '0' : (isupper(c) ? 'A' : 'a');
                int shift = key[i % key.length()] - 'A';
                if (!encrypting) shift = -shift;
                
                c = base + ((c - base + shift + 62) % 62);
            }
        }
        return result;
    }
    
public:
    SecureMessage() : encrypted(false) {
        encryptionKey = generateKey(16);
    }
    
    bool setContent(const string& newContent) {
        if (newContent.empty()) {
            cout << "Error: Content cannot be empty" << endl;
            return false;
        }
        
        content = newContent;
        encrypted = false;
        logAccess("Content updated");
        return true;
    }
    
    string getContent() const {
        if (encrypted) {
            cout << "Error: Content is encrypted" << endl;
            return "";
        }
        logAccess("Content accessed");
        return content;
    }
    
    bool encrypt() {
        if (content.empty()) {
            cout << "Error: No content to encrypt" << endl;
            return false;
        }
        
        if (encrypted) {
            cout << "Error: Content already encrypted" << endl;
            return false;
        }
        
        content = transform(content, encryptionKey, true);
        encrypted = true;
        logAccess("Content encrypted");
        return true;
    }
    
    bool decrypt() {
        if (content.empty()) {
            cout << "Error: No content to decrypt" << endl;
            return false;
        }
        
        if (!encrypted) {
            cout << "Error: Content not encrypted" << endl;
            return false;
        }
        
        content = transform(content, encryptionKey, false);
        encrypted = false;
        logAccess("Content decrypted");
        return true;
    }
    
    bool isEncrypted() const {
        return encrypted;
    }
    
    vector<string> getAccessHistory() const {
        return accessLog;
    }
    
    void clearAccessLog() {
        accessLog.clear();
        logAccess("Access log cleared");
    }
};

class SecureChannel {
private:
    vector<SecureMessage> messages;
    string channelId;
    bool active;
    
    // Helper function to generate channel ID
    string generateChannelId() {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribution(10000, 99999);
        return "CH" + to_string(distribution(generator));
    }
    
public:
    SecureChannel() : active(true) {
        channelId = generateChannelId();
    }
    
    string getChannelId() const {
        return channelId;
    }
    
    bool isActive() const {
        return active;
    }
    
    bool addMessage(const string& content) {
        if (!active) {
            cout << "Error: Channel is closed" << endl;
            return false;
        }
        
        SecureMessage message;
        if (!message.setContent(content)) {
            return false;
        }
        
        if (!message.encrypt()) {
            return false;
        }
        
        messages.push_back(message);
        return true;
    }
    
    bool readMessage(size_t index) {
        if (!active) {
            cout << "Error: Channel is closed" << endl;
            return false;
        }
        
        if (index >= messages.size()) {
            cout << "Error: Invalid message index" << endl;
            return false;
        }
        
        SecureMessage& message = messages[index];
        if (message.isEncrypted()) {
            if (!message.decrypt()) {
                return false;
            }
        }
        
        cout << "Message " << index << ": " << message.getContent() << endl;
        
        // Re-encrypt after reading
        return message.encrypt();
    }
    
    void closeChannel() {
        active = false;
    }
    
    size_t messageCount() const {
        return messages.size();
    }
    
    vector<string> getMessageHistory(size_t index) const {
        if (index >= messages.size()) {
            return vector<string>();
        }
        return messages[index].getAccessHistory();
    }
};

int main() {
    cout << "Secure Messaging Demo" << endl;
    cout << "===================" << endl;
    
    // Create secure channel
    SecureChannel channel;
    cout << "\nChannel created with ID: " << channel.getChannelId() << endl;
    
    // Add messages
    cout << "\nAdding messages:" << endl;
    cout << "---------------" << endl;
    
    vector<string> testMessages = {
        "Hello, this is a secret message!",
        "The meeting is at 3 PM tomorrow.",
        "Your access code is: 7890"
    };
    
    for (const auto& msg : testMessages) {
        if (channel.addMessage(msg)) {
            cout << "Message added successfully" << endl;
        }
    }
    
    // Read messages
    cout << "\nReading messages:" << endl;
    cout << "----------------" << endl;
    
    for (size_t i = 0; i < channel.messageCount(); ++i) {
        cout << "\nAccessing message " << i << ":" << endl;
        channel.readMessage(i);
        
        cout << "\nAccess history:" << endl;
        auto history = channel.getMessageHistory(i);
        for (const auto& entry : history) {
            cout << entry << endl;
        }
    }
    
    // Test error cases
    cout << "\nTesting error cases:" << endl;
    cout << "-----------------" << endl;
    
    cout << "Trying to read invalid message:" << endl;
    channel.readMessage(99);
    
    cout << "\nClosing channel..." << endl;
    channel.closeChannel();
    
    cout << "Trying to add message to closed channel:" << endl;
    channel.addMessage("This should fail");
    
    return 0;
}
