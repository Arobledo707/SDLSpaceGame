
#include "GameStateMachine.h"
#include "vld.h"
#include <conio.h>

//TODO add fonts to resourcemanager
// clean up menu
// add "Hanzo" enemy
int main(int argc, char** argv)
{
	GameStateMachine game;

	game.Update();

	game.CleanUp();
	return 0;
}