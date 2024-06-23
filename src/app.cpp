#include "app.hpp"


void App::Run(){
  while(window.isOpen()){
    Event_Handler();
    Render();
    // if(iter % 1000 == 0 && iter < 3000){ agent.update_agent(window);}
    // if(iter == 10000){ break; }
    ++iter;
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
  agent.create_agent(window);

  window.display();
}