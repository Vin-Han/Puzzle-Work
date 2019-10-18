#include "textFunction.h"

int textFunction::welcomeFace() {
	system("cls");
	int playerInput;
	for (;;) {
		cout << "*****welcome to puzzleworld*****" << endl;
		cout << "******choose one play mode******" << endl;
		cout << "***********************************************************" << endl;
		cout << "***I want to give some number*** please input \"1\"       ***" << endl;
		cout << "***I want to use random number** please input \"2\"       ***" << endl;
		cout << "***I want to use order number \"1~15\"*** please input \"3\"***" << endl;
		cout << "***I want to quit the game*** please input \"4\"          ***" << endl;
		cout << "***********************************************************" << endl;
		cin >> playerInput;
		if (cin.fail()) {
			system("cls");
			cout << "********************************" << endl;
			cout << "**It is not a number,try again**" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (playerInput != 1 && playerInput != 2 && playerInput != 3 && playerInput != 4) {
			system("cls");
			cout << "********************************" << endl;
			cout << "*It is a worry number,try again*" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			system("cls");
			return playerInput;
		}
	}
}

int textFunction::playerInput1(int* arrayOnly) {
		for (int input = 0; input < 16; )
	{
		cout << "*****give me \""<< input + 1 <<"\" number*****" << endl;
		cout << "******one by one by one******" << endl;
		cout << "***within this range: 1~20***" << endl;
		cout << "*****************************" << endl;
		cin >> arrayOnly[input];
		if (cin.fail()) {
			system("cls");
			cout << "********************************" << endl;
			cout << "**It is not a number,try again**" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (arrayOnly[input] < 1 || arrayOnly[input] >20) {
			system("cls");
			cout << "********************************" << endl;
			cout << "*It is a worry number,try again*" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			for (int checkNum = 0; checkNum < input; checkNum++) {
				if (arrayOnly[checkNum] == arrayOnly[input]) {
					system("cls");
					cout << "********************************" << endl;
					cout << "**Number is repeated,try again**" << endl;
					cout << "********************************" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else
				{
					system("cls");
					cin.clear();
					cin.ignore(1024, '\n');
					input++;
				}
			}
		}
	}
	return showArray(arrayOnly);
}

int textFunction::playerInput2(int* arrayOnly) {
	for (int countNum = 0; countNum < 16; countNum++) {
		arrayOnly[countNum] = ((rand() % 20) + 1);
		for (int checkNum = 0; checkNum < countNum; checkNum++) {
			if (arrayOnly[checkNum] == arrayOnly[countNum]) {
				countNum--;
			}
		}
	}
	return showArray(arrayOnly);
}

int textFunction::playerInput3(int* arrayOnly) {
	for (int countNum = 0; countNum < 16; countNum++) {
		arrayOnly[countNum] = countNum + 1;
	}
	return showArray(arrayOnly);
}

int textFunction::showArray(int* arrayOnly) {
	int playNum;
	system("cls");
	for (;;)
	{
		cout << "**********************************" << endl;
		cout << "******so now let us begin ?*******" << endl;
		cout << "******by using this array ?*******" << endl;
		cout << "**********************************" << endl;
		cout << "*********" << arrayOnly[0] << "\t" << arrayOnly[1] << "\t" << arrayOnly[2] << "\t" << arrayOnly[3] << "*********" << endl;
		cout << "*********" << arrayOnly[4] << "\t" << arrayOnly[5] << "\t" << arrayOnly[6] << "\t" << arrayOnly[7] << "*********" << endl;
		cout << "*********" << arrayOnly[8] << "\t" << arrayOnly[9] << "\t" << arrayOnly[10] << "\t" << arrayOnly[11] << "*********" << endl;
		cout << "*********" << arrayOnly[12] << "\t" << arrayOnly[13] << "\t" << arrayOnly[14] << "\t" << arrayOnly[15] << "*********" << endl;
		cout << "**********************************" << endl;
		cout << "****\"1\":yes*******\"2\":back****" << endl;
		cin >> playNum;
		if (cin.fail()) {
			system("cls");
			cout << "********************************" << endl;
			cout << "**It is not a number,try again**" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (playNum != 1 && playNum != 2) {
			system("cls");
			cout << "********************************" << endl;
			cout << "*It is a worry number,try again*" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			return playNum;
		}
	}

}