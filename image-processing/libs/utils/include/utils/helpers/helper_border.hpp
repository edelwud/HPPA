#pragma once

short *addImageBorder(short *sourceImage, size_t height, size_t width) {
    if (height < 1 || width < 1) {
        throw std::runtime_error("invalid array sizes");
    }
    auto borderedHeight = height + 2;
    auto borderedWidth = width + 2;
    auto borderedSize = borderedHeight * borderedWidth;
    auto imageWithBorder = new unsigned char [borderedSize];
    memset(imageWithBorder, 0, borderedSize * sizeof(unsigned char ));
    for (size_t i = 1; i < borderedHeight - 1; ++i) {
        auto srcOffset = (i - 1) * width;
        memcpy(&imageWithBorder[i * borderedWidth + 1], sourceImage + srcOffset, width * sizeof(unsigned char ));
    }
    delete[] sourceImage;
    return imageWithBorder;
}

short *removeImageBorder(short *imageWithBorder, size_t borderedHeight, size_t borderedWidth) {
    if (borderedHeight < 3 || borderedWidth < 3) {
        throw std::runtime_error("invalid array sizes");
    }
    auto height = borderedHeight - 2;
    auto width = borderedWidth - 2;
    auto size = height * width;
    auto imageWithoutBorder = new short[size];
    for (size_t i = 0; i < height; ++i) {
        auto srcOffset = (i + 1) * borderedWidth + 1;
        memcpy(imageWithoutBorder + (i * width), imageWithBorder + srcOffset, width * sizeof(unsigned char ));
    }
    delete[] imageWithBorder;
    return imageWithoutBorder;
}
