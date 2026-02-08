#pragma once
#include <vector>
#include "number.hpp"

class Sorter {
public:
    Sorter() = default;

    void add(const Number&);
    void print() const;

    void insertionSort();
    void mergeSort();
    void mergeRecursion(size_t, size_t);
    void merge(size_t, size_t, size_t);
private:
    std::vector<Number> data;

    static void swap(Number&, Number&);
};