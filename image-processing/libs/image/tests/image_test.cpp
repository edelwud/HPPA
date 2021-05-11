#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/embossing-filter.cuh>
#include <filters/kekw-filter.cuh>
#include <filters/laplace-filter.cuh>
#include <image/image-grayscale-cpu.hpp>
#include <image/image-grayscale.hpp>

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

TEST(image, LaplaceFilteringCpuTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simple(image);

    simple.setFilter(laplaceFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_laplace_cpu.pgm", 1);
}

TEST(image, EmbossingFilteringCpuTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simple(image);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_embossing_cpu.pgm", 1);
}

TEST(image, GpuAndCpuIdentity) {
    auto imageGpu = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(imageGpu);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    auto imageCpu = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simpleCpu(imageCpu);

    simpleCpu.setFilter(embossingFilter);
    simpleCpu.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_embossing_cpu_test.pgm", 1);
    imageCpu = Loader::loadImage(LOADER_ASSETS_PATH + "sample_embossing_cpu_test.pgm", 1);


    ASSERT_EQ(imageGpu.width, imageCpu.width);
    ASSERT_EQ(imageGpu.height, imageCpu.height);

    for (int i = 0; i < imageGpu.height; ++i) {
        for (int j = 0; j < imageGpu.width; ++j) {
            int index = i * imageGpu.width + j;
            ASSERT_EQ(imageGpu.data[index], imageCpu.data[index]);
        }
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
