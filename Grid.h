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
	Grid(int height, int width, string mode, string nextString);
	//destructor
	~Grid();

	//methods
	void makeGrid();
	string getString();
	string getPopulation();
	int countNeighbors(int row, int col);
	bool checkNeighbor(int x, int y);
	string nextGenStr();
	void nextGenGrid(string nextString);

	//variables
	int sizeX;
	int sizeY;
	float density;
	//string gridString = "";
//	string popString = "";
	string mode = "";

	//make slash declare the array 
	char** gameGrid;
};