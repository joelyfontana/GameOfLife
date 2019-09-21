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
	Grid(int height, int width);
	//overloaded constructor 
	Grid(int maxSize);
	//destructor
	~Grid();

	//methods
	void makeGrid();
	string getString();

	//variables
	int sizeX;
	int sizeY;

	//make slash declare the array 
	char** gameGrid;
};