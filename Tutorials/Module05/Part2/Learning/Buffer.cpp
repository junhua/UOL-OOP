#include "Buffer.h"
#include <iostream>

void Buffer::copyFrom(const Buffer& other) {
    try {
        data = new int[other.size];
        size = other.size;
        std::copy(other.data, other.data + size, data);
    } catch (const std::bad_alloc& e) {
        throw std::runtime_error("Memory allocation failed in copyFrom");
    }
}

Buffer::Buffer(size_t n) : size(n) {
    try {
        data = new int[size]();  // Zero-initialize
    } catch (const std::bad_alloc& e) {
        throw std::runtime_error("Memory allocation failed in constructor");
    }
    std::cout << "Size constructor called with size " << size << std::endl;
}

Buffer::Buffer(const int* values, size_t n) : size(n) {
    try {
        data = new int[size];
        std::copy(values, values + size, data);
    } catch (const std::bad_alloc& e) {
        throw std::runtime_error("Memory allocation failed in data constructor");
    }
    std::cout << "Data constructor called with size " << size << std::endl;
}

Buffer::Buffer(const Buffer& other) {
    copyFrom(other);
    std::cout << "Copy constructor called" << std::endl;
}

Buffer::Buffer(Buffer&& other) noexcept
    : size(other.size), data(other.data) {
    other.size = 0;
    other.data = nullptr;
    std::cout << "Move constructor called" << std::endl;
}

Buffer& Buffer::operator=(const Buffer& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        Buffer temp(other);  // Copy-and-swap idiom
        swap(temp);
    }
    return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    std::cout << "Move assignment operator called" << std::endl;
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

Buffer::~Buffer() {
    delete[] data;
    std::cout << "Destructor called for buffer of size " << size << std::endl;
}

int Buffer::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Buffer index out of range");
    }
    return data[index];
}

void Buffer::set(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Buffer index out of range");
    }
    data[index] = value;
}

void Buffer::fill(int value) {
    std::fill(data, data + size, value);
}

void Buffer::resize(size_t newSize) {
    if (newSize == size) return;
    
    int* newData = nullptr;
    try {
        if (newSize > 0) {
            newData = new int[newSize]();
            std::copy(data, data + std::min(size, newSize), newData);
        }
    } catch (const std::bad_alloc& e) {
        delete[] newData;  // Clean up if allocation fails
        throw std::runtime_error("Memory allocation failed in resize");
    }
    
    delete[] data;
    data = newData;
    size = newSize;
}

void Buffer::swap(Buffer& other) noexcept {
    std::swap(data, other.data);
    std::swap(size, other.size);
}

void Buffer::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

std::ostream& operator<<(std::ostream& os, const Buffer& buffer) {
    os << "Buffer[" << buffer.size << "]: ";
    if (buffer.data) {
        for (size_t i = 0; i < buffer.size; ++i) {
            if (i > 0) os << ", ";
            os << buffer.data[i];
        }
    } else {
        os << "empty";
    }
    return os;
}
