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

#define print(value) std::cout << value << "\n"
#define endline std::cout << "\n"

constexpr float sqrt_recursive(float initial, float current, float previous){
    return current == previous ? current : 
    sqrt_recursive(initial, 0.5 * (current + initial / current), current);
}

namespace Utils{
    
    typedef array<array<vector<double>, WindowBasics::ARR_SIZE>, WindowBasics::ARR_SIZE> VECTOR_MAP;
    void PrintVectorMap(VECTOR_MAP &Map);

    template<typename T>
    void print_vector(const vector<T> &vec){
        for(auto &value: vec){
            std::cout << value << " ";
        } endline;
    }

    constexpr float sqrt_cexpr(float initial){
        return 
            initial >= 0 && initial < std::numeric_limits<float>::infinity() ? 
            sqrt_recursive(initial, initial, 0) : 
            std::numeric_limits<float>::quiet_NaN();
    }
}