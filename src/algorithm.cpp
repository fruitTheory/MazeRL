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
  Action = ChooseAction();
  DoAction(Action);
  Reward = GetReward();
  UpdateQValue();
}

void MLearning::ResetState(){
  Agent::agent_pos = agent_init_position;
}

void MLearning::UpdateQValue(){
  int previous_y = PreviousState.y;
  int previous_x = PreviousState.x;
  vector<double> future_QValues = QValueMap[previous_y][previous_x];
  
  auto maximum_value_iter = std::max_element(future_QValues.begin(), future_QValues.end());
  double FutureMaxQValue = *maximum_value_iter;
  Utils::print_vector(future_QValues);

  int current_y = Agent::agent_pos.y;
  int current_x = Agent::agent_pos.x;
  vector<double> current_QValues = QValueMap[current_y][current_x];

  double discount_future = FutureMaxQValue*gamma;

  print(discount_future);

  double expected_value = discount_future+Reward;

  print(expected_value);

  double difference = expected_value-current_QValues[Action];

  print(difference);

  QValueMap[previous_y][previous_x][Action] = current_QValues[Action]+(alpha*difference);

}

double MLearning::GetReward(){

  int row = Agent::agent_pos.y;
  int col = Agent::agent_pos.x;
  int map_value = Environment::map[row][col];
  
  switch(map_value){
    case RewardType::DEFAULT:{
      return -1;
    }
    case RewardType::WALL:{
      ResetState();
      return -5;
    }
    case RewardType::GOAL:{
      ResetState();
      return 100;
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
    Action = RandomAction();
  }
  else{ 
    auto maximum_value_iter = std::max_element(map_QValues.begin(), map_QValues.end());
    MaxQValue = *maximum_value_iter;
    int iterator = std::distance(map_QValues.begin(), maximum_value_iter);
    Action = static_cast<ActionType>(iterator);
  }
  return Action;
}

void MLearning::DoAction(const ActionType &type){

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