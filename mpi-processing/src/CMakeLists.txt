include_directories(/usr/lib64/openmpi/include)
link_directories(/usr/lib64/openmpi/lib64)

add_executable(${PROJECT_NAME} executor.hpp main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC mpi mpi_cxx image loader)
