#include "utility.hpp"
#include "maze.hpp"
#include "app.hpp"
#include "algorithm.hpp"
#include <iostream>


int main()
{
  std::cout << "Hello" << std::endl;

  MLearning::CheckReward();
  MLearning::Temporary();
  
  App app;
  app.Run();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}