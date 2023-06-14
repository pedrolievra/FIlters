#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>

Image::Image() : width(0), height(0) {}

void Image::loadPPM(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string format;
    file >> format;
    if (format != "P3")
    {
        std::cerr << "Invalid PPM format. Only P3 format is supported." << std::endl;
        return;
    }

    file >> width >> height;
    int maxValue;
    file >> maxValue;

    if (maxValue != 255)
    {
        std::cerr << "Invalid maximum value. Only 8-bit images are supported." << std::endl;
        return;
    }

    pixels.resize(width * height);

    // Read pixel data
    for (Pixel &pixel : pixels)
    {
        int red, green, blue;
        file >> red >> green >> blue;
        pixel.red = static_cast<unsigned char>(red);
        pixel.green = static_cast<unsigned char>(green);
        pixel.blue = static_cast<unsigned char>(blue);
    }

    file.close();
}

void Image::savePPM(const std::string &filename) const
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    file << "P3\n";
    file << width << " " << height << "\n";
    file << "255\n";

    // Write pixel data
    int count = 0;
    for (const Pixel &pixel : pixels)
    {
        file << static_cast<int>(pixel.red) << " " << static_cast<int>(pixel.green) << " " << static_cast<int>(pixel.blue) << " ";
        count++;
        if (count >= 5)
        {
            file << "\n";
            count = 0;
        }
    }

    file.close();
}

// std::vector<Pixel>& getPixels();
std::vector<Pixel> &Image::getPixels()
{
    return pixels;
}
