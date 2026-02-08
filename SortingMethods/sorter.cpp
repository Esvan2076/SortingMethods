#include "sorter.hpp"

void Sorter::swap(Number& a, Number& b) {
    Number temp = a;
    a = b;
    b = temp;
}

void Sorter::add(const Number& n) {
    data.push_back(n);
}

void Sorter::print() const {
    for (const Number& n : data) {
        n.print();
    }
}

void Sorter::insertionSort() {
    for (size_t i = 1; i < data.size(); ++i) {
        //for (size_t j = i; j > 0 and data[j - 1] > data[j]; --j) {
        //    swap(data[j], data[j - 1]);
        //}

        size_t j = i;
        while (j > 0 && data[j - 1] > data[j]) {
            std::swap(data[j], data[j - 1]);
            --j;
        }
    }
}

void Sorter::mergeSort() {
    if (data.size() == 0) return;
    mergeRecursion(0, data.size() - 1);
}

void Sorter::mergeRecursion(size_t start, size_t end) {
    size_t size = (end - start + 1);
    if (size == 1) {
        return;
    }

    size_t mid = start + (end - start) / 2;

    mergeRecursion(start, mid);
    mergeRecursion(mid + 1, end);

    merge(start, mid, end);
}

void Sorter::merge(size_t start, size_t mid, size_t end) {
    size_t sizeLeft = (mid - start) + 1;
    size_t sizeRight = end - mid;

    std::vector<Number> left;
    left.reserve(sizeLeft);
    std::vector<Number> right;
    right.reserve(sizeRight);

    for (size_t i = start; i <= mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid + 1; i <= end; ++i) {
        right.push_back(data[i]);
    }

    size_t idxLeft = 0, idxRight = 0, k = start;

    while (idxLeft < sizeLeft and idxRight < sizeRight) {
        if (left[idxLeft] <= right[idxRight]) {
            data[k] = left[idxLeft];
            ++idxLeft;
        }
        else {
            data[k] = right[idxRight];
            ++idxRight;
        }
        ++k;
    }

    while (idxLeft < sizeLeft) {
        data[k] = left[idxLeft];
        ++idxLeft;
        ++k;
    }

    while (idxRight < sizeRight) {
        data[k] = right[idxRight];
        ++idxRight;
        ++k;
    }
}
