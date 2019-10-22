#include "coreFunction.h"

void coreFunction::startBegin(int* arrayOnly, const int sizeNum) {
	this->arrayOnly = arrayOnly;
	oneVector.emplace_back(arrayOnly);
	usefulVector.emplace_back(arrayOnly);
	printArray(arrayOnly, sizeNum);
	loopArray(oneVector, twoVector, usefulVector, sizeNum);
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
	if (arrayOnly[(sizeNum * sizeNum) + 1] != 0 && arrayOnly[(sizeNum * sizeNum)] != 2) {
		arrayStrUp(arrayOnly, twoVector, usefulVector, sizeNum);
	}
	else {}
	if (arrayOnly[(sizeNum * sizeNum) + 1] != (sizeNum - 1) && arrayOnly[(sizeNum * sizeNum)] != 1 && arrayOnly[(sizeNum * sizeNum)] != 0) {
		arrayStrDown(arrayOnly, twoVector, usefulVector, sizeNum);
	}
	else {}
	if (arrayOnly[(sizeNum * sizeNum) + 2] != 0 && arrayOnly[(sizeNum * sizeNum)] != 4) {
		arrayStrRight(arrayOnly, twoVector, usefulVector,sizeNum);
	}
	else {}
	if (arrayOnly[(sizeNum * sizeNum) + 2] != (sizeNum - 1) && arrayOnly[(sizeNum * sizeNum)] != 3 && arrayOnly[(sizeNum * sizeNum)] != 0) {
		arrayStrLeft(arrayOnly, twoVector, usefulVector, sizeNum);
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

void coreFunction::arrayStrUp(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector,const int sizeNum) {
	int* arrayUp = new int[(sizeNum * sizeNum) + 3];
	for (int copyNum = 0; copyNum < ((sizeNum * sizeNum) + 3); copyNum++)
	{
		arrayUp[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayUp[(sizeNum * sizeNum) + 1] * sizeNum + arrayUp[(sizeNum * sizeNum) + 2];
	int temp2 = (arrayUp[(sizeNum * sizeNum) + 1] - 1) * sizeNum + arrayUp[(sizeNum * sizeNum) + 2];
	int tempUp = arrayUp[temp1];
	arrayUp[temp1] = arrayUp[temp2];
	arrayUp[temp2] = tempUp;
	arrayUp[(sizeNum * sizeNum) + 1] = arrayUp[(sizeNum * sizeNum) + 1] - 1;
	arrayUp[(sizeNum * sizeNum)] = 1;
	if (checkArray(arrayUp, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayUp;
	}
}
void coreFunction::arrayStrDown(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	int* arrayDown = new int[(sizeNum * sizeNum) + 3];
	for (int copyNum = 0; copyNum < ((sizeNum * sizeNum) + 3); copyNum++)
	{
		arrayDown[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayDown[(sizeNum * sizeNum) + 1] * sizeNum + arrayDown[(sizeNum * sizeNum) + 2];
	int temp2 = (arrayDown[(sizeNum * sizeNum) + 1] + 1) * sizeNum + arrayDown[(sizeNum * sizeNum) + 2];
	int tempUp = arrayDown[temp1];
	arrayDown[temp1] = arrayDown[temp2];
	arrayDown[temp2] = tempUp;
	arrayDown[(sizeNum * sizeNum) + 1] = arrayDown[(sizeNum * sizeNum) + 1] + 1;
	arrayDown[(sizeNum * sizeNum)] = 2;
	if (checkArray(arrayDown, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayDown;
	}
}
void coreFunction::arrayStrRight(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	int* arrayRight = new int[(sizeNum * sizeNum) + 3];
	for (int copyNum = 0; copyNum < ((sizeNum * sizeNum) + 3); copyNum++)
	{
		arrayRight[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayRight[(sizeNum * sizeNum) + 1] * sizeNum + arrayRight[(sizeNum * sizeNum) + 2];
	int temp2 = arrayRight[(sizeNum * sizeNum) + 1] * sizeNum + arrayRight[(sizeNum * sizeNum) + 2] - 1;
	int tempUp = arrayRight[temp1];
	arrayRight[temp1] = arrayRight[temp2];
	arrayRight[temp2] = tempUp;
	arrayRight[(sizeNum * sizeNum) + 2] = arrayRight[(sizeNum * sizeNum) + 2] - 1;
	arrayRight[(sizeNum * sizeNum)] = 3;
	if (checkArray(arrayRight, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayRight;
	}
}
void coreFunction::arrayStrLeft(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	int* arrayLeft = new int[(sizeNum * sizeNum) + 3];
	for (int copyNum = 0; copyNum < ((sizeNum * sizeNum) + 3); copyNum++)
	{
		arrayLeft[copyNum] = arrayOnly[copyNum];
	}
	int temp1 = arrayLeft[(sizeNum * sizeNum) + 1] * sizeNum + arrayLeft[(sizeNum * sizeNum) + 2];
	int temp2 = arrayLeft[(sizeNum * sizeNum) + 1] * sizeNum + arrayLeft[(sizeNum * sizeNum) + 2] + 1;
	int tempUp = arrayLeft[temp1];
	arrayLeft[temp1] = arrayLeft[temp2];
	arrayLeft[temp2] = tempUp;
	arrayLeft[(sizeNum * sizeNum) + 2] = arrayLeft[(sizeNum * sizeNum) + 2] + 1;
	arrayLeft[(sizeNum * sizeNum)] = 4;
	if (checkArray(arrayLeft, twoVector, usefulVector, sizeNum) == false) {
		delete[]arrayLeft;
	}
}
