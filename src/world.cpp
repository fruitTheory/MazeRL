#include "world.hpp"
#include "utility.hpp"
#include "SFML/Graphics.hpp"
#include <array>
#include <iostream>

using std::array;
using namespace sf;
using namespace WindowBasics;

const sf::Vector2i Agent::agent_init_position{1,1};
sf::Vector2i Agent::agent_pos = Agent::agent_init_position;
const array<array<int, ShapeBasics::WindowDivision>, ShapeBasics::WindowDivision> Environment::map = 
{{
1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 1, 1, 1, 1, 1, 0, 1, 2, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1
}};

// Take array mapped position convert to screen based position
Vector2i ShapeBasics::convert_position(const Vector2i &array_pos, const RectangleShape &shape){
  Vector2i screen_position;
  screen_position.x = WINDOW_SIZE - (WINDOW_SIZE - (array_pos.x * shape.getSize().x));
  screen_position.y = WINDOW_SIZE - (WINDOW_SIZE - (array_pos.y * shape.getSize().y));
  return screen_position;
}

void Environment::draw_map(RenderWindow &window){
  Vector2f shape_size  = square.getSize();

  for(int y = 0; y < WindowDivision; y++){
    for(int x = 0; x < WindowDivision; x++){
      if(map[y][x] == 0){square.setFillColor(ground_color);}
      if(map[y][x] == 1){square.setFillColor(wall_color);}
      if(map[y][x] == 2){square.setFillColor(goal_color);}
      square.setPosition(shape_size.x*x, shape_size.y*y);
      window.draw(square);
    }
  }
}

void Agent::draw_agent(RenderWindow &window){
  Vector2i screen_position = convert_position(agent_pos, square);
  square.setFillColor(agent_color);
  square.setPosition(screen_position.x, screen_position.y);
  window.draw(square);
}