#include "game_core.h"
#include <SFML/Graphics.hpp>

int width = 30, height = 30;
int screen = 25;


int main() {
	RenderWindow* window = new RenderWindow(VideoMode(screen * width, screen * height), "Snake!");
	TGameCore WINDOW;
	WINDOW.open(window);

	return 0;
}