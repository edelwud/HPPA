#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/laplace-filter.hpp>
#include <image/image-grayscale.hpp>

//TEST(image, ExecutionTimeTest) {
//    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 1);
//
//    ImageGrayscale simple(image);
//
//    auto laplaceFilter = new LaplaceFilter();
//    simple.setFilter(laplaceFilter);
//    simple.applyFilter();
//
//    ASSERT_EQ(simple.getImage().width, 640);
//}

TEST(image, FilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(image);

    auto kekw = simple.getImage().data;
    for (int i = 0; i < 128*128; i++)
        std::cout << kekw[i] << ' ';
    std::cout << std::endl;

    simple.setFilter(laplaceFilter);
    simple.applyFilter();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
