#pragma once
#include <fstream>
#include<string>
#include "toolFunction.h"

class recordUsing:public toolFunction
{
private:
	void readRecord(string fileName, vector<int*> &array, const int sizeNum);
	void showRecord(vector<int*> &array, const int sizeNum, int arrayNum);
public:
	bool openFile(string fileName);
	void dealRecord(string fileName, vector<int*> &array, const int sizeNum);
	void remRecord(int* arrayOnly, int puzzleLevel);
	void saveSolution(int* arrayOnly, int puzzleLevel, int resultrow, int resultcolumn);
	void dealSolution(string fileName, vector<int*>& array, const int sizeNum);
	void readSolution(string fileName, vector<int*>& array, const int sizeNum, string &content);
};