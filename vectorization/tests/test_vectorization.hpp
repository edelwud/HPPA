#include <gtest/gtest.h>

#include <chrono>

#include <benchmark/benchmark.hpp>
#include <matrix/parent_matrix.hpp>

#define ITERATIONS 5000

using namespace std::chrono;

template<class T>
class VectorizationTest : public ::testing::Test {
protected:
    VectorizationTest() {
        matrix = new ParentMatrix<T>({ 8, 8, 8, 8 });
        matrix2 = new ParentMatrix<T>({ 8, 8, 8, 8 });
    }

    ~VectorizationTest() {
        delete matrix;
        delete matrix2;
    }

    virtual void SetUp() {
        point = high_resolution_clock::now();
    }

    virtual void TearDown() {
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto total = duration_cast<duration<double>>(t2 - point).count();
        std::cout << std::endl << "Total: " << total << std::endl;
        std::cout << "Average: " << std::setprecision(6) << total/counter << std::endl;
        counter = 0;
    }

    void log(double time) {
        std::cout << "Time point: " << std::setprecision(6) << time << std::endl;
        counter++;
    }

    inline static int counter = 0;
    high_resolution_clock::time_point point;
    ParentMatrix<T> *matrix;
    ParentMatrix<T> *matrix2;
};