#include "toolFunction.h"

bool toolFunction::checkArray(int* arrayOnly, vector<int*>& twoVector, vector<int*>& usefulVector, const int sizeNum) {
	vector<int*>::iterator usefulBeg = usefulVector.begin();
	int maxSize = sizeNum * sizeNum;
	for (; usefulBeg != usefulVector.end(); usefulBeg++) {
			for (int checkNum = (maxSize -1); checkNum > 0; ) {
				if (arrayOnly[checkNum] != (*usefulBeg)[checkNum]) break;
				checkNum--;
				if (checkNum == 0) return false;
			}
	}
	twoVector.push_back(arrayOnly);
	usefulVector.push_back(arrayOnly);
	return true;
}


void toolFunction::printResult(vector<int*>& usefulVector, const int sizeNum) {
	int row = 0;
	int rerow = 0;
	int colunm = 0;
	int recolunm = 0;
	int attayCount = 0;
	vector<int*>::iterator begVector = usefulVector.begin();
	for (; begVector != usefulVector.end(); begVector++) {
		if ((*begVector)[(sizeNum* sizeNum) - 1] == -1){
			calculateAmount((*begVector),row,colunm,rerow,recolunm,sizeNum);
			for (int calculatenum = 0; calculatenum < (sizeNum * sizeNum); calculatenum++){
				if ((calculatenum % sizeNum) == 0) cout << endl;
				if ((*begVector)[calculatenum] == -1) cout << " " << "    ";
				else cout << (*begVector)[calculatenum] << "    ";
			}
			cout << "\n\n" << "row = " << row << "\n" << "colunm = " << colunm<<"\n" << "rerow = " << rerow<<"\n" << "recolunm = " << recolunm << endl;
		}
	}
}

void toolFunction::calculateAmount(int*array , int &row, int &colunm ,int & rerow,int & recolunm,int sizeNum) {
	for (int cherkVerNum = 0; cherkVerNum < sizeNum; cherkVerNum++) {
		for (int cherkHorNum = 0; cherkHorNum < (sizeNum - 1); cherkHorNum++) {
			if ((array[(cherkVerNum * sizeNum) + cherkHorNum] + 1) != array[(cherkVerNum * sizeNum) + cherkHorNum + 1]) break;
			else if (cherkHorNum == (sizeNum - 2)) row++;
		}
	}
	for (int cherkHorNum = 0; cherkHorNum < sizeNum; cherkHorNum++) {
		for (int cherkVerNum = 0; cherkVerNum < (sizeNum - 1); cherkVerNum++) {
			if ((array[(cherkVerNum * sizeNum) + cherkHorNum] + 1) != array[((cherkVerNum + 1) * sizeNum) + cherkHorNum]) {
				break;
			}
			else {
				if (cherkHorNum == (sizeNum - 2)) {
					colunm++;
				}
			}
		}
	}
	for (int cherkVerNum = 0; cherkVerNum < sizeNum; cherkVerNum++) {
		for (int cherkHorNum = 0; cherkHorNum < (sizeNum - 1); cherkHorNum++) {
			if (array[(cherkVerNum * sizeNum) + cherkHorNum] != (array[(cherkVerNum * sizeNum) + cherkHorNum + 1] + 1)) {
				break;
			}
			else {
				if (cherkHorNum == (sizeNum - 2)) {
					rerow++;
				}
			}
		}
	}
	for (int cherkHorNum = 0; cherkHorNum < sizeNum; cherkHorNum++) {
		for (int cherkVerNum = 0; cherkVerNum < (sizeNum - 1); cherkVerNum++) {
			if (array[(cherkVerNum * sizeNum) + cherkHorNum] != (array[((cherkVerNum + 1) * sizeNum) + cherkHorNum] + 1)) {
				break;
			}
			else {
				if (cherkHorNum == (sizeNum - 2)) {
					recolunm++;
				}
			}
		}
	}
}

void toolFunction::printResult(vector<int*>& usefulVector, const int sizeNum,string content) {
	vector<int*>::iterator begVector = usefulVector.begin();
	for (; begVector != usefulVector.end(); begVector++) {
		if ((*begVector)[(sizeNum * sizeNum) - 1] == -1) {
			for (int calculatenum = 0; calculatenum < (sizeNum * sizeNum); calculatenum++) {
				if ((calculatenum % sizeNum) == 0) cout << endl;
				if ((*begVector)[calculatenum] == -1) cout << " " << "    ";
				else cout << (*begVector)[calculatenum] << "    ";
			}
		}
		cout << endl;
	}
	cout <<content << endl;
}