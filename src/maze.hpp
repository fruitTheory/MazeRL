#pragma once

#include "SFML/Graphics.hpp"
#include <array>

using std::array;

class ShapeBasics{
  public:
  sf::RectangleShape create_square();
  sf::Vector2i convert_position(const sf::Vector2i &array_pos, const sf::RectangleShape &shape);

  protected:
  int WINDOW_SIZE = 400; int MULT = 2;
  const int block_size = std::sqrt(WINDOW_SIZE) * MULT; // 40
  const int block_size_div = WINDOW_SIZE / block_size; // 10

  private:
  const float outline_thickness{2.5};
  const sf::Color outline_color{200,200,200};
  const sf::Color default_color{20,20,20};
};

class Environment: public ShapeBasics{
  public:
  const array<array<int, 10>, 10> map = {{
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,1,1,1,1,
    0,0,0,0,0,0,1,1,0,1,
    0,0,0,0,0,0,1,0,0,1,
    0,0,0,0,0,1,1,0,0,1,
    0,0,0,1,1,1,0,0,1,0,
    0,0,0,1,0,0,0,0,1,0,
    0,0,0,1,0,0,0,1,1,0,
    0,0,0,1,0,0,1,1,0,0,
  }};
  void create_map();
  void create_goal(sf::RenderWindow &window);
  void draw_map(sf::RenderWindow &window);

  private:
  const sf::Color ground_color{0,128,250}; //  Blue
  const sf::Color wall_color{0,10,250}; // Dark Blue
  const sf::Color goal_color{10,250,10}; // Green
  const sf::Vector2i goal_pos{8,3}; // goal position

};

class Agent: public ShapeBasics{
  public:
  sf::Vector2i agent_pos{5,9};

  void create_agent(sf::RenderWindow &window);
  void update_agent(sf::RenderWindow &window);

  private:
  const sf::Color agent_color{250,10,10}; // Red

};
