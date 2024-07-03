#include "algorithm.hpp"
#include "utility.hpp"
#include <vector>

using std::vector;
using std::array;

void MLearning::InitVec(){
  for(auto &outer: QValueMap){
    std::fill(outer.begin(), outer.end(), QValueVector);
  }
}

MLearning::ActionType MLearning::RandomAction(){
  return static_cast<ActionType>(rand() % MaxActions);
}

void MLearning::Start(){
  PreviousState = agent_pos;
  ActionType Action = ChooseAction();
  DoAction(Action);
  Reward = GetReward();
  UpdateQValue();
}

void MLearning::ResetState(){
  Agent::agent_pos = agent_init_position;
}

void MLearning::UpdateQValue(){
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> choice_QValues = QValueMap[row][col];
  CalculateQValue();
  // PrintQValueMap();
}

void MLearning::CalculateQValue(){
}

double MLearning::GetReward(){

  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  int map_value = Environment::map[row][col];
  
  switch(map_value){
    case RewardType::DEFAULT:{
      return -0.1;
    }
    case RewardType::WALL:{
      ResetState();
      return -1;
    }
    case RewardType::GOAL:{
      return 5;
    }
    default:
      std::cerr << "Invalid map value, Out of Range." << std::endl;
      throw std::out_of_range("");
  }
}

MLearning::ActionType MLearning::ChooseAction(){
  ActionType Action;
  double ExploreChance = rand()/(double)RAND_MAX;
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> map_QValues = QValueMap[row][col];

  // Explore vs Exploit
  if(ExploreChance < epsilon){
    // print("Explore");
    Action = RandomAction();
  }
  else{ 
    // print("Exploit");
    auto maximum_value_iter = std::max_element(map_QValues.begin(), map_QValues.end());
    MaxQValue = *maximum_value_iter;
    int iterator = std::distance(map_QValues.begin(), maximum_value_iter);
    Action = static_cast<ActionType>(iterator);
  }
  return Action;
}

void MLearning::DoAction(ActionType type){

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

void MLearning::PrintQValueMap(){
  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  vector<double> map_actions = QValueMap[row][col];
  map_actions[1] = 1;
  Utils::PrintVectorMap(QValueMap);
}