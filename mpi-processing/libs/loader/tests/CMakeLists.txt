set(TEST_NAME ${LIBRARY_NAME}_test)

find_package(GTest REQUIRED)

add_executable(${TEST_NAME} loader_test.cpp)

target_link_libraries(${TEST_NAME} ${LIBRARY_NAME} GTest::GTest)
