#include <filter.cuh>

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
    return Row(this, row);
}

short &Filter::Row::operator[](int col) {
    return filter->mask[row * filter->columns + col];
}
