#include "fomulaFun.h"

void fomulaFun::start(int* array, int gamelevel) {
	set<int> arrayuse;
	for (int transNum = 0; transNum < (gamelevel * gamelevel); transNum++){
		arrayuse.insert(array[transNum]);
	}
	unsigned long long rowNum = calculate(arrayuse, gamelevel);
	printFomRe(array, gamelevel, rowNum);
}

unsigned long long fomulaFun::calculate(set<int> array, int gamelevel) {
	int variableNum = cherkArray(array, gamelevel);
	int accout;
	unsigned long long row = 0;
	if(gamelevel == 2)	row = (unsigned long long)variableNum * (gamelevel - 1) * factorial((gamelevel * gamelevel - gamelevel - 1));
	else  row = ((unsigned long long)variableNum * (gamelevel - 1) * factorial((gamelevel * gamelevel - gamelevel - 1)) / 2) ;
	return row;
}

int fomulaFun::cherkArray(set<int> array, int gamelevel) {
	int possibleNum = 0;
	set<int>::iterator begIterator = array.begin();
	for (; begIterator != array.end(); begIterator++) {
		for (int i = 1; i < gamelevel; i++) {
			set<int>::iterator cherkIterator = array.find((*begIterator + i));
			if (cherkIterator == array.end()) {
				break;
			}
			else {
				if (i == (gamelevel - 1)) {
					possibleNum++;
				}
			}
		}
	}
	return possibleNum;
}

int fomulaFun::factorial(int gamelevel) {
	return gamelevel * (gamelevel > 1 ? factorial(gamelevel - 1) : 1);
}

void fomulaFun::printFomRe(int* array, int gamelevel, unsigned long long row) {
	for (int useNum = 0; useNum < (gamelevel * gamelevel); useNum++) {
		if(array[useNum] == -1) cout << " " << "\t";
		else cout << array[useNum] << "\t";
		if ((useNum + 1) % gamelevel == 0) cout << endl;
	}
	cout << "row =" << row << "\ncolumn =" << row << "\nrerow =" << row << "\nrecolumn =" << row << endl;
	saveSolution(array,gamelevel,row,row);
}