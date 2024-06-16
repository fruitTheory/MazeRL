#include "algorithm.hpp"
#include "utility.hpp"
#include "SFML/Graphics.hpp"
#include <array>
#include <iostream>

#define WINDOW_SIZE 400
#define MULT 2
using std::array;

const int block_size = std::sqrt(WINDOW_SIZE); // 20
const int block_size_mult = block_size * MULT;
const int block_size_div = WINDOW_SIZE / block_size;
const float outline_thickness{2.5};

const sf::Color outline_color{200,200,200};
const sf::Color default_color{0,128,250}; //  Blue
const sf::Color wall_color{0,10,250}; // Dark Blue

const sf::Color agent_color{250,10,10}; // Red
const sf::Color goal_color{10,250,10}; // Green

const sf::Vector2i goal_pos{8,3}; // goal position
sf::Vector2i agent_pos{5,9}; // initial agent position

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

sf::RectangleShape get_square(){

  sf::RectangleShape square(sf::Vector2f(block_size_mult, block_size_mult));

  square.setOutlineColor(outline_color);
  square.setOutlineThickness(outline_thickness);
  square.setFillColor(default_color);

  return square;
}

void create_agent(sf::RenderWindow &window){

  sf::RectangleShape square = get_square();
  sf::Vector2i screen_position = convert_position(agent_pos, square);

  square.setFillColor(agent_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);

}

void create_goal(sf::RenderWindow &window){

  sf::RectangleShape square = get_square();
  sf::Vector2i screen_position = convert_position(goal_pos, square);

  square.setFillColor(goal_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);

}

void update_agent(sf::RenderWindow &window){

  agent_pos.y -= 1;
  sf::RectangleShape square = get_square();
  sf::Vector2i screen_position = convert_position(agent_pos, square);

  square.setFillColor(agent_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);

}

// Take array mapped position convert to screen based position
sf::Vector2i convert_position(const sf::Vector2i &array_pos, const sf::RectangleShape &shape){
  sf::Vector2i screen_position;
  screen_position.x = WINDOW_SIZE - (WINDOW_SIZE - (array_pos.x * shape.getSize().x));
  screen_position.y = WINDOW_SIZE - (WINDOW_SIZE - (array_pos.y * shape.getSize().y));
  return screen_position;
}

void draw_map(sf::RenderWindow &window){

  sf::RectangleShape square = get_square();
  sf::Vector2f shape_size  = square.getSize();

  for(int y = 0; y < block_size_div; y++){
    for(int x = 0; x < block_size_div; x++){
      if(map[y][x] == 0){square.setFillColor(sf::Color(0,128,250));}
      if(map[y][x] == 1){square.setFillColor(sf::Color(0,10,250));}
      square.setPosition(shape_size.x*x, shape_size.y*y);
      window.draw(square);
    }
  }
}