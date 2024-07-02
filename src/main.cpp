#include "utility.hpp"
#include "app.hpp"
#include "world.hpp"
#include "algorithm.hpp"
#include <iostream>


int main()
{
  std::cout << "Hello" << std::endl;
  
  App app;
  app.Run();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}