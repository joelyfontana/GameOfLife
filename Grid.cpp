/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Programming Assignment 2*/

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "Grid.h"

using namespace std;

//constructor
Grid::Grid(int height, int width, float density, string mode)
{
	sizeX = height;
	sizeY = width;
	this->mode = mode;
	//make density equal to this density
	this->density = density;
	// add make grid to constructor to always call it 
	makeGrid();
}

Grid::Grid(string filePath, string mode)
{
	openFile(filePath);
	this->mode = mode;
}
/*
//next generation constructor (does not need to know the density)
Grid::Grid(int height, int width, string mode, string nextString)
{
	sizeX = height;
	sizeY = width;
	this->mode = mode;
	makeGrid();
	nextGenGrid(nextString);
}
*/

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

//make the game board with correct dimensions
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
	//cout << gridString << endl;
	return gridString;
}

//make a string that holds the next generation
string Grid::nextGenStr()
{
	//cout << "line 89" << endl;
	string nextString = "";
	//iterate through the rows of the array
	for (int row = 0; row < sizeX; ++row)
	{
		for (int col = 0; col < sizeY; ++col)
		{
			//cout << "col" << col << endl;
			//cout << "row" << row << endl;
			//APPLY THE RULES OF THE GAME
			//if a cell has 3 neighbors
			if (countNeighbors(row, col) ==3)
			{
				nextString += string(1, 'X');
			}
			//if a cell has 2 neighbors
			else if (countNeighbors(row, col) == 2 && gameGrid[row][col] == 'X')
			{
				nextString += string(1, 'X');
			}
			//if a cell has one or less neighbors, has 2 but is already empty, or has 4 or more
			else
			{
				nextString += string(1, '-');
			}
		}
	}
	return nextString;
}

//make a funtion to get the density and random positions of the cells
string Grid::getPopulation()
{
	string popString = "";
	int total = sizeX * sizeY;
	//get the amount of X's
	int population = total * density;
	cout << "Total: " << total << " Population: " << population << endl;
	
	//convert the density into number of X's, put them in a string, and shuffle the string
	for (int i = 0; i < population; i++)
	{
		popString += "X";
	}

	//make the rest of the string dashes
	int remain = total - population;
	for (int i = 0; i < remain; i++)
	{
		popString += "-";
	}

	//shuffle the string 
	random_shuffle(popString.begin(), popString.end());
	int counter = 0;
	for (int row = 0; row < sizeX; ++row)
	{
		//gameGrid[row] = new char[sizeY];
		for (int col = 0; col < sizeY; ++col)
		{
			gameGrid[row][col] =popString[counter];
			++counter;
		}
	}
	return popString;
}


//puts the next generation into the array/ grid
void Grid::nextGenGrid(string nextString)
{
	int counter = 0;
	for (int row = 0; row < sizeX; ++row)
	{

		for (int col = 0; col < sizeY; ++col)
		{
			gameGrid[row][col] = nextString[counter];
			++counter;
		}
	}
}

//count a cells neighbors
int Grid::countNeighbors(int row, int col)
{
//	cout << "checking neighbors" << endl;
	int neighbor=0;

	//ERROR HERE

		//checks right of cell
		if (checkNeighbor(row + 1,col) == true)
		{
			neighbor++;
		}
		//checks left of cell
		if (checkNeighbor(row - 1,col) == true)
		{
			neighbor++;
		}
		//checks above cell
		if (checkNeighbor(row, col+1) == true)
		{
			neighbor++;
		}
		//checks below cell
		if (checkNeighbor(row, col-1) == true)
		{
			neighbor++;
		}
		//check bottom left of cell
		if (checkNeighbor(row - 1, col-1) == true)
		{
			neighbor++;
		}
		//check top right of cell
		if (checkNeighbor(row + 1, col+1) == true)
		{
			neighbor++;
		}
		//check top left of cell
		if (checkNeighbor(row - 1, col+1) == true)
		{
			neighbor++;
		}
		//check bottom right of cell
		if (checkNeighbor(row + 1, col-1) == true)
		{
			neighbor++;
		}
		return neighbor;
}

//check to see if the cell is an X first and return true if it is
// MAKE THE DIFFERENT MODES IN THIS FUNCTION
bool Grid::checkNeighbor(int x, int y)
{
	//CLASSIC MODE
	if (mode == "Classic")
	{
		//check to see if the cell is outside the array and return false if it is
		if (x < 0 || y < 0 || x >= sizeX || y >= sizeY)
		{
			return false;
		}
		// if the value is in the grid and an X return true
		else if (gameGrid[x][y] == 'X')
		{
			return true;
		}
		//returns false if the value is in the grid but is not an X
		return false;
	}
	//DOUGHNUT MODE
	if (mode == "Doughnut")
	{
		//check to see if the value is outside the grid
		//if (x < 0 || y < 0 || x >= sizeX || y >= sizeY)
		//{
				//if the value is at the last spot in the grid
			if (x >= sizeX)
			{
				x = 0;
			}
			if (y >= sizeY)
			{
				y = 0;
			}
			//if the value is outside the grid, loop it around to the first value 
			if (x < 0)
			{
				x = sizeX - 1;
			}
			if (y < 0)
			{
				y = sizeY - 1;
			}
			
			if (gameGrid[x][y] == 'X')
			{
				return true; 
			}
		//}

		//if the value already exists in the grid
		else if (gameGrid[x][y] == 'X')
		{
			return true;
		}
		//if the value does not have an X or exist outside the grid
		else 
		{
			return false;
		}

		return false;
	}

	//MIRROR MODE
	if (mode == "Mirror")
	{
		if (x < 0) 
		{
			x = 0;
		}
		if (y < 0)
		{
			y = 0;
		}
		if (x > sizeX - 1)
		{
			x = sizeX - 1;
		}
		if (y > sizeY - 1)
		{
			y = sizeY - 1;
		}
		if (gameGrid[x][y] == 'X')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

string Grid::openFile(string filePath)
{
	ifstream mapFile;
	string line;
	mapFile.open(filePath);
	string strRow, strCol = "";
	getline(mapFile, strRow);
	getline(mapFile, strCol);
	sizeX = stoi(strRow);
	cout << "sizeX: " << sizeX << endl;
	sizeY = stoi(strCol);
	cout << "sizeY: " << sizeY << endl;
	int rowCount = 0;
	int colCount = 0;

	makeGrid();

	while (getline(mapFile, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			gameGrid[rowCount][colCount] = line[i];
			colCount++;
		}
	
		rowCount++;
		colCount = 0;
	}
	mapFile.close();
	return filePath;
}




