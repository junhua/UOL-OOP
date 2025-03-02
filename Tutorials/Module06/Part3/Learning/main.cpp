#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "PropertyAccess.h"
using namespace std;

// Helper function to display user information
void displayUser(const User& user) {
    cout << "\nUser Information:" << endl;
    cout << "================" << endl;
    cout << "Display Name: " << user.getDisplayName() << endl;
    cout << "Username: " << user.getUsername() << endl;
    cout << "Email: " << user.getEmail() << endl;
    cout << "Age: " << user.getAge() << endl;
    cout << "Status: " << (user.isActive() ? "Active" : "Inactive") << endl;
    cout << "Adult: " << (user.isAdult() ? "Yes" : "No") << endl;
}

// Helper function to display admin information
void displayAdmin(const AdminUser& admin) {
    displayUser(admin);
    cout << "Super User: " << (admin.isSuperUser() ? "Yes" : "No") << endl;
    
    cout << "Permissions: ";
    auto perms = admin.getPermissions();
    if (perms.empty()) {
        cout << "None" << endl;
    } else {
        cout << endl;
        for (const auto& perm : perms) {
            cout << "- " << perm << endl;
        }
    }
}

// Simulate concurrent access
void simulateConcurrentAccess(User& user) {
    // Thread 1: Update profile
    thread t1([&user]() {
        for (int i = 0; i < 3; i++) {
            user.setUsername("user" + to_string(i));
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });
    
    // Thread 2: Read profile
    thread t2([&user]() {
        for (int i = 0; i < 3; i++) {
            cout << "Current user: " << user.getUsername() << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });
    
    t1.join();
    t2.join();
}

int main() {
    cout << "Property Access Example" << endl;
    cout << "=====================" << endl;
    
    // Demonstrate poor property access
    cout << "\nPoor Property Access Example:" << endl;
    cout << "-------------------------" << endl;
    
    UserPoor poorUser;
    poorUser.username = "";  // Invalid, but no validation
    poorUser.email = "invalid";  // Invalid email format
    poorUser.age = -5;  // Invalid age
    poorUser.active = true;
    
    poorUser.printInfo();
    cout << "Problems with poor access:" << endl;
    cout << "1. No validation of data" << endl;
    cout << "2. No encapsulation" << endl;
    cout << "3. No thread safety" << endl;
    cout << "4. No state consistency" << endl;
    
    // Demonstrate good property access
    cout << "\nGood Property Access Example:" << endl;
    cout << "-------------------------" << endl;
    
    User user("johndoe", "john@example.com", 25);
    
    cout << "1. Initial state:" << endl;
    displayUser(user);
    
    // Demonstrate validation
    cout << "\n2. Validation in action:" << endl;
    
    if (!user.setUsername("")) {
        cout << "Prevented empty username" << endl;
    }
    
    if (!user.setEmail("invalid")) {
        cout << "Prevented invalid email" << endl;
    }
    
    if (!user.setAge(-5)) {
        cout << "Prevented invalid age" << endl;
    }
    
    if (user.setUsername("janedoe") &&
        user.setEmail("jane@example.com") &&
        user.setAge(30)) {
        cout << "Valid updates successful" << endl;
    }
    
    // Show updated state
    cout << "\n3. After valid changes:" << endl;
    displayUser(user);
    
    // Demonstrate bulk operations
    cout << "\n4. Bulk update:" << endl;
    if (user.updateProfile("alice", "alice@example.com", 22)) {
        cout << "Bulk update successful" << endl;
        displayUser(user);
    }
    
    // Demonstrate state management
    cout << "\n5. State management:" << endl;
    user.login();
    user.login();
    cout << "Login history:" << endl;
    for (const auto& entry : user.getLoginHistory()) {
        cout << entry;
    }
    
    // Demonstrate thread safety
    cout << "\n6. Thread safety demonstration:" << endl;
    simulateConcurrentAccess(user);
    
    // Demonstrate inheritance and polymorphism
    cout << "\nAdmin User Example:" << endl;
    cout << "=================" << endl;
    
    AdminUser admin("admin", "admin@example.com", 35, true);
    
    cout << "1. Initial admin state:" << endl;
    displayAdmin(admin);
    
    // Demonstrate permission management
    cout << "\n2. Permission management:" << endl;
    admin.addPermission("users.manage");
    admin.addPermission("system.config");
    admin.addPermission("users.manage");  // Duplicate
    
    cout << "\nUpdated permissions:" << endl;
    displayAdmin(admin);
    
    cout << "\nPermission checks:" << endl;
    cout << "Has users.manage: " 
         << (admin.hasPermission("users.manage") ? "Yes" : "No") << endl;
    cout << "Has unknown.perm: " 
         << (admin.hasPermission("unknown.perm") ? "Yes" : "No") << endl;
    
    // Remove permission
    admin.removePermission("users.manage");
    cout << "\nAfter removing users.manage:" << endl;
    displayAdmin(admin);
    
    cout << "\nKey Benefits of Good Property Access:" << endl;
    cout << "1. Data validation enforced" << endl;
    cout << "2. Thread safety guaranteed" << endl;
    cout << "3. State consistency maintained" << endl;
    cout << "4. Clear interface provided" << endl;
    cout << "5. Implementation details hidden" << endl;
    cout << "6. Inheritance properly supported" << endl;
    
    return 0;
}
