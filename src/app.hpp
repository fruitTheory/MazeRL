#pragma once

#include "SFML/Graphics.hpp"
#include "world.hpp"
#include "algorithm.hpp"
#include "utility.hpp"

using namespace WindowBasics;

class App{

  public:
  App(): window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "SFML window")
  {
    agent.create_agent(window);
  }

  void Run();
  void Event_Handler();
  void Render();

  private:
  sf::Event event;
  sf::RenderWindow window;
  Environment env;
  Agent agent;
  MLearning learn;
  int iter{1};
};