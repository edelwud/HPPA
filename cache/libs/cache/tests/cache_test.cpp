#include <thread>
#include <chrono>

#include <gtest/gtest.h>

#include <cache/cache.hpp>

TEST(cache, ExecutionTimeTest) {
  ASSERT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
