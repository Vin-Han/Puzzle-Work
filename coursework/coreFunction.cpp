#include "coreFunction.h"

void coreFunction::startBegin(int* arrayOnly, const int sizeNum) {
	this->arrayOnly = arrayOnly;
	oneVector.emplace_back(arrayOnly);
	usefulVector.emplace_back(arrayOnly);
	system("cls");
	loopArray(oneVector, twoVector, usefulVector, sizeNum);
}

void coreFunction::loopArray(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum){
	getNextLevel(oneVector, twoVector, usefulVector, sizeNum);
	if (oneVector.begin() == oneVector.end() && twoVector.begin() == twoVector.end()) {
		toolFunction::printResult(usefulVector, sizeNum); 
		vector<int*>::iterator oneBegin = usefulVector.begin();
		for (; oneBegin != usefulVector.end(); oneBegin++){
			delete[](*oneBegin);
		}
	}
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
	int comeDirection = sizeNum * sizeNum;
	if (arrayOnly[comeDirection] != 2 && arrayOnly[comeDirection + 1] != 0){
		int comeDirection = (sizeNum * sizeNum);
		int* arrayUp = new int[comeDirection + 3];
		for (int copyNum = 0; copyNum < (comeDirection + 3); copyNum++) {
			arrayUp[copyNum] = arrayOnly[copyNum];
		}
		int temp1 = arrayUp[comeDirection + 1] * sizeNum + arrayUp[comeDirection + 2];
		int temp2 = (arrayUp[comeDirection + 1] - 1) * sizeNum + arrayUp[comeDirection + 2];
		int tempUp = arrayUp[temp1];
		arrayUp[temp1] = arrayUp[temp2];
		arrayUp[temp2] = tempUp;
		arrayUp[comeDirection + 1] --;
		arrayUp[comeDirection] = 1;
		if (checkArray(arrayUp, twoVector, usefulVector, sizeNum) == false) {
			delete[]arrayUp;
		}
	}
	if (arrayOnly[comeDirection] != 1 && arrayOnly[comeDirection + 1] != (sizeNum - 1) && arrayOnly[comeDirection] != 0){
		int comeDirection = (sizeNum * sizeNum);
		int* arrayDown = new int[comeDirection + 3];
		for (int copyNum = 0; copyNum < (comeDirection + 3); copyNum++) {
			arrayDown[copyNum] = arrayOnly[copyNum];
		}
		int temp1 = arrayDown[comeDirection + 1] * sizeNum + arrayDown[comeDirection + 2];
		int temp2 = (arrayDown[comeDirection + 1] + 1) * sizeNum + arrayDown[comeDirection + 2];
		int tempUp = arrayDown[temp1];
		arrayDown[temp1] = arrayDown[temp2];
		arrayDown[temp2] = tempUp;
		arrayDown[comeDirection + 1] ++;
		arrayDown[comeDirection] = 2;
		if (checkArray(arrayDown, twoVector, usefulVector, sizeNum) == false) {
			delete[]arrayDown;
		}
	}
	if (arrayOnly[comeDirection] != 4 && arrayOnly[comeDirection + 2] != 0) {
		int comeDirection = (sizeNum * sizeNum);
		int* arrayRight = new int[comeDirection + 3];
		for (int copyNum = 0; copyNum < (comeDirection + 3); copyNum++) {
			arrayRight[copyNum] = arrayOnly[copyNum];
		}
		int temp1 = arrayRight[comeDirection + 1] * sizeNum + arrayRight[comeDirection + 2];
		int temp2 = arrayRight[comeDirection + 1] * sizeNum + arrayRight[comeDirection + 2] - 1;
		int tempUp = arrayRight[temp1];
		arrayRight[temp1] = arrayRight[temp2];
		arrayRight[temp2] = tempUp;
		arrayRight[comeDirection + 2] --;
		arrayRight[comeDirection] = 3;
		if (checkArray(arrayRight, twoVector, usefulVector, sizeNum) == false) {
			delete[]arrayRight;
		}
	}
	if (arrayOnly[comeDirection] != 3 && arrayOnly[comeDirection + 2] != (sizeNum - 1) && arrayOnly[comeDirection] != 0) {
		int comeDirection = (sizeNum * sizeNum);
		int* arrayLeft = new int[comeDirection + 3];
		for (int copyNum = 0; copyNum < (comeDirection + 3); copyNum++) {
			arrayLeft[copyNum] = arrayOnly[copyNum];
		}
		int temp1 = arrayLeft[comeDirection + 1] * sizeNum + arrayLeft[comeDirection + 2];
		int temp2 = arrayLeft[comeDirection + 1] * sizeNum + arrayLeft[comeDirection + 2] + 1;
		int tempUp = arrayLeft[temp1];
		arrayLeft[temp1] = arrayLeft[temp2];
		arrayLeft[temp2] = tempUp;
		arrayLeft[comeDirection + 2] ++;
		arrayLeft[comeDirection] = 4;
		if (checkArray(arrayLeft, twoVector, usefulVector, sizeNum) == false) {
			delete[]arrayLeft;
		}
	}
}