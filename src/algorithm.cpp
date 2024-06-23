#include "algorithm.hpp"
#include "utility.hpp"

array<array<double, 10>, 10> MLearning::QValueMap{0};

int MLearning::RandomNumber(){

  int rand_num = rand() % range_max;
  print(rand_num);

  return rand_num;
}

void MLearning::CheckReward(){

  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  int map_value = Environment::map[row][col];
  
  switch(map_value){
    case 0:{
      QValueMap[row][col] += 0.1;
      break;
    }
    case 1:{
      QValueMap[row][col] += -1;
      break;
    }
    case 2:{
      QValueMap[row][col] += 5;
      break;
    }
    default:
      break;
  }

}

void MLearning::Temporary(){
  for(auto row : MLearning::QValueMap){
    for(double n : row){
      std::cout << n << " " ;
    } std::cout << std::endl;
  }
}