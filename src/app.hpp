#pragma once

#include "SFML/Graphics.hpp"
#include "maze.hpp"

class App{

  public:

  App(): window(sf::VideoMode(400, 400), "SFML window") {}
  
  void Run();
  void Event_Handler();
  void Render();

  private:

  sf::Event event;
  sf::RenderWindow window;
  int iter{1};
  Environment env;
  Agent agent;
  
};