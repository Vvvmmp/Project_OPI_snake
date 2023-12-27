#include <SFML/Graphics.hpp>
#include "game_core.h"
#include "snake.h"



enum Tdirection { DOWN, LEFT, RIGHT, UP };
Tdirection direction = DOWN;

void TGameCore::events(RenderWindow* win) {
    Event event;
    while (win->pollEvent(event)){
        if (event.type == Event::Closed) {
            close(win);
        }
    }
}

void TGameCore::open(RenderWindow* win) {
    while (win->isOpen()) {
        events(win);
        win->clear();

        win->display();
    }
}