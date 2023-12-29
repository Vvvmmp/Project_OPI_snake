#include "game_core.h"
#include "food.h"
#include "snake.h"
#include <ctime>

int snakeLength = 4;
int tickCounter = 0;
bool gameOver = false;
bool isDirectionChanged = false;
bool IsBotPlaying = false;
int Width = 30, Height = 30;
int Screen = 25;

enum Tdirection { DOWN, LEFT, RIGHT, UP };
Tdirection direction = DOWN;

void AI() {
    if (sn[0].x - 1 != sn[1].x) {
        (sn[0].x < food.x && !isDirectionChanged && direction != LEFT) ? direction = RIGHT, isDirectionChanged = true : false;
    }
    if (sn[0].x + 1 != sn[1].x) {
        (sn[0].x > food.x && !isDirectionChanged && direction != RIGHT) ? direction = LEFT, isDirectionChanged = true : false;
    }
    if (sn[0].y - 1 != sn[1].y) {
        (sn[0].y < food.y && !isDirectionChanged && direction != UP) ? direction = DOWN, isDirectionChanged = true : false;
    }
    if (sn[0].y + 1 != sn[1].y) {
        (sn[0].y > food.y && !isDirectionChanged && direction != DOWN) ? direction = UP, isDirectionChanged = true : false;
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

    if ((sn[0].x == food.x) && (sn[0].y == food.y)) {
        snakeLength++;
        for (int i = 0; i < snakeLength; i++)
            while (food.x == sn[i].x && food.y == sn[i].y) {
                food.x = rand() % Width;
                food.y = rand() % Height;
            }
    }

    for (int i = 1; i < snakeLength; i++) {
        ((sn[0].x == sn[i].x) && (sn[0].y == sn[i].y)) ? gameOver = true : false;
    }
}

void TGameCore::events(RenderWindow* win) {
    Event event;
    while (win->pollEvent(event)) {

        if (event.type == Event::Closed) {
            win->close();
        }

        if (event.type == Event::KeyPressed && !isDirectionChanged && !gameOver && !IsBotPlaying) {
            (event.key.code == Keyboard::Key::W && direction != DOWN) ? direction = UP, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::A && direction != RIGHT) ? direction = LEFT, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::S && direction != UP) ? direction = DOWN, isDirectionChanged = true : false;
            (event.key.code == Keyboard::Key::D && direction != LEFT) ? direction = RIGHT, isDirectionChanged = true : false;
        }
        if (event.type == Event::KeyPressed) {
          (event.key.code == Keyboard::Key::R && gameOver) ? gameOver = false, snakeLength = 4, IsBotPlaying = false, isDirectionChanged = false : false;
        }
        if (event.type == Event::KeyPressed && !gameOver) {
          (event.key.code == Keyboard::Key::I && !gameOver && !IsBotPlaying) ? IsBotPlaying = true, tickCounter = 0 : false;
          (event.key.code == Keyboard::Key::I && !gameOver && IsBotPlaying && tickCounter > 0) ? IsBotPlaying = false : false;
        }
    }
}

void TGameCore::open(RenderWindow* win) {
    srand(time(NULL));
    Texture tile;
    tile.loadFromFile("C:/snake/Project_OPI_snake/The Snake Game/assets/tiles.png");
    Sprite tiles(tile);

    Texture snake;
    snake.loadFromFile("C:/snake/Project_OPI_snake/The Snake Game/assets/snake.png");
    Sprite Snake(snake);

    Texture apple;
    apple.loadFromFile("C:/snake/Project_OPI_snake/The Snake Game/assets/apple.png");
    Sprite apples(apple);

    Texture gameOverText;
    gameOverText.loadFromFile("C:/snake/Project_OPI_snake/The Snake Game/assets/gameover.png");
    Sprite gameOverTextSprite(gameOverText);
    gameOverTextSprite.scale(0.4, 0.4);

    food.x = rand() % 15;
    food.y = rand() % 15;

    Clock clock;
    float timer = 0, delay = 0.1;

    while (win->isOpen()) {

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        events(win);

        if (timer > delay && !gameOver) {
            timer = 0;
            if (IsBotPlaying) {
                AI();
            }
            Tick();
            tickCounter++;
            isDirectionChanged = false;
        }

        win->clear();

        for (int i = 0; i < Width; i++) {
            for (int j = 0; j < Height; j++) {
                tiles.setPosition(i * Screen, j * Screen);
                win->draw(tiles);
            }
        }
        apples.setPosition(food.x * Screen, food.y * Screen);
        win->draw(apples);

            for (int i = 0; i < snakeLength; i++) {
                (i != 0) ? Snake.setTextureRect(IntRect(0, 0, Screen, Screen)) : Snake.setTextureRect(IntRect(direction * Screen, Screen, Screen, Screen));
                if (gameOver && i == 1) {
                    Snake.setTextureRect(IntRect(direction * Screen, Screen * 2, Screen, Screen));
                }
                Snake.setPosition(sn[i].x * Screen, sn[i].y * Screen);
                win->draw(Snake);
            }

        if (gameOver) {
            gameOverTextSprite.setPosition(0, Height / 2);
            isDirectionChanged = true;
            win->draw(gameOverTextSprite);
        }


        win->display();
    }
}