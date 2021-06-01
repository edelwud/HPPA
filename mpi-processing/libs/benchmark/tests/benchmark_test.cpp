#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include <benchmark/benchmark-gpu.hpp>
#include <benchmark/benchmark.hpp>

TEST(benchmark, ExecutionTimeTest) {
    auto time = Benchmark::executionTime([]() {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);
    });
    ASSERT_EQ(int(time) / 1000, 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
