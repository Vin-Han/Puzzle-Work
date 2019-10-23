#include "textFunction.h"

int textFunction::levelChoise() {
	int puzzleLevel;
	for (;;){
		cout << "*  [  welcome to puzzleworld  ]  *" << endl;
		cout << "** [ choose one level to play ] **" << "\n" << endl;
		cout << "**  [  \"1\" use a 2*2 puzzle  ]  **" << endl;
		cout << "**  [  \"2\" use a 3*3 puzzle  ]  **" << endl;
		cout << "**  [  \"3\" use a 4*4 puzzle  ]  **" << endl;
		cin >> puzzleLevel;
		if (cin.fail() || puzzleLevel < 1 || puzzleLevel>3) {
			system("cls");
			cout <<"\n*[  Input is wrong , try again  ]*\n" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			system("cls");
			return (puzzleLevel + 1);
		}
	}
}

int textFunction::welcomeFace(int puzzleLevel,int* arrayOnly) {
	int playerInput;
	for (;;) {
		cout << "*  [  welcome to puzzleworld  ]  *" << endl;
		cout << "** [ choose one level to play ] **" << "\n" << endl;
		cout << "*[  \"1\"    Input number by hand  ] " << endl;
		cout << "*[  \"2\"    Use random number     ]" << endl;
		cout << "*[  \"3\"    Use order number \"1~"<<(puzzleLevel*puzzleLevel)<<"\"]" << endl;
		cout << "*[  \"4\"    Read puzzle from flie ]"<< endl;
		cout << "*[  \"5\"    Read a solution flie  ]" << endl;
		cout << "*[  \"0\"    Quit the game         ]" << endl;
		cin >> playerInput;
		if (cin.fail() || playerInput < 1 || playerInput > 5) {
			system("cls");
			cout << "\n*[  Input is wrong , try again  ]*\n" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else break;
	}
	system("cls");
	if      (playerInput == 1) return playerInput1(arrayOnly, puzzleLevel);
	else if (playerInput == 2) return playerInput2(arrayOnly, puzzleLevel);
	else if (playerInput == 3) return playerInput3(arrayOnly, puzzleLevel);
	else if (playerInput == 4) return 5;
	else if (playerInput == 5) return 6;
	else if (playerInput == 0) return 0;
}

int textFunction::playerInput1(int* arrayOnly, const int sizeNum) {
	for (int input = 0; input < ((sizeNum * sizeNum) - 1); ){
		cout << "**[  give me " << (sizeNum * sizeNum - 1) << " number ro build the array ]**" << endl;
		cout << "**[    please within this range: 1~20    ]**" << endl;
		cout << "**[      give me the " << (input + 1) << "/" << (sizeNum * sizeNum - 1) << " one number:     ]**" << endl;
		cin >> arrayOnly[input];
		system("cls");
		cin.clear();
		cin.ignore(1024, '\n');
		if (cin.fail() || arrayOnly[input] < 1 || arrayOnly[input] >20) cout << "\n**[      Input is wrong , try again      ]**\n" << endl;
		else {
			if (input == 0) input++;
			else {
				int nowinput = input;
				for (int checkNum = 0; checkNum < nowinput; checkNum++) {
					if (arrayOnly[checkNum] == arrayOnly[input]) {
						cout << "\n**[     Number is repeated,try again     ]**\n" << endl;
						break;
					}
					else { input = nowinput + 1; }
				}
			}
		}
	}
	return showArray(arrayOnly, sizeNum);
}

int textFunction::playerInput2(int* arrayOnly, const int sizeNum) {
	for (int countNum = 0; countNum < (sizeNum * sizeNum - 1); countNum++) {
		arrayOnly[countNum] = ((rand() % (sizeNum * (sizeNum + 1))) + 1);
		for (int checkNum = 0; checkNum < countNum; checkNum++) {
			if (arrayOnly[checkNum] == arrayOnly[countNum]) countNum--;
		}
	}
	return showArray(arrayOnly, sizeNum);
}

int textFunction::playerInput3(int* arrayOnly, const int sizeNum) {
	for (int countNum = 0; countNum < (sizeNum*sizeNum - 1); countNum++) {
		arrayOnly[countNum] = countNum + 1;
	}
	return showArray(arrayOnly, sizeNum);
}

string textFunction::playerInput4(const int sizeNum, vector<int*> arrayRead) {
	string fileName;
	for (;;){
		cout << "*  [  welcome to puzzleworld  ]  *" << endl;
		cout << "*  [ give me the name of file ] *" << endl;
		cin >> fileName;
		if (cin.fail()) {
			system("cls");
			cout << "\n**[      Input is wrong , try again      ]**\n" << endl;
		}
		if (!openFile(fileName)) {
			system("cls"); 
			cout << "\n**[      Name is wrong , try again      ]**\n" << endl;
		}
		else{
			break;
		}
	}
	return fileName;
}

int textFunction::showArray(int* arrayOnly, const int sizeNum) {
	int playNum;
	system("cls");
	for (;;){
		cout << "\n***    [  so now let us begin   ]    ****\n" << endl;
		cout << "***    [  by using this array?  ]    ****\n" << endl;
		for (int genNumA = 0; genNumA < (sizeNum*sizeNum); genNumA++) {
			if(arrayOnly[genNumA] == -1)  cout << "\t" <<" ";
			else cout << "\t" << arrayOnly[genNumA];
			if (((genNumA + 1) % sizeNum) == 0) cout << endl;
		}
		cout << "\n**   [  \"1\":regular way(slowly)  ] *** [  \"2\":back ] *** [  \"3\":save ] *** [  \"4\":use formular way(fast) ]   **" << endl;
		cin >> playNum;
		system("cls");
		cin.clear();
		cin.ignore(1024, '\n');
		if (cin.fail() || playNum < 1 || playNum > 4) cout << "\n**[      Input is wrong , try again      ]**\n" << endl;
		else return playNum;
	}
}