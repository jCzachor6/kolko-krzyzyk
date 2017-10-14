#include <iostream>
#include "MainGame.hpp"

int main()
{
	MainGame game(1024, 768, "kolkoKrzyzyk");
	game.Run();
	return EXIT_SUCCESS;
}