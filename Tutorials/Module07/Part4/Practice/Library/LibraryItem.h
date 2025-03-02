#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>
#include <iostream>

// TODO: Implement the LibraryItem base class
class LibraryItem {
public:
    // TODO: Add public members:
    // - Constructor(id, title, author)
    // - checkOut(): Mark item as checked out
    // - returnItem(): Mark item as returned
    // - displayInfo(): Show item details
    // - getId(): Return item ID
    
protected:
    // TODO: Add protected members:
    // - id (string)
    // - title (string)
    // - author (string)
    // - isCheckedOut (bool)
    // - updateStatus(): Update checkout status
    
private:
    // TODO: Add private members:
    // - logAction(): Record item actions
    // - validateId(): Check ID format
};

// TODO: Implement Book with public inheritance
class Book {
    // TODO: Add members:
    // - isbn (string)
    // - genre (string)
    // - pageCount (int)
    // Override displayInfo()
};

// TODO: Implement Reference with protected inheritance
class Reference {
    // TODO: Add members:
    // - subject (string)
    // - level (string)
    // - canCheckOut (bool)
    // Override checkOut() with restrictions
};

// TODO: Implement Internal with private inheritance
class Internal {
    // TODO: Add members:
    // - department (string)
    // - clearanceLevel (int)
    // - expiryDate (string)
    // Selectively expose functionality
};

#endif // LIBRARY_ITEM_H
