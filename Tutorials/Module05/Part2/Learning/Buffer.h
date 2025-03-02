#ifndef BUFFER_H
#define BUFFER_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>

class Buffer {
private:
    size_t size;
    int* data;
    
    // Helper method for deep copy
    void copyFrom(const Buffer& other);
    
public:
    // Constructor with size
    explicit Buffer(size_t n);
    
    // Constructor with data
    Buffer(const int* values, size_t n);
    
    // Copy constructor
    Buffer(const Buffer& other);
    
    // Move constructor
    Buffer(Buffer&& other) noexcept;
    
    // Copy assignment operator
    Buffer& operator=(const Buffer& other);
    
    // Move assignment operator
    Buffer& operator=(Buffer&& other) noexcept;
    
    // Destructor
    ~Buffer();
    
    // Accessors
    size_t getSize() const { return size; }
    
    int get(size_t index) const;
    void set(size_t index, int value);
    
    // Buffer operations
    void fill(int value);
    void resize(size_t newSize);
    void swap(Buffer& other) noexcept;
    
    // Utility methods
    bool isEmpty() const { return size == 0; }
    void clear();
    
    // Friend function for printing
    friend std::ostream& operator<<(std::ostream& os, const Buffer& buffer);
};

#endif // BUFFER_H
