/*
Joely Fontana
Student ID: 2313535
Data Structures
Section 1
Programming Assignment 2
*/

#include <iostream>
#include <fstream>
#include "File.h"
using namespace std;


File::File(string filePath)
{
	//
	this->filePath = filePath;
}

string File::readFile()
{
	//open the file
	ifstream genFile;
	genFile.open(filePath);

	//checks to make sure that the file name entered is an actual file
	if (!genFile)
	{
		cout << "Not a valid file path. Please enter a valid file path: " << endl;
		cin >> filePath;
	}
}
