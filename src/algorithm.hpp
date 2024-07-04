#pragma once

#include "utility.hpp"
#include "world.hpp"
#include <array>
#include <vector>

using std::array;
using std::vector;
using std::srand;

class MLearning: public Agent{
  public:

  MLearning():
  QValueVector(4, 0.0),
  PreviousState(agent_init_position),
  MaxActions{4},
  Reward{0},
  MaxQValue{0},
  alpha{0.1},
  gamma{0.99},
  epsilon{0.025},
  episodes{100}
  {
      InitVec();
      srand(static_cast<unsigned int>(std::time(0)));
  }

  enum ActionType {LEFT, UP, RIGHT, DOWN};
  enum RewardType {DEFAULT, WALL, GOAL};
  
  void Start();
  void ResetState();
  double GetReward();
  void UpdateQValue();
  ActionType ChooseAction();
  void DoAction(const ActionType &type);
  void PrintQValueMap();
  void CalculateQValue();

  protected:
  ActionType RandomAction();
  array<array<vector<double>, WindowDivision>, WindowDivision> QValueMap;

  private:
  void InitVec();
  const int MaxActions;
  ActionType Action{LEFT};
  const vector<double> QValueVector;
  sf::Vector2i PreviousState;
  double Reward;
  double MaxQValue;
  double alpha;
  double gamma;
  double epsilon;
  int episodes;

};

// Alpha - Learn rate - How much old info overrides new info
// Gamma - Discount - Importance of future rewards
// Epsilon - Exploration - old choices vs new choices 