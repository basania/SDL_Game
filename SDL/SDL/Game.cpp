
#include "Game.h"
#include <iostream>

Game::Game()
{
}

void Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "INIT OK.\n";
		window_ = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);

		if (window_)
		{
			std::cout << "Window has been created.\n";
		}

		renderer_ = SDL_CreateRenderer(window_, -1, 0);
		if (renderer_)
		{
			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
			std::cout << "Renderer has been created.\n";
		}
		isRunning_ = true;
	}
	else
	{
		isRunning_ = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning_ = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);
}

void Game::clean()
{
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	SDL_Quit();
	std::cout << "Game closed.\n";
}

bool Game::running()
{
	return isRunning_;
}
