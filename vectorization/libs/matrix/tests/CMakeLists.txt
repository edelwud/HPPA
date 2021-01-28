add_executable(test_matrix test_standard_matrix.cpp)
target_link_libraries(test_matrix ${LIBRARY_NAME} CONAN_PKG::gtest)