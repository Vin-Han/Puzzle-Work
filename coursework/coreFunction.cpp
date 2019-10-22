#include "coreFunction.h"

void coreFunction::startBegin(int* arrayOnly, const int sizeNum) {
	this->arrayOnly = arrayOnly;
	oneVector.emplace_back(arrayOnly);
	usefulVector.emplace_back(arrayOnly);
	printArray(arrayOnly, sizeNum);
	loopArray(oneVector, twoVector, usefulVector, sizeNum);
	row = 0;
	column = 0;
	reverseRow = 0;
	reverseColumn = 0;
}

void coreFunction::loopArray(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum)
{
	getNextLevel(oneVector, twoVector, usefulVector, sizeNum);
	if (oneVector.begin() == oneVector.end() && twoVector.begin() == twoVector.end()) { system("pause"); return; }
	else { loopArray(twoVector, oneVector, usefulVector, sizeNum); }
}

void coreFunction::getNextLevel(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	vector<int*>::iterator oneBegin = oneVector.begin();
	for (; oneBegin < oneVector.end(); oneBegin++) {
		moveArray(*oneBegin, twoVector, usefulVector, sizeNum);
	}
	oneVector.clear();
}

void coreFunction::moveArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	int arrayVer = 0;
	int arrayHor = 0;
	for (int ver = 0; ver < sizeNum; ver++) {
		for (int hor = 0; hor < sizeNum; hor++) {
			int calculateNum = (ver * sizeNum + hor);
			if (arrayOnly[calculateNum] == 0) {
				arrayVer = ver;
				arrayHor = hor;
			}
			else {}
		}
	}
	if (arrayVer != 0) {
		arrayStrUp(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor, sizeNum);
	}
	else {}
	if (arrayVer != (sizeNum - 1)) {
		arrayStrDown(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor, sizeNum);
	}
	else {}
	if (arrayHor != 0) {
		arrayStrRight(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor, sizeNum);
	}
	else {}
	if (arrayHor != (sizeNum - 1)) {
		arrayStrLeft(arrayOnly, twoVector, usefulVector, arrayVer, arrayHor, sizeNum);
	}
	else {}
}

bool coreFunction::checkArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	vector<int*>::iterator usefulBeg = usefulVector.begin();
	int maxSize = sizeNum * sizeNum;
	for (; usefulBeg != usefulVector.end(); usefulBeg++) {
		for (int checkNum = 0; checkNum < maxSize; ) {
			if (arrayOnly[checkNum] != (*usefulBeg)[checkNum]) {
				checkNum = maxSize;
			}
			else {
				checkNum++;
				if (checkNum == maxSize) {
					return false;
				}
			}
		}
	}
	cout << usefulVector.size() + 1 << endl;
	//printArray(arrayOnly, sizeNum);
	twoVector.push_back(arrayOnly);
	usefulVector.push_back(arrayOnly);
	return true;
}

void coreFunction::printArray(int* arrayOnly, const int sizeNum) {
	if (arrayOnly[(sizeNum * sizeNum) - 1] == 0)
	{
		for (int calculatenum = 0; calculatenum < (sizeNum * sizeNum); calculatenum++)
		{
			if ((calculatenum % sizeNum) == 0) {
				cout << endl;
			}
			cout << arrayOnly[calculatenum] << "    ";
		}
		cout << endl;
		cout << "\t\t" << usefulVector.size() + 1 << "\n\n" << endl;
	}
}

void coreFunction::arrayStrUp(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum) {
	int* arrayUp = new int[(sizeNum * sizeNum)];
	for (int copyNum = 0; copyNum < (sizeNum * sizeNum); copyNum++)
	{
		arrayUp[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayVer * sizeNum + arrayHor;
	int temp2 = (arrayVer - 1) * sizeNum + arrayHor;
	int tempUp = arrayUp[temp1];
	arrayUp[temp1] = arrayUp[temp2];
	arrayUp[temp2] = tempUp;
	if (checkArray(arrayUp, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayUp;
	}
}
void coreFunction::arrayStrDown(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum) {
	int* arrayDown = new int[(sizeNum * sizeNum)];
	for (int copyNum = 0; copyNum < (sizeNum * sizeNum); copyNum++)
	{
		arrayDown[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayVer * sizeNum + arrayHor;
	int temp2 = (arrayVer + 1) * sizeNum + arrayHor;
	int tempUp = arrayDown[temp1];
	arrayDown[temp1] = arrayDown[temp2];
	arrayDown[temp2] = tempUp;
	if (checkArray(arrayDown, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayDown;
	}
}
void coreFunction::arrayStrRight(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum) {
	int* arrayRight = new int[(sizeNum * sizeNum)];
	for (int copyNum = 0; copyNum < (sizeNum * sizeNum); copyNum++)
	{
		arrayRight[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayVer * sizeNum + arrayHor;
	int temp2 = arrayVer * sizeNum + arrayHor - 1;
	int tempUp = arrayRight[temp1];
	arrayRight[temp1] = arrayRight[temp2];
	arrayRight[temp2] = tempUp;
	if (checkArray(arrayRight, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayRight;
	}
}
void coreFunction::arrayStrLeft(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum) {
	int* arrayLeft = new int[(sizeNum * sizeNum)];
	for (int copyNum = 0; copyNum < (sizeNum * sizeNum); copyNum++)
	{
		arrayLeft[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayVer * sizeNum + arrayHor;
	int temp2 = arrayVer * sizeNum + arrayHor + 1;
	int tempUp = arrayLeft[temp1];
	arrayLeft[temp1] = arrayLeft[temp2];
	arrayLeft[temp2] = tempUp;
	if (checkArray(arrayLeft, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayLeft;
	}
}
