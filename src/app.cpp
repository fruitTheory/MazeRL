#include "app.hpp"


void App::Run(){
  while(window.isOpen()){
    Event_Handler();
    Render();

  }
}

void App::Event_Handler(){
  while(window.pollEvent(event)){
    if(event.type == sf::Event::Closed)
      window.close();
  }
}

void App::Render(){
  window.clear();

  env.draw_map(window);
  learn.Start();
  agent.draw_agent(window);

  window.display();

  sf::sleep(sf::seconds(1));

}