#pragma once

#include "utility.hpp"
#include "world.hpp"
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
  static array<array<double, ShapeBasics::WindowDivision>, ShapeBasics::WindowDivision> QValueMap;
  array<array<vector<double>, ShapeBasics::WindowDivision>, ShapeBasics::WindowDivision> ActionMap;

  private:
  static const int range_max{4};
  const vector<double> ChoiceVector;

};

