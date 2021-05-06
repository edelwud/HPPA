#include <gtest/gtest.h>

#include <loader/loader.hpp>

TEST(loader, LoadingImageTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);
    ASSERT_EQ(image.width, 640);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
