#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image {
private:
    int width;
    int height;
    std::vector<Pixel> pixels;

public:
    Image();
    void loadPPM(const std::string& filename);
    void savePPM(const std::string& filename) const;
    std::vector<Pixel>& getPixels();  
};

#endif  // IMAGE_H
