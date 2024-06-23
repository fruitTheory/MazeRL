#pragma once

#include "SFML/Graphics.hpp"
#include "utility.hpp"
#include <array>

using std::array;
using namespace WindowBasics;

class ShapeBasics{
  public:
  sf::RectangleShape create_square();
  sf::Vector2i convert_position(const sf::Vector2i &array_pos, const sf::RectangleShape &shape);

  protected:
  const int block_size = std::sqrt(WINDOW_SIZE) * MULT; // 40
  const int block_size_div = WINDOW_SIZE / block_size; // 10

  private:
  const float outline_thickness{2.5};
  const sf::Color outline_color{200,200,200};
  const sf::Color default_color{20,20,20};
};

class Environment: public ShapeBasics{
  public:
  const static array<array<int, ARR_SIZE>, ARR_SIZE> map;
  void create_map();
  void draw_map(sf::RenderWindow &window);

  private:
  const sf::Color ground_color{0,128,250}; //  Blue
  const sf::Color wall_color{0,10,250}; // Dark Blue
  const sf::Color goal_color{10,250,10}; // Green
  const sf::Vector2i goal_pos{8,1}; // goal position

};

class Agent: public ShapeBasics{
  public:
  static sf::Vector2i agent_pos;
  void create_agent(sf::RenderWindow &window);
  void update_agent(sf::RenderWindow &window);
  void reset_agent(sf::RenderWindow &window);

  protected:
  const static sf::Vector2i agent_init_position;

  private:
  const sf::Color agent_color{250,10,10}; // Red


};
