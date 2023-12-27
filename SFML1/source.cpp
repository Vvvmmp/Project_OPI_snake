#include <SFML/Graphics.hpp>
#include "game_core.h"
#include "snake.h"

int Width = 30, Height= 30;

enum Tdirection { DOWN, LEFT, RIGHT, UP };
Tdirection direction = DOWN;

void TGameCore::events(RenderWindow* win) {
    Event event;
    while (win->pollEvent(event)){
        if (event.type == Event::Closed) {
            win->close();
        }
        if (event.type == Event::KeyPressed && !isDirectionChanged) {
            (event.key.code == Keyboard::Key::W && direction != DOWN) ? direction = UP, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::A && direction != RIGHT) ? direction = LEFT, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::S && direction != UP) ? direction = DOWN, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::D && direction != LEFT) ? direction = RIGHT, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::R && gameOver) ? gameOver = false, snakeLength = 4, IsBotPlaying = false : false;
            (event.key.code == Keyboard::Key::I && !gameOver && !IsBotPlaying) ? IsBotPlaying = true, tickCounter = 0 : false;
            (event.key.code == Keyboard::Key::I && !gameOver && IsBotPlaying && tickCounter > 0) ? IsBotPlaying = false : false;
        }
    }
}

void Tick() {
  for (int i = snakeLength; i > 0; i--) {
    sn[i].x = sn[i - 1].x;
    sn[i].y = sn[i - 1].y;
  }

  (direction == UP) ? sn[0].y -= 1 : false;
  (direction == LEFT) ? sn[0].x -= 1 : false;
  (direction == DOWN) ? sn[0].y += 1 : false;
  (direction == RIGHT) ? sn[0].x += 1 : false;

  (sn[0].x >= Width) ? sn[0].x = 0 : false;
  (sn[0].x < 0) ? sn[0].x = Width - 1 : false;
  (sn[0].y >= Height) ? sn[0].y = 0 : false;
  (sn[0].y < 0) ? sn[0].y = Height - 1 : false;
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

  Clock clock;
  float timer = 0, delay = 0.1;

    while (win->isOpen()) {

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        events(win);

        if (timer > delay && !gameOver) {
            timer == 0;
            Tick();
        }
        win->clear();

        win->display();
    }
}