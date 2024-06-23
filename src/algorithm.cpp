#include "algorithm.hpp"
#include "utility.hpp"
#include <vector>

using std::vector;
using std::array;

array<array<double, ARR_SIZE>, ARR_SIZE> MLearning::QValueMap{0};

void MLearning::InitVec(){
  for(auto &outer: ActionMap){
    std::fill(outer.begin(), outer.end(), ChoiceVector);
  }
}

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

void MLearning::ChooseAction(){
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> map_actions = ActionMap[row][col];
  map_actions[1] = 1;
  PrintVectorMap(ActionMap);
}

void MLearning::Temporary(){
  for(const auto &row : MLearning::QValueMap){
    for(const double &n : row){
      std::cout << n << " " ;
    } std::cout << std::endl;
  }
}