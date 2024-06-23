#pragma once

#include<iostream>
#include<vector>
#include<array>

using std::vector;
using std::array;

namespace WindowBasics{
    constexpr int WINDOW_SIZE{400}; 
    constexpr int MULT{2}; 
    constexpr int ARR_SIZE{10};
}

#define print(value) std::cout << value << std::endl
#define endline std::cout << std::endl

template<typename T>
void print_vector(const vector<T> &vec){
    for(auto &value: vec){
        std::cout << value << " ";
    } endline;
}

typedef array<array<vector<double>, WindowBasics::ARR_SIZE>, WindowBasics::ARR_SIZE> VECTOR_MAP;
void PrintVectorMap(VECTOR_MAP &Map);