#include "recordUsing.h"

bool recordUsing::openFile(string fileName) {
	ifstream readfile;
	fileName = fileName + ".txt";
	readfile.open(fileName);
	if (!readfile){
		return false;
	}
	readfile.close();
	return true;
}

void recordUsing::dealRecord(string fileName, vector<int*> &array, const int sizeNum) {
	system("cls");
	readRecord(fileName, array, sizeNum);
	printResult(array, sizeNum);
	vector<int*>::iterator oneBegin = array.begin();
	for (; oneBegin != array.end(); oneBegin++) {
		delete[](*oneBegin);
	}
}

void recordUsing::dealSolution(string fileName, vector<int*>& array, const int sizeNum) {
	system("cls");
	string content;
	readSolution(fileName, array, sizeNum,content);
	printResult(array, sizeNum,content);
	vector<int*>::iterator oneBegin = array.begin();
	for (; oneBegin != array.end(); oneBegin++) {
		delete[](*oneBegin);
	}
}

void recordUsing::readRecord(string fileName,vector<int*> &array, const int sizeNum) {
	ifstream readfile;
	readfile.open(fileName + ".txt");
	int arrayNum;
	readfile >> arrayNum;
	for (int nowArray = 1; nowArray <= arrayNum; nowArray++){
		int* arrayuse = new int[(sizeNum * sizeNum)];
		for (int readNum = 0; readNum < (sizeNum * sizeNum) - 1; readNum++){
			readfile >> arrayuse[readNum];
		}
		arrayuse[(sizeNum * sizeNum) - 1] = -1;
		array.push_back(arrayuse);
	}
}

void recordUsing::showRecord(vector<int*> &array, const int sizeNum, int arrayNum) {
	system("cls");
	cout << arrayNum <<"\n"<< endl;
	vector<int*>::iterator begArray = array.begin();
	for (; begArray != array.end(); begArray++){
		for (int nowread = 0; nowread < (sizeNum*sizeNum); nowread++){
			cout << (*begArray)[nowread]<< "\t";
			if ((nowread + 1) % sizeNum == 0) cout << endl;
		}
		cout << "\n" << endl;
	}
}

void recordUsing::remRecord(int* arrayOnly ,int puzzleLevel) {
	string filename;
	cout << "*  [  welcome to puzzleworld  ]  *" << endl;
	cout << "*  [ give me the name of file ]  *" << endl;
	cin >> filename;
	ofstream savefile;
	filename = filename + ".txt";
	savefile.open(filename);
	savefile << "1" << endl;
	for (int saveNum = 0; saveNum < (puzzleLevel * puzzleLevel) - 1; saveNum++) {
		if (arrayOnly[saveNum] == -1) savefile << " " << "\t";
		else savefile << arrayOnly[saveNum] << "\t";
		if ((saveNum + 1) % puzzleLevel == 0) savefile << endl;
	}
	savefile.close();
	system("cls");
	cout << "*  [  success saved  ]  *" << endl;
}

void recordUsing::saveSolution(int* arrayOnly,int puzzleLevel ,int resultrow,int resultcolumn) {
	int playerInput;
	for (;;) {
		cout << "\n**   [  \"1\":save solutionfile  ] *** [  \"2\":quit ]   **" << endl;
		cin >> playerInput;
		cin.clear();
		cin.ignore(1024, '\n');
		if (cin.fail() || playerInput < 1 || playerInput > 2) cout << "\n**[      Input is wrong , try again      ]**\n" << endl;
		else break;
	}
	if (playerInput == 2) return ;
	else {
		string filename;
		cout << "*  [  welcome to puzzleworld  ]  *" << endl;
		cout << "*  [ give me the name of file ]  *" << endl;
		cin >> filename;
		ofstream savefile;
		filename = filename + ".txt";
		savefile.open(filename);
		savefile << "1" << endl;
		for (int saveNum = 0; saveNum < (puzzleLevel * puzzleLevel) - 1; saveNum++) {
			if (arrayOnly[saveNum] == -1) savefile << " " << "\t";
			else savefile << arrayOnly[saveNum] << "\t";
			if ((saveNum + 1) % puzzleLevel == 0) savefile << endl;
		}
		savefile << "\nrow = " << resultrow << endl;
		savefile << "column = " << resultcolumn << endl;
		savefile << "reverse row = " << resultrow << endl;
		savefile << "reverse column = " << resultcolumn << endl;
		savefile.close();
		system("cls");
		cout << "*  [  success saved  ]  *" << endl;
	}
}

void recordUsing::readSolution(string fileName, vector<int*>& array, const int sizeNum, string &content) {
	ifstream readfile;
	readfile.open(fileName + ".txt");
	int arrayNum;
	readfile >> arrayNum;
	for (int nowArray = 1; nowArray <= arrayNum; nowArray++) {
		int* arrayuse = new int[(sizeNum * sizeNum)];
		for (int readNum = 0; readNum < (sizeNum * sizeNum) - 1; readNum++) {
			readfile >> arrayuse[readNum];
		}
		arrayuse[(sizeNum * sizeNum) - 1] = -1;
		array.push_back(arrayuse);
	}
	while (!readfile.eof()) {
		string temp;
		getline(readfile,temp);
		content = content + "\n"  + temp;
	}
}
