add_executable(test_vectorization test_vectorization.cpp)
target_link_libraries(test_vectorization ${VECTORIZATION_DEPS} CONAN_PKG::gtest)