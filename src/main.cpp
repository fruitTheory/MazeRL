#include "SFML/Graphics.hpp"
#include "algorithm.hpp"
#include "utility.hpp"
#include <iostream>
#include <cmath>
#include <array>

#define WINDOW_SIZE 400

int main()
{

  std::cout << "Hello" << std::endl;

  sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "SFML window");

  sf::Event event;
  int iter{1};
  
  while (window.isOpen())
  {
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
          window.close();
    }

    window.clear();

    draw_map(window);
    create_agent(window);
    create_goal(window);
    if(iter % 1000 == 0 && iter < 3000){ update_agent(window);}
    ++iter;

    window.display();
  }

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}