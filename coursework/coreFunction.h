#include<iostream>
#include<vector>
using namespace std;
#pragma once

class coreFunction
{
private:
	int* arrayOnly ;
	vector<int*> oneVector;
	vector<int*> twoVector;
	vector<int*> usefulVector;
private:
	void loopArray(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector);
	void getNextLevel(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector);
	void moveArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector);
	void arrayStrUp(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor);
	void arrayStrDown(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor);
	void arrayStrRight(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor);
	void arrayStrLeft(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor);
	bool checkArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector);
	void printArray(int* arrayOnly, vector<int*> usefulVector);
public:
	void startBegin(int* arrayOnly);
};

