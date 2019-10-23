#include<time.h>
#include "textFunction.h"
#include "coreFunction.h"
#include "recordUsing.h"
#include "fomulaFun.h"

using namespace std;

void startGame();

void main() {
	srand((unsigned)time(NULL));
	startGame();
}

void startGame() {
	for (;;){
		textFunction* usingNow = new textFunction;
		const int puzzleLevel = usingNow->levelChoise();//let players make choice and creat the original empty array 
		int* arrayOnly = new int[(puzzleLevel * puzzleLevel) + 3];
		arrayOnly[(puzzleLevel * puzzleLevel) - 1] = -1;
		arrayOnly[(puzzleLevel * puzzleLevel)] = 0;
		arrayOnly[(puzzleLevel * puzzleLevel) + 1] = arrayOnly[(puzzleLevel * puzzleLevel) + 2] = (puzzleLevel - 1);

		int playerInput = usingNow->welcomeFace(puzzleLevel,arrayOnly);//choose game mode and begin the game
		delete usingNow;
		usingNow = NULL;
		if (playerInput == 1) {
			coreFunction newCore;
			newCore.startBegin(arrayOnly, puzzleLevel);
			return;
		}
		else if (playerInput == 2){}
		else if (playerInput == 3) {
			recordUsing fileUsing;
			fileUsing.remRecord(arrayOnly, puzzleLevel);
			delete[]arrayOnly;
			vector<int*> arrayRead;
		}
		else if (playerInput == 4) {
			fomulaFun fomway;
			fomway.start(arrayOnly, puzzleLevel);
			delete[]arrayOnly;
			return;
		}
		else if (playerInput == 5) {
			delete[]arrayOnly;
			vector<int*> arrayRead;
			string fileNme = usingNow->playerInput4(puzzleLevel, arrayRead);
			recordUsing fileUsing;
			fileUsing.dealRecord(fileNme, arrayRead, puzzleLevel);
			return;
		}
		else if (playerInput == 6) {
			delete[]arrayOnly;
			vector<int*> arrayRead;
			string fileNme = usingNow->playerInput4(puzzleLevel, arrayRead);
			recordUsing fileUsing;
			fileUsing.dealSolution(fileNme, arrayRead, puzzleLevel);
			return;
		}
		else if (playerInput == 0) { return; }
	}
}
