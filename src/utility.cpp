#include "utility.hpp"

using namespace Utils;

void Utils::PrintVectorMap(VECTOR_MAP &Map){
int num = 1;
  for(auto &inner: Map){
    for(auto &vec: inner){
      print_vector(vec);
      print(num);
      num++; }
  }
}