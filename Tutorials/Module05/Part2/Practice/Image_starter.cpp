#include "Image_starter.h"
#include <algorithm>
#include <cstring>
#include <fstream>

// TODO: Implement helper methods
size_t Image::getPixelIndex(size_t x, size_t y, size_t channel) const {
    // Calculate the index in the pixel array for the given coordinates
    // Remember to check channel bounds
    // Formula: (y * width + x) * channels + channel
    return 0;  // Replace with your implementation
}

bool Image::isValidCoordinate(size_t x, size_t y) const {
    // Check if x and y are within image dimensions
    return false;  // Replace with your implementation
}

bool Image::isValidChannel(size_t channel) const {
    // Check if channel number is valid
    return false;  // Replace with your implementation
}

// TODO: Implement constructors
Image::Image(size_t w, size_t h, size_t c) {
    // Initialize dimensions
    // Allocate pixel array
    // Handle allocation failure
    // Initialize pixels to 0
}

Image::Image(const std::string& filename) {
    // Initialize members to safe values
    // Call load function
    // Handle loading failure
}

Image::Image(const Image& other) {
    // Copy dimensions
    // Allocate new pixel array
    // Copy pixel data
    // Handle allocation failure
}

Image::Image(Image&& other) noexcept {
    // Transfer ownership of pixel array
    // Copy dimensions
    // Reset source object
}

// TODO: Implement assignment operators
Image& Image::operator=(const Image& other) {
    // Check for self-assignment
    // Free existing resources
    // Copy dimensions
    // Allocate new pixel array
    // Copy pixel data
    // Handle allocation failure
    return *this;
}

Image& Image::operator=(Image&& other) noexcept {
    // Check for self-assignment
    // Free existing resources
    // Transfer ownership of pixel array
    // Copy dimensions
    // Reset source object
    return *this;
}

// TODO: Implement destructor
Image::~Image() {
    // Free pixel array
}

// TODO: Implement pixel operations
uint8_t Image::getPixel(size_t x, size_t y, size_t channel) const {
    // Validate coordinates and channel
    // Calculate pixel index
    // Return pixel value
    return 0;  // Replace with your implementation
}

void Image::setPixel(size_t x, size_t y, size_t channel, uint8_t value) {
    // Validate coordinates and channel
    // Calculate pixel index
    // Set pixel value
}

// TODO: Implement image operations
void Image::clear(uint8_t value) {
    // Fill entire pixel array with given value
}

void Image::flipHorizontal() {
    // Swap pixels across vertical center line
    // Remember to handle all channels
}

void Image::flipVertical() {
    // Swap pixels across horizontal center line
    // Remember to handle all channels
}

void Image::rotate90() {
    // Rotate image 90 degrees clockwise
    // Create new pixel array for rotated image
    // Copy pixels to new array with rotated coordinates
    // Update dimensions and pixel array
}

// TODO: Implement resize operation
void Image::resize(size_t newWidth, size_t newHeight) {
    // Validate new dimensions
    // Create new pixel array
    // Implement simple scaling algorithm
    // Update dimensions and pixel array
    // Handle allocation failure
}

// TODO: Implement file operations
bool Image::save(const std::string& filename) const {
    // Open file for binary writing
    // Write image dimensions
    // Write pixel data
    // Handle file errors
    return false;  // Replace with your implementation
}

bool Image::load(const std::string& filename) {
    // Open file for binary reading
    // Read image dimensions
    // Allocate pixel array
    // Read pixel data
    // Handle file errors and allocation failure
    return false;  // Replace with your implementation
}
