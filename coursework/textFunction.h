#pragma once
#include <iostream>
using namespace std;

class textFunction
{
public:
	int welcomeFace();
	int levelChoise();
	int playerInput1(int* arrayOnly, const int sizeNum);
	int playerInput2(int* arrayOnly, const int sizeNum);
	int playerInput3(int* arrayOnly, const int sizeNum);
	int showArray(int* arrayOnly, const int sizeNum);
};

