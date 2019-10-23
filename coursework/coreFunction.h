#pragma once
#include "toolFunction.h"

class coreFunction:public toolFunction
{
private:
	int* arrayOnly;
	vector<int*> oneVector;
	vector<int*> twoVector;
	vector<int*> usefulVector;
private:
	void loopArray(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void getNextLevel(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void moveArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
public:
	void startBegin(int* arrayOnly, const int sizeNum);
};

