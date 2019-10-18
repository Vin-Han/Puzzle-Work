#include "coreFunction.h"

void coreFunction::startBegin(int* arrayOnly) {
	this->arrayOnly = arrayOnly;
	oneVector.emplace_back(arrayOnly);
	usefulVector.emplace_back(arrayOnly);
	loopArray(oneVector, twoVector, usefulVector);
}

void coreFunction::loopArray(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector)
{
	getNextLevel(oneVector, twoVector, usefulVector);
	if (oneVector.begin() == oneVector.end() && twoVector.begin() == twoVector.end()) return;
	else { loopArray(twoVector, oneVector, usefulVector); }
}

void coreFunction::getNextLevel(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector) {
	vector<int*>::iterator oneBegin = oneVector.begin();
	for (; oneBegin < oneVector.end(); oneBegin++) {
		moveArray(*oneBegin, twoVector, usefulVector);
	}
	oneVector.clear();
}

void coreFunction::moveArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector) {
	int arrayVer;
	int arrayHor;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			int calculateNum = ((ver + 1) * (hor + 1) - 1);
			if (arrayOnly[calculateNum] == 16) {
				arrayVer = ver;
				arrayHor = hor;
			}
			else
			{
			}
		}
	}
	if (arrayVer != 0) {
		arrayStrUp(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor);
	}
	else {}
	if (arrayVer != 3) {
		arrayStrDown(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor);
	}
	else {}
	if (arrayHor != 0) {
		arrayStrRight(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor);
	}
	else {}
	if (arrayHor != 3) {
		arrayStrLeft(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor);
	}
	else {}
}

bool coreFunction::checkArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector) {
	vector<int*>::iterator usefulBeg = usefulVector.begin();
	for (; usefulBeg < usefulVector.end(); usefulBeg++) {
		for (int checkNum = 0; checkNum < 16; checkNum++) {
			if (arrayOnly[checkNum] != (*usefulBeg)[checkNum]) {
				cout << usefulVector.size() << endl;
				printArray(arrayOnly, usefulVector);
				twoVector.emplace_back(arrayOnly);
				usefulVector.emplace_back(arrayOnly);
				return true;

			}
		}
	}
	return false;
}

void coreFunction::printArray(int* arrayOnly, vector<int*> usefulVector) {
	for (int calculateNum = 0; calculateNum < 16; calculateNum++)
	{
		if ((calculateNum % 4) == 0) {
			cout << endl;
		}
		cout << arrayOnly[calculateNum] << "    ";
	}
	cout << "\n" << usefulVector.size() << "\n\n" << endl;
	cout << "\n\n" << endl;
}

void coreFunction::arrayStrUp(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor) {
	int* arrayUp = new int[16];
	for (int copyNum = 0; copyNum < 16; copyNum++)
	{
		arrayUp[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = (arrayVer + 1) * (arrayHor + 1) - 1;
	int temp2 = arrayVer * (arrayHor + 1) - 1;
	int tempUp = arrayUp[temp1];
	arrayUp[temp1] = arrayUp[temp2];
	arrayUp[temp2] = tempUp;

	if (checkArray(arrayUp, twoVector, usefulVector) == false) {
		delete[]arrayUp;
		arrayUp == NULL;
	}
}
void coreFunction::arrayStrDown(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor) {
	int* arrayDown = new int[16];
	for (int copyNum = 0; copyNum < 16; copyNum++)
	{
		arrayDown[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = (arrayVer + 1) * (arrayHor + 1) - 1;
	int temp2 = (arrayVer + 2) * (arrayHor + 1) - 1;
	int tempUp = arrayDown[temp1];
	arrayDown[temp1] = arrayDown[temp2];
	arrayDown[temp2] = tempUp;

	if (checkArray(arrayDown, twoVector, usefulVector) == false) {
		delete[]arrayDown;
		arrayDown == NULL;
	}
}
void coreFunction::arrayStrRight(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor) {
	int* arrayRight = new int[16];
	for (int copyNum = 0; copyNum < 16; copyNum++)
	{
		arrayRight[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = (arrayVer + 1) * (arrayHor + 1) - 1;
	int temp2 = (arrayVer + 1) * arrayHor - 1;
	int tempUp = arrayRight[temp1];
	arrayRight[temp1] = arrayRight[temp2];
	arrayRight[temp2] = tempUp;

	if (checkArray(arrayRight, twoVector, usefulVector) == false) {
		delete[]arrayRight;
		arrayRight == NULL;
	}
}
void coreFunction::arrayStrLeft(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor) {
	int* arrayLeft = new int[16];
	for (int copyNum = 0; copyNum < 16; copyNum++)
	{
		arrayLeft[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = (arrayVer + 1) * (arrayHor + 1) - 1;
	int temp2 = (arrayVer + 1) * (arrayHor + 2) - 1;
	int tempUp = arrayLeft[temp1];
	arrayLeft[temp1] = arrayLeft[temp2];
	arrayLeft[temp2] = tempUp;

	if (checkArray(arrayLeft, twoVector, usefulVector) == false) {
		delete[]arrayLeft;
		arrayLeft == NULL;
	}
}