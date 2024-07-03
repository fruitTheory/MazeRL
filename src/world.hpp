#pragma once

#include "SFML/Graphics.hpp"
#include "utility.hpp"
#include <array>

using std::array;
using namespace WindowBasics;

class ShapeBasics{
  public:
  ShapeBasics(): square(sf::Vector2f(block_size, block_size))
  {
    square.setOutlineColor(outline_color);
    square.setOutlineThickness(outline_thickness);
    square.setFillColor(default_color);
  }
  sf::Vector2i convert_position(const sf::Vector2i &array_pos, const sf::RectangleShape &shape);

  protected:
  sf::RectangleShape square;
  static constexpr int block_size = Utils::sqrt_cexpr(WINDOW_SIZE) * MULT; // 40
  const sf::Color userRed{250,10,10};
  const sf::Color userGreen{10,250,10};
  const sf::Color userBlue{0,128,250};
  const sf::Color userDarkBlue{0,10,250};

  public:
  static constexpr int WindowDivision = WINDOW_SIZE / block_size; // 10 - window / block_size

  private:
  const float outline_thickness{2.5};
  const sf::Color outline_color{200,200,200};
  const sf::Color default_color{20,20,20};
  
};

class Environment: public ShapeBasics{
  public:
  const static array<array<int, WindowDivision>, WindowDivision> map;
  void draw_map(sf::RenderWindow &window);

  private:
  const sf::Color ground_color{userBlue};
  const sf::Color wall_color{userDarkBlue};
  const sf::Color goal_color{userGreen};
  const sf::Vector2i goal_pos{8,1};

};

class Agent: public ShapeBasics{
  public:
  static sf::Vector2i agent_pos;
  void draw_agent(sf::RenderWindow &window);

  protected:
  const static sf::Vector2i agent_init_position;

  private:
  const sf::Color agent_color{userRed};

};
