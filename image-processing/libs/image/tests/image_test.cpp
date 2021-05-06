#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <utils/helpers/helper_image.hpp>
#include <image/image.cuh>

TEST(image, ExecutionTimeTest) {
    __loadPPM()
    Image simple;

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
