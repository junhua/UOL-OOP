#include "DatabaseConnection_starter.h"
#include <iostream>
#include <cassert>
using namespace std;

void testBasicOperations() {
    cout << "\n1. Testing Basic Operations" << endl;
    cout << "=========================" << endl;
    
    // Create connection
    DatabaseConnection db("localhost", "user", "pass");
    assert(!db.isConnected() && "Should not be connected initially");
    cout << "Connection created successfully" << endl;
    
    // Test connection
    bool connected = db.connect();
    assert(connected && "Should connect successfully");
    assert(db.isConnected() && "Should be connected");
    cout << "Connected successfully" << endl;
    
    // Test query execution
    bool queryResult = db.executeQuery("SELECT * FROM users");
    assert(queryResult && "Query should execute successfully");
    cout << "Query executed successfully" << endl;
    
    // Check query log
    auto log = db.getQueryLog();
    assert(!log.empty() && "Query log should not be empty");
    cout << "Query logged successfully" << endl;
    
    // Test disconnection
    db.disconnect();
    assert(!db.isConnected() && "Should be disconnected");
    cout << "Disconnected successfully" << endl;
}

void testMoveSemantics() {
    cout << "\n2. Testing Move Semantics" << endl;
    cout << "=======================" << endl;
    
    // Create and connect first database
    DatabaseConnection db1("host1", "user1", "pass1");
    db1.connect();
    db1.executeQuery("SELECT 1");
    cout << "First connection established" << endl;
    
    // Move construction
    DatabaseConnection db2(std::move(db1));
    assert(db2.isConnected() && "db2 should be connected");
    assert(!db1.isConnected() && "db1 should be disconnected");
    cout << "Move construction successful" << endl;
    
    // Test moved connection
    bool queryResult = db2.executeQuery("SELECT 2");
    assert(queryResult && "Query should work on moved connection");
    cout << "Query on moved connection successful" << endl;
    
    // Move assignment
    DatabaseConnection db3("host3", "user3", "pass3");
    db3 = std::move(db2);
    assert(db3.isConnected() && "db3 should be connected");
    assert(!db2.isConnected() && "db2 should be disconnected");
    cout << "Move assignment successful" << endl;
}

void testErrorHandling() {
    cout << "\n3. Testing Error Handling" << endl;
    cout << "========================" << endl;
    
    DatabaseConnection db("invalid_host", "user", "pass");
    
    // Test connection failure
    try {
        db.connect();
        cout << "Connection status: " << (db.isConnected() ? "Connected" : "Disconnected") << endl;
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    // Test query on disconnected database
    try {
        db.executeQuery("SELECT 1");
        assert(false && "Should not execute query when disconnected");
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void testReconnection() {
    cout << "\n4. Testing Reconnection" << endl;
    cout << "======================" << endl;
    
    DatabaseConnection db("localhost", "user", "pass");
    db.connect();
    cout << "Initial connection established" << endl;
    
    // Simulate connection loss and reconnection
    db.disconnect();
    cout << "Connection lost" << endl;
    
    bool reconnected = db.reconnect();
    assert(reconnected && "Should reconnect successfully");
    assert(db.isConnected() && "Should be connected after reconnect");
    cout << "Reconnection successful" << endl;
    
    // Test query after reconnection
    bool queryResult = db.executeQuery("SELECT 1");
    assert(queryResult && "Query should work after reconnection");
    cout << "Query after reconnection successful" << endl;
}

void testTransactions() {
    cout << "\n5. Testing Transactions" << endl;
    cout << "======================" << endl;
    
    DatabaseConnection db("localhost", "user", "pass");
    db.connect();
    
    // Test successful transaction
    assert(db.beginTransaction() && "Should begin transaction");
    cout << "Transaction begun" << endl;
    
    bool queryResult = db.executeQuery("INSERT INTO users VALUES (1, 'test')");
    assert(queryResult && "Query in transaction should succeed");
    cout << "Query in transaction executed" << endl;
    
    assert(db.commitTransaction() && "Should commit transaction");
    cout << "Transaction committed" << endl;
    
    // Test transaction rollback
    assert(db.beginTransaction() && "Should begin second transaction");
    db.executeQuery("INSERT INTO users VALUES (2, 'test2')");
    assert(db.rollbackTransaction() && "Should rollback transaction");
    cout << "Transaction rollback successful" << endl;
}

int main() {
    cout << "Database Connection Tests" << endl;
    cout << "========================" << endl;
    
    try {
        testBasicOperations();
        testMoveSemantics();
        testErrorHandling();
        testReconnection();
        testTransactions();
        
        cout << "\nAll tests completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
