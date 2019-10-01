/*
Joely Fontana
Student ID: 2313535
Data Structures
Section 1
Programming Assignment 2
*/

#include <iostream>
using namespace std;

class Grid
{
public:
	//constructor
	Grid(int height, int width, float population, string mode);
	//next generation constructor 
	Grid(string filePath, string mode);
	//destructor
	~Grid();

	//methods
	void makeGrid();
	string getString();
	string getPopulation();
	int countNeighbors(int row, int col);
	bool checkNeighbor(int x, int y);
	string openFile(string filePath);
	string nextGenStr();
	void nextGenGrid(string nextString);

	//variables
	int sizeX;
	int sizeY;
	float density;
	string mode = "";

	// make/declare the array 
	char** gameGrid;
};