/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Programming Assignment 2*/


#include <chrono>
#include <thread>
#include <stdio.h>
#include "Grid.h"
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//declare variables
string answer = "";
string mode = "";
string input = "";
int height;
int width;
int neighbor;
float density = 0;
int xC, yC;
int row, col;
string filePath;
string stringArray[3];

//Grid gameGrid(height, width, density, mode);
int main(int argc, char** argv)
{
	//ask the user what mode they would like to play
	cout << "Welcome to the Game of Life! Would you like to play Classic Mode, Doughnut Mode, or Mirror Mode?: " << endl;
	cin >> mode;

	//get random to shuffle the string in the Grid.cpp
	srand(time(NULL));
	//ask the user if they would like to use a random file or a map file
	cout << "Would you like to provide a map file or a random assignment?"<<endl;
	cin >> answer;

	if (answer == "map")
	{
		cout << "Please enter the file path: " << endl;
		cin >> filePath;
		cout << "File Path: " << filePath << endl;
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

	//ask the user what the want the hell they want between generations (back in my day, we didn't have pauses between generations)
	cout << "Would you like to pause between generations, press the enter key between generations, or output the generations to a file? (Please enter either 'pause','enter', or 'output'): " << endl;
	cin >> input;
	
	//make new pointers
	Grid* currentGen;

	//if the user chooses random, shuffle the grid
	if (answer == "random")
	{
		currentGen= new Grid(height, width, density, mode);
		currentGen->getPopulation();
	}

	//do not shuffle the grid if the map is chosen, instead set the height and width
	else 
	{
		currentGen = new Grid(filePath, mode);
		height = currentGen ->sizeX;
		width = currentGen->sizeY;
	}
	Grid* newGen;
	string firstString = currentGen->getString();
	cout << "Generation #0: \n" << firstString << endl;

	//for the while loop
	bool repeat = true;
	int genCount = 1;
	//for the press enter before each generation
	getchar();

	if (input == "output")
	{
		ofstream outfile("lifeFile.out");
		outfile << "Generation #0" << endl;

		outfile << firstString << endl;
		cout << firstString << endl;
	}
	else
	{
		cout << firstString << endl;
	}

	while (repeat ==true)
	{
		cout << "Generation #" << genCount << endl;
		string nString = currentGen -> nextGenStr();
		//use the newGeneration constructor 
		newGen = new Grid(height, width, density, mode);
		newGen->nextGenGrid(nString);
		string outputNewGen = newGen->getString();
		//print out the new generation
		cout <<outputNewGen << endl;
		
		//checks to see if the grids have stabilized
		//make a string array that holds three strings
		stringArray[genCount % 3] = nString;
		stringArray[(genCount + 1) % 3] = outputNewGen;
		//iterate through the strings to see if they are equal
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				//ignore the first two because they will always be equal
				if (i == j)
				{
					continue;
				}
				//if the strings are equal, end the game
				if (stringArray[i] == stringArray[j]) 
				{
					repeat = false;
					break;
				}
			}
		}
		if (repeat == false)
		{
			break;
		}
		//check to see if the grid is not all dashes and if they are not repeating
		if (outputNewGen.find('X') || firstString != outputNewGen)
		{
			//delete the old generation
			currentGen ->~Grid();
			//make the new generation the current generation
			currentGen = newGen;
		}
		else 
		{
			cout << "killed" << endl;
			repeat = false;
		}

		//what to do between generations
		//pauses between generations
		if (input == "pause")
		{
			sleep_for(seconds(2));
		}
		//must press enter between generations
		else if (input == "enter")
		{
			cout << "Please press enter to continue to the next generation" << endl;
			getchar();
		}
		//prints to an output file
		else if (input == "output")
		{
			ofstream outfile("lifeFile.out", ofstream::app);
			outfile << "Generation# " << genCount << endl;
			outfile << outputNewGen << endl;
			outfile.close();
		}
		//if neither option is selected
		else
		{
			cout << "please enter either 'pause', 'enter' or 'output': " << endl;
			cin >> input;
		}
		genCount++;
	}

	return 0;
}
