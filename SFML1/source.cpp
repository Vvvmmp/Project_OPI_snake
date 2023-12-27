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

void Tick() {
  for (int i = snakeLength; i > 0; i--) {
    sn[i].x = sn[i - 1].x;
    sn[i].y = sn[i - 1].y;
  }
}

void TGameCore::open(RenderWindow* win) {
  Texture tile;
  tile.loadFromFile("C:/snake/SFML1/assets/tiles.png");
  Sprite tiles(tile);

  Texture snake;
  snake.loadFromFile("C:/snake/SFML1/assets/snake.png");
  Sprite Snake(snake);

  Texture apple;
  apple.loadFromFile("C:/snake/SFML1/assets/apple.png");
  Sprite apples(apple);

  Texture gameOverText;
  gameOverText.loadFromFile("C:/snake/SFML1/assets/gameover.png");
  Sprite gameOverTextSprite(gameOverText);
  gameOverTextSprite.scale(0.4, 0.4);

    while (win->isOpen()) {
        events(win);
        win->clear();

        win->display();
    }
}