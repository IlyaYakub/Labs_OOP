#pragma once

#include "Array.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

// Default Constructor
Array::Array()
    : arr(nullptr), size(0)
{
}

// Constructor with size parameter
Array::Array(size_t size)
    : size(size)
{
    assert(size >= 0 && "Incorrect size (less than 0).");

    if (size == 0) {
        arr = nullptr;
    }
    else {
        arr = new int[size];
    }
}

// Copy Constructor
Array::Array(const Array& Ar)
    : size(Ar.size)
{
    arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = Ar.arr[i];
    }
}

// Destructor
Array::~Array() {
    delete[] arr;
}

// Input Method
bool Array::Input() {
    if (size < 0)  return false;
    if (size == 0) return true;

    for (size_t i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    std::cout << "\n\n";
    return true;
}

// Check Existence Method
bool Array::IsAlreadyExist(int value, const std::vector<int>& vec) const {
    return std::find(vec.begin(), vec.end(), value) != vec.end();
}

// Get Intersection Method
std::vector<int> Array::GetIntersection(const Array& Arr2) const {
    std::vector<int> intersection_vec;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < Arr2.size; ++j) {
            if (arr[i] == Arr2.arr[j]) {
                if (IsAlreadyExist(arr[i], intersection_vec))
                    continue;
                intersection_vec.push_back(arr[i]);
            }
        }
    }
    return intersection_vec;
}

// Get Association Method
std::vector<int> Array::GetAssociation(const Array& Arr2) const {
    std::vector<int> associative_vec;

    for (size_t i = 0; i < size; ++i) {
        if (!IsAlreadyExist(arr[i], associative_vec)) {
            associative_vec.push_back(arr[i]);
        }
    }

    for (size_t i = 0; i < Arr2.size; ++i) {
        if (!IsAlreadyExist(Arr2.arr[i], associative_vec)) {
            associative_vec.push_back(Arr2.arr[i]);
        }
    }
    return associative_vec;
}

// Utility function to print vector
void printVector(const std::vector<int>& vec, const std::string& header) {
    std::cout << header << " ---> { ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << "}\n\n";
}
