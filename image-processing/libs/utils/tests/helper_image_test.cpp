#include <gtest/gtest.h>
#include <iomanip>

#include <utils/helpers/helper_border.hpp>

TEST(helper_image, AddImageBorderTest) {
    int height = 4;
    int width = 4;
    auto sourceImageArray = new unsigned char [height * width]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    auto actualArray = addImageBorder(sourceImageArray, height, width);
    for (int i = 0; i < height + 2; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < width + 2; ++j) {
            std::cout << std::setw(2) << 0+actualArray[i * (width + 2) + j] << " ";
        }
        std::cout << " ]" << std::endl;
    }
}

TEST(helper_image, RemoveImageBorderTest) {
    int borderedHeight = 6;
    int borderedWidth = 6;
    auto sourceImageArray = new unsigned char [borderedHeight * borderedWidth]{0, 0, 0, 0, 0, 0,
                                                                      0, 1, 2, 3, 4, 0,
                                                                      0, 5, 6, 7, 8, 0,
                                                                      0, 9, 10, 11, 12, 0,
                                                                      0, 13, 14, 15, 16, 0,
                                                                      0, 0, 0, 0, 0, 0};
    auto actualArray = removeImageBorder(sourceImageArray, borderedHeight, borderedWidth);
    for (int i = 0; i < borderedHeight - 2; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < borderedWidth - 2; ++j) {
            std::cout << std::setw(2) << 0+actualArray[i * (borderedWidth - 2) + j] << " ";
        }
        std::cout << " ]" << std::endl;
    }
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
