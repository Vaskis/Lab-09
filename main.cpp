// Jeremiah Vaskis
// Lab 09
// 12/03/2018

#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;

string getFileName() {
	string name;
	cout << "Enter filename: ";
	cin >> name;
	return name;
}

bool checkOpeness(string file, ifstream& inFile) {
	inFile.open(file); // Try to Open File
	if (!inFile.is_open()) {
		cout << "File: " << file << " cannot be opened." << endl;
		inFile.close();
		inFile.clear();
		return false;
	}
	else {
		cout << "File: " << file << " successfully opened." << endl;
		return true;
	}
}

int main() {

	string fileName, input_string;
	ifstream InFile;
	ofstream OutFile;
	map <string, int> map_object;

	fileName = getFileName();
	
	if (checkOpeness(fileName, InFile)) {
			
		// While can read word out of file into string
		while (!InFile.eof()) {
			InFile >> input_string;
			++map_object[input_string];
		}

		// Close Input File
		InFile.close();

		// for loop that goes acrros the entire map and takes the contents and spits it into output.txt
		OutFile.open("output.txt");

		for (map<string, int>::iterator it = map_object.begin(); it != map_object.end(); ++it) {
			for (int i = 0; i < it->second; i++) {
				OutFile << it->first;
			}
		}

		// Close Output File
		OutFile.close();
	}

	system("pause");
	return 0;
}