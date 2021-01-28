add_executable(test_benchmark test_benchmark.cpp)
target_link_libraries(test_benchmark ${LIBRARY_NAME} CONAN_PKG::gtest)