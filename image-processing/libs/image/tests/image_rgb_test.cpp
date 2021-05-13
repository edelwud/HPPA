#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/embossing-filter.cuh>
#include <filters/laplace-filter.cuh>
#include <image/image-rgb-cpu.hpp>
#include <image/image-rgb.hpp>

TEST(image_rgb, EmbossingFilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);

    ImageRGB simple(image);

    simple.setFilter(embossingFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "rgb/sample_embossing.ppm", 3);
}


TEST(image_rgb, LaplaceFilteringTest) {
    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);

    ImageRGB simple(image);

    simple.setFilter(laplaceFilter);
    simple.applyFilter();

    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "rgb/sample_laplace.ppm", 3);
}

//TEST(image_rgb, LaplaceFilteringCpuTest) {
//    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);
//
//    ImageRGBCpu simple(image);
//
//    simple.setFilter(laplaceFilter);
//    simple.applyFilter();
//
//    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "rgb/sample_laplace_cpu.ppm", 3);
//}
//
//TEST(image_rgb, EmbossingFilteringCpuTest) {
//    auto image = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);
//
//    ImageRGBCpu simple(image);
//
//    simple.setFilter(embossingFilter);
//    simple.applyFilter();
//
//    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "sample_embossing_cpu.pgm", 3);
//}
//
//TEST(image_rgb, GpuAndCpuIdentity) {
//    auto imageGpu = Loader::loadImage(LOADER_ASSETS_PATH + "sample.ppm", 3);
//
//    ImageRGB simple(imageGpu);
//
//    simple.setFilter(embossingFilter);
//    simple.applyFilter();
//
//    auto imageCpu = Loader::loadImage(LOADER_ASSETS_PATH + "rgb/sample.ppm", 3);
//
//    ImageRGBCpu simpleCpu(imageCpu);
//
//    simpleCpu.setFilter(embossingFilter);
//    simpleCpu.applyFilter();
//
//    Loader::saveImage(simple.getImage(), LOADER_ASSETS_PATH + "rgb/sample_embossing_cpu_test.ppm", 3);
//    imageCpu = Loader::loadImage(LOADER_ASSETS_PATH + "rgb/sample_embossing_cpu_test.ppm", 3);
//
//
//    ASSERT_EQ(imageGpu.width, imageCpu.width);
//    ASSERT_EQ(imageGpu.height, imageCpu.height);
//
//    for (int i = 0; i < imageGpu.height; ++i) {
//        for (int j = 0; j < imageGpu.width; ++j) {
//            int index = i * imageGpu.width + j;
//            ASSERT_EQ(imageGpu.data[index], imageCpu.data[index]);
//        }
//    }
//}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}