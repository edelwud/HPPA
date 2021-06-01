#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/laplace-filter.cuh>

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
