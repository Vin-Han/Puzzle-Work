#include<iostream>
#include<vector>
using namespace std;
#pragma once

class coreFunction
{
private:
	int* arrayOnly;
	vector<int*> oneVector;
	vector<int*> twoVector;
	vector<int*> usefulVector;
	int row;
	int column;
	int reverseRow;
	int reverseColumn;
private:
	void loopArray(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void getNextLevel(vector<int*>& oneVector, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void moveArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void arrayStrUp(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum);
	void arrayStrDown(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum);
	void arrayStrRight(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum);
	void arrayStrLeft(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int& arrayVer, const int& arrayHor, const int sizeNum);
	bool checkArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void printArray(int* arrayOnly, const int sizeNum);
public:
	void startBegin(int* arrayOnly, const int sizeNum);
};

