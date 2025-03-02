# Library Management System Practice Exercise

This exercise focuses on implementing access control in a library management system using C++. You'll practice using public, private, and protected access specifiers while building a system to manage different types of library items.

## Learning Objectives
- Understand and apply access control concepts
- Practice inheritance with access specifiers
- Implement data hiding and encapsulation
- Design class hierarchies with proper access levels

## Requirements

### LibraryItem Base Class
1. Private members:
   - Item ID (read-only)
   - Title
   - Status (available/borrowed)
   - Due date
   - Borrowing history

2. Protected members:
   - Helper functions for derived classes
   - Status checking utilities
   - History management functions

3. Public interface:
   - Constructor with ID and title
   - Borrow/return operations
   - Status queries
   - History access methods

### Book Class (Derived from LibraryItem)
1. Private members:
   - Author
   - ISBN
   - Page count
   - Genre

2. Protected members:
   - ISBN validation
   - Book information formatting

3. Public interface:
   - Constructor with book details
   - Book-specific operations
   - Override base class methods as needed

### Magazine Class (Derived from LibraryItem)
1. Private members:
   - Issue number
   - Publication date
   - Publisher
   - Category

2. Protected members:
   - Date validation
   - Issue information formatting

3. Public interface:
   - Constructor with magazine details
   - Magazine-specific operations
   - Override base class methods as needed

### DVD Class (Derived from LibraryItem)
1. Private members:
   - Director
   - Duration
   - Rating
   - Genre

2. Protected members:
   - Duration formatting
   - Rating validation

3. Public interface:
   - Constructor with DVD details
   - DVD-specific operations
   - Override base class methods as needed

### Library Class
1. Private members:
   - Collection of items
   - Member records
   - Transaction log

2. Protected members:
   - Search helpers
   - Validation utilities
   - Record management functions

3. Public interface:
   - Add/remove items
   - Member operations
   - Search functionality

## Implementation Steps

1. Start with LibraryItem_starter.h:
   - Define class structures
   - Declare member variables
   - Specify access levels

2. Implement in LibraryItem_starter.cpp:
   - Define constructors
   - Implement member functions
   - Add validation logic

3. Complete library_test.cpp:
   - Test all class functionality
   - Verify access controls
   - Check inheritance behavior

## Testing Requirements

1. Basic Operations:
   - Create items of each type
   - Test borrowing/returning
   - Verify history tracking

2. Access Control:
   - Verify private member protection
   - Test protected member inheritance
   - Check public interface accessibility

3. Error Handling:
   - Test invalid operations
   - Verify input validation
   - Check boundary conditions

4. Inheritance:
   - Test base class functionality
   - Verify derived class features
   - Check access level inheritance

## Evaluation Criteria

1. Proper Access Control:
   - Correct use of public/private/protected
   - Appropriate data hiding
   - Proper inheritance implementation

2. Code Organization:
   - Clear class structure
   - Well-organized member functions
   - Logical inheritance hierarchy

3. Functionality:
   - All operations work correctly
   - Proper error handling
   - Accurate record keeping

4. Testing:
   - Comprehensive test cases
   - Access control verification
   - Error condition handling

## Tips
- Think carefully about which members should be private vs protected
- Use protected for functions needed by derived classes
- Keep the public interface minimal and focused
- Implement proper validation in all operations
- Document your access control decisions
