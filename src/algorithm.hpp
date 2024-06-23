#pragma once

#include "maze.hpp"
#include "utility.hpp"
#include <array>
#include <vector>

using std::array;
using std::vector;

class MLearning: public Agent{
  public:

  MLearning(): ChoiceVector(4, 0.0)
  {
      InitVec();
  }

  enum class ActionType {LEFT, UP, RIGHT, DOWN};
  void InitVec();
  static int RandomNumber();
  static void Temporary();
  void Reward_Positive();
  void Reward_Negative();
  static void CheckReward();
  void StoreState();
  void ChooseAction();

  protected:
  static array<array<double, ARR_SIZE>, ARR_SIZE> QValueMap;
  array<array<vector<double>, ARR_SIZE>, ARR_SIZE> ActionMap;

  private:
  static const int range_max{4};
  const vector<double> ChoiceVector;

};

