#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <iostream>
#include <vector>

// TODO: Implement the Protocol base class
class Protocol {
public:
    // TODO: Add public members:
    // - Constructor(name, version)
    // - connect(): Establish connection
    // - disconnect(): Close connection
    // - send(data): Send data
    // - receive(): Receive data
    // - getName(): Return protocol name
    
protected:
    // TODO: Add protected members:
    // - name (string)
    // - version (string)
    // - isConnected (bool)
    // - buffer (vector<char>)
    // - validateData(): Check data format
    // - handleError(): Process errors
    
private:
    // TODO: Add private members:
    // - initializeConnection(): Setup
    // - cleanupConnection(): Teardown
    // - logActivity(): Record events
};

// TODO: Implement TCP with public inheritance
class TCP {
    // TODO: Add members:
    // - port (int)
    // - windowSize (int)
    // - retryCount (int)
    // Override connect() with handshake
    // Override send() with reliability
};

// TODO: Implement Internal with protected inheritance
class Internal {
    // TODO: Add members:
    // - domain (string)
    // - priority (int)
    // - isSecure (bool)
    // Override send() with routing
    // Add security methods
};

// TODO: Implement Hardware with private inheritance
class Hardware {
    // TODO: Add members:
    // - deviceType (string)
    // - baudRate (int)
    // - parity (char)
    // Selectively expose protocol
    // Add hardware control
};

#endif // PROTOCOL_H
