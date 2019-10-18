#include<time.h>
#include "textFunction.h"
#include "coreFunction.h"
using namespace std;

void startGame() {
	textFunction* usingNow = new textFunction;
	int* arrayOnly = new int[16];

	for (;;)
	{
		int playerInput = usingNow->welcomeFace();
		if (playerInput == 1) {
			int playNum = usingNow->playerInput1(arrayOnly);
			if (playNum == 1)
			{
				delete usingNow;
				usingNow = NULL;
				coreFunction newCore;
				newCore.startBegin(arrayOnly);
				return;
			}
		}
		else if (playerInput == 2) {
			int playNum = usingNow->playerInput2(arrayOnly);
			if (playNum == 1)
			{
				delete usingNow;
				usingNow = NULL;
				coreFunction newCore;
				newCore.startBegin(arrayOnly);
				return;
			}
		}
		else if (playerInput == 3) {
			int playNum = usingNow->playerInput3(arrayOnly);
			if (playNum == 1)
			{
				delete usingNow;
				usingNow = NULL;
				coreFunction newCore;
				newCore.startBegin(arrayOnly);
				return;
			}
		}
		else if (playerInput == 4) {
			return;
		}

	}
}

void main() {
	srand((unsigned)time(NULL));
	startGame();
}
