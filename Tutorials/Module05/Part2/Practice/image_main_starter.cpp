#include "Image_starter.h"
#include <iostream>
#include <cassert>
using namespace std;

void testConstructors() {
    cout << "\n1. Testing Constructors" << endl;
    cout << "====================" << endl;
    
    // Test empty image creation
    Image img1(100, 100);  // Default RGB (3 channels)
    assert(img1.getWidth() == 100);
    assert(img1.getHeight() == 100);
    assert(img1.getChannels() == 3);
    cout << "Empty RGB image created successfully" << endl;
    
    // Test grayscale image
    Image img2(50, 50, 1);  // Grayscale (1 channel)
    assert(img2.getWidth() == 50);
    assert(img2.getHeight() == 50);
    assert(img2.getChannels() == 1);
    cout << "Empty grayscale image created successfully" << endl;
    
    // Test copy constructor
    Image img3 = img1;
    assert(img3.getWidth() == img1.getWidth());
    assert(img3.getHeight() == img1.getHeight());
    assert(img3.getChannels() == img1.getChannels());
    cout << "Image copied successfully" << endl;
    
    // Test move constructor
    Image img4 = std::move(img3);
    assert(img4.getWidth() == 100);
    assert(img3.isEmpty());  // Original should be empty after move
    cout << "Image moved successfully" << endl;
}

void testPixelOperations() {
    cout << "\n2. Testing Pixel Operations" << endl;
    cout << "=========================" << endl;
    
    Image img(2, 2, 3);  // Small RGB image for testing
    
    // Test setting pixels
    img.setPixel(0, 0, 0, 255);  // Red
    img.setPixel(0, 0, 1, 0);    // Green
    img.setPixel(0, 0, 2, 0);    // Blue
    cout << "Pixel set successfully" << endl;
    
    // Test getting pixels
    assert(img.getPixel(0, 0, 0) == 255);
    assert(img.getPixel(0, 0, 1) == 0);
    assert(img.getPixel(0, 0, 2) == 0);
    cout << "Pixel values retrieved successfully" << endl;
    
    // Test invalid coordinates
    try {
        img.setPixel(100, 100, 0, 255);
        assert(false && "Should throw exception for invalid coordinates");
    } catch (const out_of_range& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    // Test invalid channel
    try {
        img.getPixel(0, 0, 3);
        assert(false && "Should throw exception for invalid channel");
    } catch (const out_of_range& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void testImageOperations() {
    cout << "\n3. Testing Image Operations" << endl;
    cout << "=========================" << endl;
    
    Image img(3, 2, 1);  // Small grayscale image
    
    // Set some test values
    for (size_t y = 0; y < img.getHeight(); ++y) {
        for (size_t x = 0; x < img.getWidth(); ++x) {
            img.setPixel(x, y, 0, static_cast<uint8_t>(x + y * img.getWidth()));
        }
    }
    
    // Test clear
    img.clear(128);
    assert(img.getPixel(0, 0, 0) == 128);
    cout << "Clear operation successful" << endl;
    
    // Test flip horizontal
    img.setPixel(0, 0, 0, 255);
    img.setPixel(2, 0, 0, 0);
    img.flipHorizontal();
    assert(img.getPixel(0, 0, 0) == 0);
    assert(img.getPixel(2, 0, 0) == 255);
    cout << "Horizontal flip successful" << endl;
    
    // Test flip vertical
    Image img2(2, 3, 1);
    img2.setPixel(0, 0, 0, 255);
    img2.setPixel(0, 2, 0, 0);
    img2.flipVertical();
    assert(img2.getPixel(0, 0, 0) == 0);
    assert(img2.getPixel(0, 2, 0) == 255);
    cout << "Vertical flip successful" << endl;
    
    // Test rotation
    Image img3(2, 3, 1);
    img3.setPixel(0, 0, 0, 255);
    img3.rotate90();
    assert(img3.getWidth() == 3);
    assert(img3.getHeight() == 2);
    cout << "90-degree rotation successful" << endl;
}

void testResizeOperation() {
    cout << "\n4. Testing Resize Operation" << endl;
    cout << "=========================" << endl;
    
    Image img(4, 4, 1);
    img.clear(255);  // White image
    
    // Test upscaling
    img.resize(8, 8);
    assert(img.getWidth() == 8);
    assert(img.getHeight() == 8);
    cout << "Upscale successful" << endl;
    
    // Test downscaling
    img.resize(2, 2);
    assert(img.getWidth() == 2);
    assert(img.getHeight() == 2);
    cout << "Downscale successful" << endl;
    
    // Test invalid dimensions
    try {
        img.resize(0, 5);
        assert(false && "Should throw exception for invalid dimensions");
    } catch (const invalid_argument& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void testFileOperations() {
    cout << "\n5. Testing File Operations" << endl;
    cout << "========================" << endl;
    
    Image img(100, 100, 3);
    
    // Create test pattern
    for (size_t y = 0; y < img.getHeight(); ++y) {
        for (size_t x = 0; x < img.getWidth(); ++x) {
            img.setPixel(x, y, 0, static_cast<uint8_t>(x % 256));  // Red
            img.setPixel(x, y, 1, static_cast<uint8_t>(y % 256));  // Green
            img.setPixel(x, y, 2, 128);                            // Blue
        }
    }
    
    // Test save
    assert(img.save("test.img"));
    cout << "Image saved successfully" << endl;
    
    // Test load
    Image loaded("test.img");
    assert(loaded.getWidth() == img.getWidth());
    assert(loaded.getHeight() == img.getHeight());
    assert(loaded.getChannels() == img.getChannels());
    cout << "Image loaded successfully" << endl;
    
    // Test invalid file operations
    try {
        Image invalid("nonexistent.img");
        assert(false && "Should throw exception for invalid file");
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

int main() {
    cout << "Image Class Tests" << endl;
    cout << "================" << endl;
    
    try {
        testConstructors();
        testPixelOperations();
        testImageOperations();
        testResizeOperation();
        testFileOperations();
        
        cout << "\nAll tests completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
