#include "MainGame.hpp"
#include "DEFINITIONS.hpp"
#include "SplashState.hpp"
#include "PlayBotState.hpp"

int main()
{
	MainGame game(GAME_WIDTH, GAME_HEIGHT, "kolkoKrzyzyk");
	game.getData()->stateManager.AddState(StatePtr(new PlayBotState(game.getData(), 10, 10)));
	game.Run();
	return 0;
}