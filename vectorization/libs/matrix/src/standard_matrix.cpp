#include <standard_matrix.hpp>

#include <iomanip>
#include <iostream>
#include <stdexcept>

StandardMatrix::StandardMatrix(int rows, int columns) : Matrix(rows, columns) {
    space = allocate(rows, columns);
    fill(space, rows, columns, 10);
}

void StandardMatrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setprecision(3) << std::setw(5) << space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void StandardMatrix::multiply(Matrix& matrix) {
    if (columns != matrix.getRows()) {
        throw std::runtime_error("cannot multiply matrix");
    }

    auto distColumns = matrix.getColumns();
    auto distSpace = matrix.getSpace();
    auto resultSpace = allocate(rows, distColumns);

    for(int i = 0; i < rows; i++) {
        auto resultSpacePart = resultSpace[i];
        auto hostSpacePart = space[i];
        for (int k = 0; k < columns; k++) {
            auto hostValue = hostSpacePart[k];
            auto distSpacePart = distSpace[k];
            for (int j = 0; j < distColumns; j++) {
                resultSpacePart[j] += hostValue * distSpacePart[j];
            }
        }
    }

    free(space, rows, columns);
    columns = distColumns;
    space = resultSpace;
}

void StandardMatrix::add(Matrix& matrix) {
    auto resultSpace = allocate(rows, columns);
    auto distSpace = matrix.getSpace();

    for (int i = 0; i < rows; i++) {
        auto distSpacePart = distSpace[i];
        auto resultSpacePart = resultSpace[i];
        auto hostSpacePart = space[i];
        for (int j = 0; j < columns; j++) {
            resultSpacePart[j] = hostSpacePart[j] + distSpacePart[j];
        }
    }
    free(space, rows, columns);
    space = resultSpace;
}
