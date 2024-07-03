#include "algorithm.hpp"
#include "utility.hpp"
#include <vector>

using std::vector;
using std::array;

array<array<double, ShapeBasics::WindowDivision>, ShapeBasics::WindowDivision> MLearning::RewardMap;

void MLearning::InitVec(){
  for(auto &outer: QValueMap){
    std::fill(outer.begin(), outer.end(), QValueVector);
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
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> map_QValues = QValueMap[row][col];

  // Explore vs Exploit
  if(ExploreChance < epsilon){
    Action = RandomAction();
    print(Action);
    DoAction(Action);
  }
  else{
    // map_QValues[3] = 1;
    auto maximum_value_iter = std::max_element(map_QValues.begin(), map_QValues.end());
    int maximum_value = *maximum_value_iter;
    int iterator = std::distance(map_QValues.begin(), maximum_value_iter);
    Action = static_cast<ActionType>(iterator);
    DoAction(Action);
  }
}

void MLearning::ex_chex(int value){
    if (value > 9){
      throw std::out_of_range("Index is out of range");
    }
}

void MLearning::DoAction(ActionType type){

  sf::Vector2i temporary = Agent::agent_pos;
  
  switch(type){
    case ActionType::LEFT:{
      if(Agent::agent_pos.x - 1 < 0){
        std::cerr << "Agent Out of Range Error." << std::endl; 
        throw std::out_of_range("");
      }
      Agent::agent_pos.x += -1;
      break;
    }
    case ActionType::UP:{
      if(Agent::agent_pos.y - 1 < 0){
        std::cerr << "Agent Out of Range Error." << std::endl;
        throw std::out_of_range("");
      }
      Agent::agent_pos.y += -1;
      break;
    }
    case ActionType::RIGHT:{
      if(Agent::agent_pos.x + 1 > 9){
        std::cerr << "Agent Out of Range Error." << std::endl;
        throw std::out_of_range("");
      }
      Agent::agent_pos.x += 1;
      break;
    }
    case ActionType::DOWN:{
      if(Agent::agent_pos.y + 1 > 9){
        std::cerr << "Agent Out of Range Error." << std::endl;
        throw std::out_of_range("");
      }
      Agent::agent_pos.y += 1;
      break;
    }
    default:
      std::cerr << "Invalid Action Type, Out of Range." << std::endl;
      throw std::out_of_range("");
  }
}

void MLearning::PrintChoiceMap(){
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> map_actions = QValueMap[row][col];
  map_actions[1] = 1;
  Utils::PrintVectorMap(QValueMap);
}

void MLearning::PrintRewardMap(){
  for(const auto &row : MLearning::RewardMap){
    for(const double &n : row){
      std::cout << n << " " ;
    } std::cout << std::endl;
  }
}