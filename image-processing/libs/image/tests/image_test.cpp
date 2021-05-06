#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/laplace-filter.cuh>
#include <image/image-grayscale.cuh>

TEST(image, ExecutionTimeTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 1);

    ImageGrayscale simple(image);

    auto laplaceFilter = new LaplaceFilter();
    simple.setFilter(laplaceFilter);
    simple.applyFilter();

    ASSERT_EQ(simple.getImage().width, 640);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
