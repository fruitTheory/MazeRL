#include "SFML/Graphics.hpp"
#include "maze.hpp"
#include "app.hpp"
#include "utility.hpp"
#include <iostream>
#include <cmath>
#include <array>


int main()
{
  std::cout << "Hello" << std::endl;

  App app;
  app.Run();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}