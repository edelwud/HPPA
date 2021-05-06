#pragma once

#include <initializer_list>
#include <vector>

class Filter {
public:
    class Row {
        friend class Filter;

    public:
        short& operator[](int col);

    private:
        Row(Filter *filter, int row);

    private:
        Filter *filter;
        int row;
    };

    Filter(int rows, int columns, std::initializer_list<short> mask);

public:
    std::vector<short> getMask();
    unsigned int getLength() const;

public:
    Row operator[](int x);

private:
    std::vector<short> mask;
    int rows;
    int columns;
};
