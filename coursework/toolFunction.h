#pragma once
#include<vector>
#include<iostream>
using namespace std;

class toolFunction
{
public:
	bool checkArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum);
	void printResult(vector<int*>& usefulVector, const int sizeNum, string content);
	void printResult(vector<int*>& usefulVector, const int sizeNum);
	void calculateAmount(int* array, int& row, int& colunm, int& rerow, int& recolunm,int sizeNum);
};

