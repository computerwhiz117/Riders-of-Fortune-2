// Riders of Fortune 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int = 8;
const int = 8;
char gameBoard[rows][columns];

void drawBoard(int, int);
void changePosition(int &, int &, int &);

int main()
{
	int i;
	int fight;
	int Yarra = 100;
	int *weapon;
	int battle;
	int *XP;
	int *HP;
	int attack = 0;
	int enemy = 5;
    cout << "Welcome to Riders of Fortune 2.0. Choose to:\n";
	cout << "1. Start a new game";
	cout << "2. Load a Saved Game";
	cin >> i;

	if (i == 1)
	{
		//ifstream myfile;
		//myfile.open("saveGame.txt")
			//myfile << "Saving your game.\n";
		//myfile.close();

		cout << "After you obtained the Chalice of Knowledge, you decided to explore a new dungeoun but you enter in you encountered new enemies and monsters." << endl;
		cout << "Your adventure begins";
		cout << "Riders of Fortune 2.0";

		int spacesToMove = 0;
		//Default the position of our game piece
		int positionX = 0;
		int positionY = 0;

		//Draw the board
		drawBoard(positionX, positionY);
		while (spacesToMove != -1) {

			cout << "Pick your move" << endl;
			cin >> spacesToMove;

			if (spacesToMove > 0) {
				changePosition(positionX, positionY, spacesToMove);
				drawBoard(positionX, positionY);
			}
		}
		return 0;
	}

	void changePosition(int &positionX, int &positionY, int spacesToMove) {
		while (spacesToMove > 0)
		{
			//position is in the first row and moving right
			if (spacesToMove > 0 && positionX == 0 && positionY != 7) {
				if (positionY + spacesToMove >= columns) {
					spacesToMove = spacesToMove - (columns - (positionY + 1));
					positionY = 7;
				}
				else {
					positionY = positionY + spacesToMove;
					spacesToMove = 0;
				}
			}
			//position is last column and moving down 
			if (spacesToMove > 0 && positionY == 7 && positionX != 7) {
				if (positionX + spacesToMove >= rows) {
					spacesToMove = spacesToMove - (rows - (positionX + 1));
					positionX = 7;

					cout << "You encountered an enemy, choose how many fights";
					cin >> fight;

					if (fight >= enemy)
					{
						XP = &Yarra;

						Yarra = Yarra + 2;

						cout << "You have defeated the enemy, your XP went down to "; << XP << endl;
					}
					else if
					{
						HP = &Yarra;

						Yarra = Yarra - 2;

						cout << "The enemy hit you, your HP went down to " << HP << endl;
					}

					else
					{

						cout << "The enemy defeated you, GAME OVER!!!!!!!!!!!!!!";
					}
				}
				else {
					positionX = positionX + spacesToMove;
					spacesToMove = 0;
				}
			}

			//position is on last row and moving left
			if (spacesToMove > 0 && positionX == 7 && positionY != 0) {
				if ((columns - (positionY + 1)) + spacesToMove >= columns) {
					spacesToMove = spacesToMove - (positionY);
					positionY = 0;
				}
				else {
					positionY = positionY - spacesToMove;
					spacesToMove = 0;
				}
			}

			//position is on first column and moving up
			if (spacesToMove > 0 && positionY == 0 && positionX != 0) {
				if ((rows - (positionX + 1)) + spacesToMove >= rows) {
					spacesToMove = spacesToMove - (positionX);
					positionX = 0;
				}
				else {
					positionX = positionX - spacesToMove;
					spacesToMove = 0;
				}
			}
		} //end of while
	}

	void drawBoard(int positionX, int positionY) {
		//Use two loops to draw the game board. If the passed in player position matches
		//a position, place a P on it.
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < columns; y++)
			{
				//The board representation will be drawn with * only if is the outer paths
				//of the 2D Array
				if (y == 0 || y == 7 || x == 0 || x == 7) {
					if (positionX == x && positionY == y)
					{
						gameBoard[x][y] = 'P';
					}
					else {
						gameBoard[x][y] = '*';
					}
					cout << setw(2) << gameBoard[x][y];
				}
				else {
					cout << setw(2) << " ";
				}
			}
			cout << endl;
		}
	}


		
	}
	//ofstream myfile("saveGame.txt");
	//else if (myfile.is_open())
	//{
		//if (myfile.isopen())
		//{
			//myfile << "Loading your last save.\n";
			//myfile.close();
		//}
	//}
	else
	{
		cout << "You have no saved game";
	}
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
