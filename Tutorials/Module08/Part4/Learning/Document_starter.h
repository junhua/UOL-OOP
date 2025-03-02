#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>

// Forward declarations
class Author;
class Formatter;

// TODO: Create a Document class that demonstrates "has-a" relationships
// This class should include:
// - Private members for title, content, and creationDate
// - A "has-a" relationship with Author (composition)
// - A "has-a" relationship with Formatter (aggregation)
// - Methods for displaying, formatting, and modifying the document

class Document {
    // Your implementation here
};

// TODO: Create an Author class to demonstrate composition relationship
// The Document "has-a" Author (strong ownership)
class Author {
    // Your implementation here
};

// TODO: Create a Formatter class to demonstrate aggregation relationship
// The Document "has-a" Formatter (weak ownership)
class Formatter {
    // Your implementation here
};

#endif // DOCUMENT_H
