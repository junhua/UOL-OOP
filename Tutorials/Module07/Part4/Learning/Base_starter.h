#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

// TODO: Implement the Base class with different access levels
class Base {
public:
    // TODO: Add public members:
    // - Constructor taking name parameter
    // - publicMethod(): Prints "[name]: Public method"
    // - getName(): Returns name
    
protected:
    // TODO: Add protected members:
    // - name (string)
    // - protectedMethod(): Prints "[name]: Protected method"
    // - getNameProtected(): Returns name
    
private:
    // TODO: Add private members:
    // - privateMethod(): Prints "[name]: Private method"
    // - privateHelper(): Internal functionality
    
    // Note: Private members are not accessible in derived classes
    // They provide internal implementation details
};

// TODO: Implement PublicDerived with public inheritance
class PublicDerived {
public:
    // TODO: Add constructor
    // - Call Base constructor with "PublicDerived"
    // - Print "Public inheritance example"
    
    // TODO: Add testAccess() method to demonstrate:
    // - Calling public methods (OK)
    // - Calling protected methods (OK)
    // - Attempting private methods (Error)
    // - Using protected members
};

// TODO: Implement ProtectedDerived with protected inheritance
class ProtectedDerived {
public:
    // TODO: Add constructor
    // - Call Base constructor with "ProtectedDerived"
    // - Print "Protected inheritance example"
    
    // TODO: Add accessBaseMethod() to demonstrate:
    // - Calling public methods (now protected)
    // - Calling protected methods (still protected)
    // - Using inherited protected members
};

// TODO: Implement PrivateDerived with private inheritance
class PrivateDerived {
public:
    // TODO: Add constructor
    // - Call Base constructor with "PrivateDerived"
    // - Print "Private inheritance example"
    
    // TODO: Add accessBaseMethod() to demonstrate:
    // - Calling public methods (now private)
    // - Calling protected methods (now private)
    // - Selectively exposing functionality
};

#endif // BASE_H
