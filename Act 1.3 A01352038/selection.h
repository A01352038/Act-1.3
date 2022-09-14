#ifndef SELECTION_H
#define SELECTION_H
#include <vector>
#include "header.h"
//Sergio Augusto Macías Corona
//A01352038

template <class T>
void selection_sort(std::vector<T> &data_vec)
{
    int pos{};

    for (size_t i{data_vec.size() - 1}; i > 0; --i)
    {
        for (size_t j{1}; j <= i; ++j)
            if (data_vec[j].date >= data_vec[pos].date)
                pos = j;

        if (pos != i)
            swap(data_vec, i, pos);
    }
}

#endif //! SELECTION_H