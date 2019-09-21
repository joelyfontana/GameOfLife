/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Programming Assignment 2*/

#include <iostream>
#include "Grid.h"

using namespace std;


//default constructor
Grid::Grid(int height,int width)
{
	sizeX = height;
	sizeY = width;
	
	// add make grid to constructor to always call it 
	makeGrid();
}

//overloaded constructor
Grid::Grid(int maxSize)
{
	//EMPTY?!?!?!?!
}

//destructor
Grid::~Grid()
{
	//delete to re-allocate memory and prevent a memory leak
	for (int i = 0; i < sizeX; ++i)
	{
		delete[] gameGrid[i];
	}
	delete[] gameGrid;
}

void Grid::makeGrid() {
	//make a two dimensional dynamic array
	gameGrid = new char* [sizeX];
	for (int row = 0; row < sizeX; ++row)
	{
		gameGrid[row] = new char[sizeY];
		for (int col = 0; col < sizeY; ++col)
		{
			gameGrid[row][col] = '-';
		}
	}
}

//make a method to put the values of the grid into a string
string Grid::getString()
{
	//make a new string 
	string gridString = ""; 
	//iterate through the rows of the array
	for (int row = 0; row < sizeX; ++row)
	{
			for (int col = 0; col < sizeY; ++col)
			{
				gridString += string(1,gameGrid[row][col]);
		}
			gridString += "\n";
	}
	cout << gridString << endl;
	return gridString;
}


