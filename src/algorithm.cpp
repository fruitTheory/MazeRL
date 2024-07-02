#include "algorithm.hpp"
#include "utility.hpp"
#include <vector>

using std::vector;
using std::array;

array<array<double, ShapeBasics::WindowDivision>, ShapeBasics::WindowDivision> MLearning::RewardMap;

void MLearning::InitVec(){
  for(auto &outer: QChoiceMap){
    std::fill(outer.begin(), outer.end(), ChoiceVector);
  }
}

MLearning::ActionType MLearning::RandomAction(){
  return static_cast<ActionType>(rand() % range_max);
}

void MLearning::GiveReward(){

  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  int map_value = Environment::map[row][col];
  
  switch(map_value){
    case CaseType::DEFAULT:{
      RewardMap[row][col] += -0.1;
      break;
    }
    case CaseType::WALL:{
      RewardMap[row][col] += -1;
      // Reset state
      break;
    }
    case CaseType::GOAL:{
      RewardMap[row][col] += 5;
      break;
    }
    default:
      std::cout << "How'd you get this value." << std::endl;
      break;
  }
}

void MLearning::ChooseAction(){
  ActionType Action;
  double ExploreChance = rand()/(double)RAND_MAX;

  // Explore vs Exploit
  if(ExploreChance < epsilon){
    Action = RandomAction();
    print(Action);
    DoAction(Action);
  }
  else{
    print("Best action");
  }
}

void MLearning::DoAction(ActionType type){
  switch(type){
    case ActionType::LEFT:{
      Agent::agent_pos.x += -1;
      break;
    }
    case ActionType::UP:{
      Agent::agent_pos.y += 1;
      break;
    }
    case ActionType::RIGHT:{
      Agent::agent_pos.x += 1;
      break;
    }
    case ActionType::DOWN:{
      Agent::agent_pos.y += -1;
      break;
    }
    default:
      std::cout << "Never to be reached." << std::endl;
      break;
  }
}

void MLearning::PrintChoiceMap(){
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> map_actions = QChoiceMap[row][col];
  map_actions[1] = 1;
  Utils::PrintVectorMap(QChoiceMap);
}

void MLearning::PrintRewardMap(){
  for(const auto &row : MLearning::RewardMap){
    for(const double &n : row){
      std::cout << n << " " ;
    } std::cout << std::endl;
  }
}