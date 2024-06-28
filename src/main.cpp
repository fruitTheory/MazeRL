#include "utility.hpp"
#include "world.hpp"
#include "app.hpp"
#include "algorithm.hpp"
#include <iostream>


int main()
{
  std::cout << "Hello" << std::endl;

  MLearning learn;
  learn.ChooseAction();
  
  App app;
  app.Run();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}