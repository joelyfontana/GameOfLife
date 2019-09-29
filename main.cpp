/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Programming Assignment 2*/

#include "Grid.h"
#include "file.h"
#include <time.h>

//declare variables
string answer = "";
string mode = "";
int height;
int width;
int neighbor;
float density = 0;
int xC, yC;
int row, col;
string filePath;

int main(int argc, char** argv)
{
	//ask the user what mode they would like to play
	cout << "Welcome to the Game of Life. Would you like to play Classic Mode, Doughnut Mode, or Mirror Mode?: " << endl;
	cin >> mode;
	if (mode == "Classic")
	{
		cout << "You have chosen Classic Mode" << endl;
	}

	//get random to shuffle the string in the Grid.cpp
	srand(time(NULL));
	cout << "Would you like to provide a map file or a random assignment?"<<endl;
	cin >> answer;
	//cout << answer << endl;

	//use a while loop to see if the input is correct or not and ajust accordingly 
	//WHYYYYYYYY DOES THIS ALWAYS HAPPEN EVEN WHEN ANSWER IS MAP OR RANDOM im too hungover for this shit 
	
	/*while (answer != "map" || answer != "random")
	{
		//if user does not type either option (im looking at you german)
		cout << "please enter either 'map file' or 'random assignment': " << endl;
		cin >> answer;
		break;
	}
	*/ 

	if (answer == "map")
	{
		cout << "Please enter the file path: " << endl;
		cin >> filePath;
		cout << filePath << endl;
		File mapFile(filePath);
	}
	//if user wants a random assignment 
	else if (answer == "random")
	{
		cout << "Please enter the height: " << endl;
		cin >> height;
		cout << "Please enter the width: " << endl;
		cin >> width;
		cout << "Please enter the density (a decimal between 0 and 1): " << endl;
		cin >> density;
		if (density < 0 || density > 1)
		{
			cout << "Please enter a density between 0 and 1: " << endl;
			cin >> density;
		}
		cout << height << "," << width << "," << density << endl;
	}


	//make a grid object 
	Grid gameGrid(height, width, density, mode);
	gameGrid.getPopulation();
	cout << "getString: \n" << gameGrid.getString() << endl;
	int numN = gameGrid.countNeighbors(0,0);
	cout << "neighbors: " << numN << endl;
	string nextGen = gameGrid.nextGenStr();
	cout << "Next Gen String" << nextGen << endl;
	Grid nextGeneration(height, width, mode, nextGen);
	cout << "nextGenGrid: " << nextGeneration.nextGenGrid();
	return 0;
}
