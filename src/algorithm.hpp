#pragma once

#include "SFML/Graphics.hpp"

sf::RectangleShape get_square();
void create_agent(sf::RenderWindow &window);
void create_goal(sf::RenderWindow &window);
void draw_map(sf::RenderWindow &window);
sf::Vector2i convert_position(const sf::Vector2i &array_pos, const sf::RectangleShape &shape);
void update_agent(sf::RenderWindow &window);