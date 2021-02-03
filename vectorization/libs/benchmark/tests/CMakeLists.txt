find_package(GTest CONFIG REQUIRED)
add_executable(test_benchmark test_benchmark.cpp)
target_link_libraries(test_benchmark ${LIBRARY_NAME} GTest::main)