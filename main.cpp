/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Programming Assignment 2*/

#include "Grid.h"
#include "file.h"

//declare variables
string answer = "";
int height;
int width;
string filePath;

int main(int argc, char** argv)
{
	cout << "Welcome to the Game of Life. Would you like to provide a map file or a random assignment?"<<endl;
	cin >> answer;
	cout << answer << endl;
	//if user wants to use a map file
	if (answer == "map")
	{
		cout << "Please enter the file path: " << endl;
		cin >> filePath;
		File mapFile(filePath);
		//INSERT FILE CLASS METHOD SHIT
	}
	//if user wants a random assignment 
	else if (answer == "random assignment")
	{
		cout << "Please enter the dimensions of the world (height, width): " << endl;
		cin >> height >> width;
	}
	//if user does not type either option (im looking at you dr. german)
	else
	{
		cout << "please enter either 'map file' or 'random assignment': " << endl;
		cin >> answer;
	}

	//make a grid object 
	Grid  gameGrid(3, 3);
	gameGrid.makeGrid();
	gameGrid.getString();

	return 0;
}
