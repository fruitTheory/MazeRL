#include "utility.hpp"

void PrintVectorMap(VECTOR_MAP &Map){
int num = 1;
  for(auto &inner: Map){
    for(auto &vec: inner){
      print_vector(vec);
      print(num);
      num++; }
  }
}