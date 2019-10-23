#pragma once
#include"recordUsing.h"
using namespace std;

class textFunction:public recordUsing
{
public:
	int levelChoise();
	int welcomeFace(int puzzleLevel,int* arrayOnly);
	string playerInput4(const int sizeNum,vector<int*> arrayRead);
private:
	int playerInput1(int* arrayOnly, const int sizeNum);
	int playerInput2(int* arrayOnly, const int sizeNum);
	int playerInput3(int* arrayOnly, const int sizeNum);
	int showArray(int* arrayOnly, const int sizeNum);
};

