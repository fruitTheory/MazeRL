#pragma once

#include "maze.hpp"
#include "utility.hpp"
#include <array>

using std::array;

class MLearning: public Agent{
  public:

  static array<array<double, ARR_SIZE>, ARR_SIZE> QValueMap;
  enum class Action {LEFT, UP, RIGHT, DOWN};
  enum class Reward {LEFT, UP, RIGHT, DOWN};

  static int RandomNumber();
  static void Temporary();
  void Reward_Positive();
  void Reward_Negative();
  static void CheckReward();
  void StoreState();
  void ChooseAction();

  private:
  static const int range_max{4};

};

