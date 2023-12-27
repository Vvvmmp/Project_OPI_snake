#include <SFML/Graphics.hpp>
#include "game_core.h"

void TGameCore::events(RenderWindow* win) {
    Event event;
    while (win->pollEvent(event)){

    }
}

void TGameCore::open(RenderWindow* win) {
    while (win->isOpen()) {
        events(win);
        win->clear();

        win->display();
    }
}