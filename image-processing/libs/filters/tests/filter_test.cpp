#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <filters/laplace-filter.cuh>

TEST(filter, LaplaceInitializeTest) {
    LaplaceFilter filter;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << filter[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
