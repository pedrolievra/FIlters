#include "Image.h"
#include <iostream>

using namespace std;

void applySepiaFilter(Image& image) {
    std::vector<Pixel>& pixels = image.getPixels();
    for (Pixel& pixel : pixels) {
        unsigned char originalRed = pixel.red;
        unsigned char originalGreen = pixel.green;
        unsigned char originalBlue = pixel.blue;

        
        pixel.red = static_cast<unsigned char>(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
        pixel.green = static_cast<unsigned char>(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
        pixel.blue = static_cast<unsigned char>(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
    }
}

void applyGrayscaleFilter(Image& image) {
    std::vector<Pixel>& pixels = image.getPixels();
    for (Pixel& pixel : pixels) {
        unsigned char originalRed = pixel.red;
        unsigned char originalGreen = pixel.green;
        unsigned char originalBlue = pixel.blue;

        unsigned char grayscaleValue = static_cast<unsigned char>((originalRed + originalGreen + originalBlue) / 3);

        pixel.red = grayscaleValue;
        pixel.green = grayscaleValue;
        pixel.blue = grayscaleValue;
    }
}

void invertColors(Image& image) {
    std::vector<Pixel>& pixels = image.getPixels();
    for (Pixel& pixel : pixels) {
        pixel.red = 255 - pixel.red;
        pixel.green = 255 - pixel.green;
        pixel.blue = 255 - pixel.blue;
    }
}
