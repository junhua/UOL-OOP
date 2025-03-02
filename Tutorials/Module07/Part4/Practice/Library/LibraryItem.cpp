#include "LibraryItem.h"

// TODO: Implement LibraryItem constructor
// Parameters:
// - id: Item identifier
// - title: Item title
// - author: Item author
// Expected behavior:
// 1. Initialize all members
// 2. Set isCheckedOut to false
// 3. Validate ID format
// 4. Log creation action

// TODO: Implement LibraryItem::checkOut()
// Expected behavior:
// 1. Check if already checked out
// 2. Update status if available
// 3. Log checkout action
// 4. Return success/failure

// TODO: Implement LibraryItem::returnItem()
// Expected behavior:
// 1. Check if currently checked out
// 2. Update status
// 3. Log return action
// 4. Return success/failure

// TODO: Implement LibraryItem::displayInfo()
// Expected output format:
// Item Information:
// ================
// ID: [id]
// Title: [title]
// Author: [author]
// Status: [Checked Out/Available]

// TODO: Implement Book constructor
// Remember:
// 1. Call LibraryItem constructor
// 2. Initialize Book-specific members
// 3. Log book creation

// TODO: Implement Book::displayInfo()
// Remember:
// 1. Call base class displayInfo()
// 2. Add Book-specific info:
//    ISBN: [isbn]
//    Genre: [genre]
//    Pages: [pageCount]

// TODO: Implement Reference constructor
// Remember:
// 1. Call LibraryItem constructor
// 2. Initialize Reference-specific members
// 3. Set canCheckOut based on level

// TODO: Implement Reference::checkOut()
// Remember:
// 1. Check canCheckOut flag
// 2. Only allow checkout for certain levels
// 3. Call base class method if allowed
// 4. Log restriction if denied

// TODO: Implement Internal constructor
// Remember:
// 1. Call LibraryItem constructor
// 2. Initialize Internal-specific members
// 3. Set clearance requirements

// TODO: Implement Internal access methods
// Remember:
// 1. Selectively expose base functionality
// 2. Add clearance level checks
// 3. Log all access attempts
