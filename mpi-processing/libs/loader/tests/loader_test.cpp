#include <gtest/gtest.h>

#include <loader/loader.hpp>

TEST(loader, LoadingColorImageTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);
    ASSERT_EQ(image.width, 640);
}

TEST(loader, LoadingGrayscaleImageTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);
    ASSERT_EQ(image.width, 5184);
}

TEST(loader, SavingGrayscaleImageTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);
    Loader::saveImage(image, LOADER_ASSETS_PATH + "sample_saved.pgm", 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


