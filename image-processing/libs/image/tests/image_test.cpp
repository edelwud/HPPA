#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/embossing-filter.cuh>
#include <filters/kekw-filter.cuh>
#include <filters/laplace-filter.cuh>
#include <image/image-grayscale.hpp>
#include <image/image-grayscale-cpu.hpp>

TEST(image, EmbossingFilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(image);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_embossing.pgm", 1);
}


TEST(image, LaplaceFilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(image);

    simple.setFilter(laplaceFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_laplace.pgm", 1);
}

TEST(image, EmbossingFilteringCpuTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simple(image);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_embossing_cpu.pgm", 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
