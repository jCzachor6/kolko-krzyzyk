#include "MainGame.hpp"
#include "DEFINITIONS.hpp"

int main()
{
	MainGame game(GAME_WIDTH, GAME_HEIGHT, "kolkoKrzyzyk");
	game.Run();
	return EXIT_SUCCESS;
}