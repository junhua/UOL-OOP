#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <stdexcept>
#include <memory>

class Image {
private:
    uint8_t* pixels;
    size_t width;
    size_t height;
    size_t channels;  // Usually 1 for grayscale, 3 for RGB, 4 for RGBA
    
    // TODO: Add helper methods for pixel access and validation
    size_t getPixelIndex(size_t x, size_t y, size_t channel) const;
    bool isValidCoordinate(size_t x, size_t y) const;
    bool isValidChannel(size_t channel) const;
    
public:
    // TODO: Implement constructors
    Image(size_t w, size_t h, size_t c = 3);  // Create empty image
    Image(const std::string& filename);        // Load from file
    Image(const Image& other);                 // Copy constructor
    Image(Image&& other) noexcept;            // Move constructor
    
    // TODO: Implement assignment operators
    Image& operator=(const Image& other);
    Image& operator=(Image&& other) noexcept;
    
    // TODO: Implement destructor
    ~Image();
    
    // Accessors
    size_t getWidth() const { return width; }
    size_t getHeight() const { return height; }
    size_t getChannels() const { return channels; }
    
    // TODO: Implement pixel operations
    uint8_t getPixel(size_t x, size_t y, size_t channel) const;
    void setPixel(size_t x, size_t y, size_t channel, uint8_t value);
    
    // TODO: Implement image operations
    void clear(uint8_t value = 0);
    void flipHorizontal();
    void flipVertical();
    void rotate90();
    
    // TODO: Implement resize operation
    void resize(size_t newWidth, size_t newHeight);
    
    // TODO: Implement file operations
    bool save(const std::string& filename) const;
    bool load(const std::string& filename);
    
    // TODO: Implement utility methods
    bool isEmpty() const { return pixels == nullptr; }
    size_t getSize() const { return width * height * channels; }
    const uint8_t* getData() const { return pixels; }
};

#endif // IMAGE_H
