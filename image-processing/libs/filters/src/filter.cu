#include <filter.cuh>

#include <stdexcept>

Filter::Filter(int rows, int columns, std::initializer_list<short> m) {
    mask = m;
    this->rows = rows;
    this->columns = columns;
}

std::vector<short> Filter::getMask() {
    return mask;
}

Filter::Row::Row(Filter *filter, int row) {
    this->filter = filter;
    this->row = row;
}

Filter::Row Filter::operator[](int row) {
    if (row >= rows)
        throw std::runtime_error("error: filter row >= rows");

    return Row(this, row);
}

short &Filter::Row::operator[](int col) {
    if (col >= filter->columns)
        throw std::runtime_error("error: filter col >= columns");

    return filter->mask[row * filter->columns + col];
}
