#include "textFunction.h"

int textFunction::welcomeFace() {
	system("cls");
	int playerInput;
	for (;;) {
		cout << "*****welcome to puzzleworld*****" << endl;
		cout << "******choose one play mode******" << endl;
		cout << "***************************************************************" << endl;
		cout << "***I want to use the number I like*** please input \"1\"      ***" << endl;
		cout << "***I want to use the random number** please input \"2\"       ***" << endl;
		cout << "***I want to use the order number \"1~15\"*** please input \"3\"***" << endl;
		cout << "***I want to quit the game*** please input \"4\"              ***" << endl;
		cout << "***************************************************************" << endl;
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

int textFunction::levelChoise() {
	for (;;)
	{
		int puzzleLevel;
		cout << "*****welcome to puzzleworld*****" << endl;
		cout << "****choose one level to play****" << endl;
		cout << "*****\"1\" use a 2*2 puzzle*****" << endl;
		cout << "*****\"2\" use a 3*3 puzzle*****" << endl;
		cout << "*****\"3\" use a 4*4 puzzle*****" << endl;
		cin >> puzzleLevel;
		if (cin.fail()) {
			system("cls");
			cout << "********************************" << endl;
			cout << "**It is not a number,try again**" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (puzzleLevel != 1 && puzzleLevel != 2 && puzzleLevel != 3) {
			system("cls");
			cout << "********************************" << endl;
			cout << "*It is a worry number,try again*" << endl;
			cout << "********************************" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (puzzleLevel == 1)
			{
				system("cls");
				return 2;
			}
			else if (puzzleLevel == 2)
			{
				system("cls");
				return 3;
			}
			else if (puzzleLevel == 3)
			{
				system("cls");
				return 4;
			}
		}
	}
}

int textFunction::playerInput1(int* arrayOnly, const int sizeNum) {
	for (int input = 0; input < ((sizeNum * sizeNum) - 1); )
	{
		cout << "*****give me \"" << (input + 1) << "/" << (sizeNum * sizeNum) << "\" number*****" << endl;
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
			if (input == 0) {
				system("cls");
				cin.clear();
				cin.ignore(1024, '\n');
				input++;
			}
			else {
				int nowinput = input;
				system("cls");
				cin.clear();
				cin.ignore(1024, '\n');
				for (int checkNum = 0; checkNum < nowinput; checkNum++) {
					if (arrayOnly[checkNum] == arrayOnly[input]) {
						cout << "********************************" << endl;
						cout << "**Number is repeated,try again**" << endl;
						cout << "********************************" << endl;
						break;
					}
					else {
						input = nowinput + 1;
					}
				}
			}
		}
	}
	arrayOnly[(sizeNum * sizeNum) - 1] = 0;
	arrayOnly[(sizeNum * sizeNum)] = 0;
	arrayOnly[(sizeNum * sizeNum) + 1] =(sizeNum - 1);
	arrayOnly[(sizeNum * sizeNum) + 2] =(sizeNum - 1);
	return showArray(arrayOnly, sizeNum);
}

int textFunction::playerInput2(int* arrayOnly, const int sizeNum) {
	for (int countNum = 0; countNum < (sizeNum * sizeNum); countNum++) {
		arrayOnly[countNum] = ((rand() % (sizeNum * (sizeNum + 1))) + 1);
		for (int checkNum = 0; checkNum < countNum; checkNum++) {
			if (arrayOnly[checkNum] == arrayOnly[countNum]) {
				countNum--;
			}
		}
	}
	arrayOnly[(sizeNum * sizeNum) - 1] = 0;
	arrayOnly[(sizeNum * sizeNum)] = 0;
	arrayOnly[(sizeNum * sizeNum) + 1] = (sizeNum - 1);
	arrayOnly[(sizeNum * sizeNum) + 2] = (sizeNum - 1);
	return showArray(arrayOnly, sizeNum);
}

int textFunction::playerInput3(int* arrayOnly, const int sizeNum) {
	for (int countNum = 0; countNum < (sizeNum*sizeNum); countNum++) {
		arrayOnly[countNum] = countNum + 1;
	}
	arrayOnly[(sizeNum * sizeNum) - 1] = 0;
	arrayOnly[(sizeNum * sizeNum)] = 0;
	arrayOnly[(sizeNum * sizeNum) + 1] = (sizeNum - 1);
	arrayOnly[(sizeNum * sizeNum) + 2] = (sizeNum - 1);
	return showArray(arrayOnly, sizeNum);
}

int textFunction::showArray(int* arrayOnly, const int sizeNum) {
	int playNum;
	system("cls");
	for (;;){
		cout << "**********************************" << endl;
		cout << "******so now let us begin ?*******" << endl;
		cout << "******by using this array ?*******" << endl;
		cout << "**********************************" << endl;
		for (int genNumA = 0; genNumA < (sizeNum*sizeNum); genNumA++) {
			if ((genNumA % sizeNum) == 0)
			{
				cout << "*********";
			}
			cout << arrayOnly[genNumA] << "\t";
			if (((genNumA + 1) % sizeNum) == 0)
			{
				cout << "*********" << endl;
			}
		}
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