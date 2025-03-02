#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <string>
#include <vector>
#include <stdexcept>

class DatabaseConnection {
private:
    std::string host;
    std::string username;
    std::string password;
    bool connected;
    void* connection;  // Simulated database handle
    std::vector<std::string> queryLog;
    
    // TODO: Add any additional helper methods you need
    
public:
    // TODO: Implement constructors
    DatabaseConnection(const std::string& host, 
                      const std::string& user, 
                      const std::string& pass);
    
    // TODO: Implement copy constructor
    DatabaseConnection(const DatabaseConnection& other) = delete;
    
    // TODO: Implement move constructor
    DatabaseConnection(DatabaseConnection&& other) noexcept;
    
    // TODO: Implement assignment operators
    DatabaseConnection& operator=(const DatabaseConnection& other) = delete;
    DatabaseConnection& operator=(DatabaseConnection&& other) noexcept;
    
    // TODO: Implement destructor
    ~DatabaseConnection();
    
    // Connection operations
    bool connect();
    void disconnect();
    bool isConnected() const { return connected; }
    
    // Query operations
    bool executeQuery(const std::string& query);
    std::vector<std::string> getQueryLog() const { return queryLog; }
    
    // Connection info
    std::string getHost() const { return host; }
    std::string getUsername() const { return username; }
    
    // TODO: Implement reconnection logic
    bool reconnect();
    
    // TODO: Implement transaction support
    bool beginTransaction();
    bool commitTransaction();
    bool rollbackTransaction();
};

#endif // DATABASE_CONNECTION_H
