get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME_WLE)
set(LIBRARY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME})
set(LIBRARY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB HEADERS ${LIBRARY_INCLUDE_DIR}/*)
file(GLOB SOURCES ${LIBRARY_SOURCE_DIR}/*)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_link_libraries(${LIBRARY_NAME} utils)

target_include_directories(
        ${LIBRARY_NAME}
        PRIVATE
        $<BUILD_INTERFACE:${LIBRARY_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>)

target_include_directories(
        ${LIBRARY_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_subdirectory(tests)
