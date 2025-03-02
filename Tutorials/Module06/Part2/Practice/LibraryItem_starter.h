#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <vector>
#include <ctime>

// TODO: Implement LibraryItem base class
// - Track item details and status
// - Manage borrowing operations
class LibraryItem {
private:
    // TODO: Add private member variables
    // - Item ID
    // - Title
    // - Status (available/borrowed)
    // - Due date
    // - Borrowing history
    
protected:
    // TODO: Add protected helper functions
    // - Format due date
    // - Check availability
    // - Update history
    
public:
    // TODO: Implement public interface
    // - Constructor
    // - Borrow/return operations
    // - Status queries
    // - History access
};

// TODO: Implement Book class
// - Inherit from LibraryItem
// - Add book-specific features
class Book {
private:
    // TODO: Add private member variables
    // - Author
    // - ISBN
    // - Page count
    // - Genre
    
protected:
    // TODO: Add protected helpers
    // - Validate ISBN
    // - Format book info
    
public:
    // TODO: Implement public interface
    // - Constructor
    // - Book-specific operations
    // - Information access
};

// TODO: Implement Magazine class
// - Inherit from LibraryItem
// - Add magazine-specific features
class Magazine {
private:
    // TODO: Add private member variables
    // - Issue number
    // - Publication date
    // - Publisher
    // - Category
    
protected:
    // TODO: Add protected helpers
    // - Format issue info
    // - Validate dates
    
public:
    // TODO: Implement public interface
    // - Constructor
    // - Magazine-specific operations
    // - Information access
};

// TODO: Implement DVD class
// - Inherit from LibraryItem
// - Add DVD-specific features
class DVD {
private:
    // TODO: Add private member variables
    // - Director
    // - Duration
    // - Rating
    // - Genre
    
protected:
    // TODO: Add protected helpers
    // - Format duration
    // - Validate rating
    
public:
    // TODO: Implement public interface
    // - Constructor
    // - DVD-specific operations
    // - Information access
};

// TODO: Implement Library class
// - Manage collection of items
// - Handle member operations
class Library {
private:
    // TODO: Add private member variables
    // - Item collection
    // - Member records
    // - Transaction log
    
protected:
    // TODO: Add protected helpers
    // - Find items
    // - Validate members
    // - Update records
    
public:
    // TODO: Implement public interface
    // - Add/remove items
    // - Member operations
    // - Search functionality
};

#endif // LIBRARYITEM_H
