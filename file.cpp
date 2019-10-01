/*
Joely Fontana
Student ID: 2313535
Data Structures
Section 1
Programming Assignment 2
*/

/*
#include <iostream>
#include <fstream>
#include "File.h"
#include <string>
using namespace std;

ifstream genFile;
int rowCount = 0;
int colCount = 0;
File::File(string filePath)
{
	//make this file path equal to the other filepath  
	this->filePath = filePath;
}

string File::fileLines(char gridGame)
{
	string line;
	while (getline(genFile, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			gridGame[rowCount][colCount] = line[i];
		}
	}
}



string File::readFile()
{
	string String;
	//open the file
	
	genFile.open(filePath);
	genFile >> String;
	cout << String << endl;

	//checks to make sure that the file name entered is an actual file
	if (!genFile)
	{
		cout << "Not a valid file path. Please enter a valid file path: " << endl;
		cin >> filePath;
	}
}

*/