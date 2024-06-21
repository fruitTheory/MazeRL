#include "maze.hpp"
#include "utility.hpp"
#include "SFML/Graphics.hpp"
#include <array>
#include <iostream>


using std::array;
using namespace sf;

RectangleShape ShapeBasics::create_square(){
  RectangleShape square(Vector2f(block_size, block_size));
  square.setOutlineColor(outline_color);
  square.setOutlineThickness(outline_thickness);
  square.setFillColor(default_color);

  return square;
}

// Take array mapped position convert to screen based position
Vector2i ShapeBasics::convert_position(const Vector2i &array_pos, const RectangleShape &shape){
  Vector2i screen_position;
  screen_position.x = WINDOW_SIZE - (WINDOW_SIZE - (array_pos.x * shape.getSize().x));
  screen_position.y = WINDOW_SIZE - (WINDOW_SIZE - (array_pos.y * shape.getSize().y));
  return screen_position;
}

void Environment::create_goal(RenderWindow &window){
  RectangleShape square = create_square();
  Vector2i screen_position = convert_position(goal_pos, square);
  square.setFillColor(goal_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);
  
}

void Environment::draw_map(RenderWindow &window){
  RectangleShape square = create_square();
  Vector2f shape_size  = square.getSize();

  for(int y = 0; y < block_size_div; y++){
    for(int x = 0; x < block_size_div; x++){
      if(map[y][x] == 0){square.setFillColor(ground_color);}
      if(map[y][x] == 1){square.setFillColor(wall_color);}
      square.setPosition(shape_size.x*x, shape_size.y*y);
      window.draw(square);
    }
  }
}

void Agent::create_agent(RenderWindow &window){
  RectangleShape square = create_square();
  Vector2i screen_position = convert_position(agent_pos, square);
  square.setFillColor(agent_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);

}

void Agent::update_agent(RenderWindow &window){
  agent_pos.y -= 1;
  RectangleShape square = create_square();
  Vector2i screen_position = convert_position(agent_pos, square);

  square.setFillColor(agent_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);
}