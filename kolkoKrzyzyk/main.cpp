#include "MainGame.hpp"
#include "DEFINITIONS.hpp"
#include "SplashState.hpp"
#include "PlayBotState.hpp"

int main()
{
	MainGame game(GAME_WIDTH, GAME_HEIGHT, "kolkoKrzyzyk");
	game.getData()->stateManager.AddState(StatePtr(new SplashState(game.getData())));
	game.Run();
	return 0;
}