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
  QValueVector(4, 0.0)
  {
      InitVec();
      srand(static_cast<unsigned int>(std::time(0)));
  }

  enum ActionType {LEFT, UP, RIGHT, DOWN};
  enum CaseType {DEFAULT, WALL, GOAL};
  
  void Start();
  void StoreState();
  void ResetState();
  static void GiveReward();
  void PrintRewardMap();
  void PrintChoiceMap();
  ActionType ChooseAction();
  void DoAction(ActionType type);

  protected:
  static ActionType RandomAction();
  static array<array<double, WindowDivision>, WindowDivision> RewardMap;
  array<array<vector<double>, WindowDivision>, WindowDivision> QValueMap;

  private:
  void InitVec();
  static const int range_max{4};
  const vector<double> QValueVector;
  double alpha = 0.1;
  double gamma = 0.99;
  double epsilon = 0.1;
  int episodes = 100;

};

// Alpha - Learn rate - How much old info overrides new info
// Gamma - Discount - Importance of future rewards
// Epsilon - Exploration - old choices vs new choices 