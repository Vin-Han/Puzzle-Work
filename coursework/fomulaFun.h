#pragma once
#include<set>
#include"recordUsing.h"

class fomulaFun:public recordUsing {
private:
	unsigned long long calculate(set<int> array, int gamelevel);
	int cherkArray(set<int> array, int gamelevel);
	int factorial(int gamelevel);
	void printFomRe(int* array, int gamelevel, unsigned long long result);
public:
	void start(int* array, int gamelevel);
};

