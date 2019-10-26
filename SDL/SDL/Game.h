#pragma once

#include <SDL.h>
#include <string>

class Game
{
public:
	Game();
	~Game() = default;

	void init(std::string title, int xpos, int ypos, int width, int height, bool fullScreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning_;

	SDL_Window* window_;
	SDL_Renderer* renderer_;
};
