#ifndef PROPERTY_ACCESS_H
#define PROPERTY_ACCESS_H

#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <chrono>

// Example of poor property access
class UserPoor {
public:
    std::string username;  // Direct access to data
    std::string email;
    int age;
    bool active;
    
    void printInfo() {
        std::cout << username << " (" << email << ")" << std::endl;
    }
};

// Example of good property access
class User {
private:
    std::string username;
    std::string email;
    int age;
    bool active;
    std::vector<std::string> loginHistory;
    mutable std::mutex mutex;  // For thread-safe operations
    
    // Validation helpers
    bool isValidUsername(const std::string& name) const {
        return !name.empty() && name.length() >= 3 && name.length() <= 20;
    }
    
    bool isValidEmail(const std::string& email) const {
        // Basic email validation
        return email.find('@') != std::string::npos &&
               email.find('.') != std::string::npos;
    }
    
    bool isValidAge(int age) const {
        return age >= 0 && age <= 150;
    }
    
    void recordLogin() {
        auto now = std::chrono::system_clock::now();
        auto timestamp = std::chrono::system_clock::to_time_t(now);
        loginHistory.push_back(std::ctime(&timestamp));
    }
    
public:
    // Constructor with validation
    User(const std::string& username, const std::string& email, int age)
        : active(true) {
        setUsername(username);
        setEmail(email);
        setAge(age);
    }
    
    // Basic getters
    std::string getUsername() const {
        std::lock_guard<std::mutex> lock(mutex);
        return username;
    }
    
    std::string getEmail() const {
        std::lock_guard<std::mutex> lock(mutex);
        return email;
    }
    
    int getAge() const {
        std::lock_guard<std::mutex> lock(mutex);
        return age;
    }
    
    bool isActive() const {
        std::lock_guard<std::mutex> lock(mutex);
        return active;
    }
    
    // Validated setters
    bool setUsername(const std::string& name) {
        if (!isValidUsername(name)) {
            return false;
        }
        std::lock_guard<std::mutex> lock(mutex);
        username = name;
        return true;
    }
    
    bool setEmail(const std::string& newEmail) {
        if (!isValidEmail(newEmail)) {
            return false;
        }
        std::lock_guard<std::mutex> lock(mutex);
        email = newEmail;
        return true;
    }
    
    bool setAge(int newAge) {
        if (!isValidAge(newAge)) {
            return false;
        }
        std::lock_guard<std::mutex> lock(mutex);
        age = newAge;
        return true;
    }
    
    // Computed properties
    bool isAdult() const {
        std::lock_guard<std::mutex> lock(mutex);
        return age >= 18;
    }
    
    std::string getDisplayName() const {
        std::lock_guard<std::mutex> lock(mutex);
        return username + " (" + email + ")";
    }
    
    // State-changing operations
    bool activate() {
        std::lock_guard<std::mutex> lock(mutex);
        if (active) return false;
        active = true;
        return true;
    }
    
    bool deactivate() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!active) return false;
        active = false;
        return true;
    }
    
    // Bulk operations
    bool updateProfile(const std::string& newUsername,
                      const std::string& newEmail,
                      int newAge) {
        if (!isValidUsername(newUsername) ||
            !isValidEmail(newEmail) ||
            !isValidAge(newAge)) {
            return false;
        }
        
        std::lock_guard<std::mutex> lock(mutex);
        username = newUsername;
        email = newEmail;
        age = newAge;
        return true;
    }
    
    // History tracking
    std::vector<std::string> getLoginHistory() const {
        std::lock_guard<std::mutex> lock(mutex);
        return loginHistory;
    }
    
    void login() {
        std::lock_guard<std::mutex> lock(mutex);
        if (active) {
            recordLogin();
        }
    }
};

// Example of property access with inheritance
class AdminUser : public User {
private:
    std::vector<std::string> permissions;
    bool superUser;
    
public:
    AdminUser(const std::string& username,
              const std::string& email,
              int age,
              bool super = false)
        : User(username, email, age), superUser(super) {}
    
    // Additional getters
    bool isSuperUser() const {
        return superUser;
    }
    
    std::vector<std::string> getPermissions() const {
        return permissions;
    }
    
    // Permission management
    bool addPermission(const std::string& permission) {
        if (permission.empty()) return false;
        
        auto it = std::find(permissions.begin(),
                           permissions.end(),
                           permission);
        if (it != permissions.end()) return false;
        
        permissions.push_back(permission);
        return true;
    }
    
    bool removePermission(const std::string& permission) {
        auto it = std::find(permissions.begin(),
                           permissions.end(),
                           permission);
        if (it == permissions.end()) return false;
        
        permissions.erase(it);
        return true;
    }
    
    bool hasPermission(const std::string& permission) const {
        if (superUser) return true;
        
        return std::find(permissions.begin(),
                        permissions.end(),
                        permission) != permissions.end();
    }
    
    // Override computed property
    std::string getDisplayName() const {
        return User::getDisplayName() + 
               (superUser ? " [Super Admin]" : " [Admin]");
    }
};

#endif // PROPERTY_ACCESS_H
