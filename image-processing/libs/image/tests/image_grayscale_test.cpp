#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/embossing-filter.cuh>
#include <filters/kekw-filter.cuh>
#include <filters/laplace-filter.cuh>
#include <image/image-grayscale-cpu.hpp>
#include <image/image-grayscale.hpp>

TEST(image_grayscale, EmbossingFilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(image);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "grayscale/sample_embossing.pgm", 1);
}


TEST(image_grayscale, LaplaceFilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(image);

    simple.setFilter(laplaceFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "grayscale/sample_laplace.pgm", 1);
}

TEST(image_grayscale, LaplaceFilteringCpuTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simple(image);

    simple.setFilter(laplaceFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "grayscale/sample_laplace_cpu.pgm", 1);
}

TEST(image_grayscale, EmbossingFilteringCpuTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simple(image);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "grayscale/sample_embossing_cpu.pgm", 1);
}

TEST(image_grayscale, GpuAndCpuIdentity) {
    auto imageGpu = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscale simple(imageGpu);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    auto imageCpu = Loader::loadImage(LOADER_ASSETS_PATH + "sample.pgm", 1);

    ImageGrayscaleCpu simpleCpu(imageCpu);

    simpleCpu.setFilter(embossingFilter);
    simpleCpu.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "grayscale/sample_embossing_cpu_test.pgm", 1);
    imageCpu = Loader::loadImage(LOADER_ASSETS_PATH + "grayscale/sample_embossing_cpu_test.pgm", 1);


    ASSERT_EQ(imageGpu.width, imageCpu.width);
    ASSERT_EQ(imageGpu.height, imageCpu.height);

    for (int i = 1; i < imageGpu.height-1; ++i) {
        for (int j = 1; j < imageGpu.width-1; ++j) {
            int index = i * imageGpu.width + j;
            ASSERT_EQ(imageGpu.data[index], imageCpu.data[index]);
        }
    }
}