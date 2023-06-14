#include "Image.h"
#include "Filters.h"

int main() {
    Image image;
    image.loadPPM("image/lena.ppm");

    // Apply the desired operations on the image
    invertColors(image);
    image.savePPM("lenaInverted.ppm");

    Image image2;
    image2.loadPPM("image/lena.ppm");
    applyGrayscaleFilter(image2);
    image2.savePPM("lenaGrayscale.ppm");

    Image image3;
    image3.loadPPM("image/lena.ppm");
    applySepiaFilter(image3);
    image3.savePPM("lenaSepia.ppm");

    return 0;
}