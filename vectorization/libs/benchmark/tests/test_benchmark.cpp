#include <gtest/gtest.h>

#include <unistd.h>
#include <benchmark/benchmark.hpp>

TEST(benchmark, ExecutionTest) {
    Benchmark::getExecutionTime([](){});
}

TEST(benchmark, ExecutionTimeTest) {
    int time = (int)Benchmark::getExecutionTime([](){
        sleep(1);
    });
    ASSERT_EQ(1, time);
}