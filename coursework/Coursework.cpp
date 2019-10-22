#include<time.h>
#include "textFunction.h"
#include "coreFunction.h"
using namespace std;

void startGame() {
	textFunction* usingNow = new textFunction;

	for (;;)
	{
		const int puzzleLevel = usingNow->levelChoise();
		int* arrayOnly = new int[(puzzleLevel * puzzleLevel)];
		int playerInput = usingNow->welcomeFace();
		if (playerInput == 1) {
			int playNum = usingNow->playerInput1(arrayOnly, puzzleLevel);
			if (playNum == 1)
			{
				delete usingNow;
				usingNow = NULL;
				coreFunction newCore;
				newCore.startBegin(arrayOnly, puzzleLevel);
				return;
			}
		}
		else if (playerInput == 2) {
			int playNum = usingNow->playerInput2(arrayOnly, puzzleLevel);
			if (playNum == 1)
			{
				delete usingNow;
				usingNow = NULL;
				coreFunction newCore;
				newCore.startBegin(arrayOnly, puzzleLevel);
				return;
			}
		}
		else if (playerInput == 3) {
			int playNum = usingNow->playerInput3(arrayOnly, puzzleLevel);
			if (playNum == 1)
			{
				delete usingNow;
				usingNow = NULL;
				coreFunction newCore;
				newCore.startBegin(arrayOnly, puzzleLevel);
				return;
			}
		}
		else if (playerInput == 4) {
			return;
		}
		delete[]arrayOnly;
	}
}

void main() {
	srand((unsigned)time(NULL));
	startGame();
}
