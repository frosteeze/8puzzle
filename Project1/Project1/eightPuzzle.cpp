#include "stdafx.h"
#include "eightPuzzle.h"


eightPuzzle::eightPuzzle()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			puzzle[i][j] = -1;
		}
	}

	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int test = rand() % 9;
			if (check(test))
			{
				j--;
			}

			else
			{
				puzzle[i][j] = test;
			}
		}
	}
}

eightPuzzle::eightPuzzle(int input[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			puzzle[i][j] = input[i][j];
		}
	}
}

//helper function to check if a number is already in the puzzle
bool eightPuzzle::check(int n)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (n == puzzle[i][j])
			{
				return true;
			}
		}
	}

	return false;
}

int eightPuzzle::heuristics1()
{
	int n = 0; //The number of misplaced squares
	int test = 1; int j = 1; //don't count beginning square, which should be empty
	for (int i = 0; i < 3; i++)
	{
		for (j; j < 3; j++)
		{
			if (puzzle[i][j] != test) n++;
			test++;
		}
		j = 0; 
	}
	return n;
}

int eightPuzzle::heuristics2()
{
	int n = 0; int x; int y; 
	int j = 1; //beginning square should be empty

	for (int i = 0; i < 3; i++)
	{
		for (j; j < 3; j++)
		{
			int solution = (i * 3) + j;
			pos(x, y, solution);
			//Keep looking for the real position and count the steps
			
			while (i != x || j != y)
			{
				if (x < i)
				{
					x++;
					n++;
				}

				else if (x > i)
				{
					x--;
					n++;
				}

				if (y < j)
				{
					y++;
					n++;
				}

				else if (y > j)
				{
					y--;
					n++;
				}

				cout << "X is: " << x << endl;
				cout << "y is: " << y << endl;
				cout << "I is: " << i << endl;
				cout << "J is: " << j << endl;
			}
			cout << "X is: " << x << endl;
			cout << "y is: " << y << endl;

			cout << "Number being traced: " << solution << endl;
			cout << "Number of traces so far: " << n << endl;
		}
		j = 0;
	}
	return n;
}

//helper function to return position of number in puzzle. Uses pointers to return two numbers.
void eightPuzzle::pos(int &x, int&y, int n)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (n == puzzle[i][j])
			{
				x = i;
				y = j;
			}
		}
	}
}

//check for inversions. If so, will restart
bool eightPuzzle::isOdd()
{
	int inversions = 0; int x; int y; 
	for (int i = 1; i < 9; i++)
	{
		pos(x, y, i);
		for (int j = x; j < 3; j++)
		{
			for (int k = y; k < 3; k++)
			{
				if ((i > puzzle[j][k]) && (puzzle[j][k] != 0))
				{
					inversions++;
				}
			}
			y = 0;
		}
	}
	cout << inversions << endl;

	return true;
}

//moves the "0" or moving piece up, down, right, or left
void eightPuzzle::move(string s)
{
	if (s == "up")
	{
		int x; int y;
		pos(x, y, 0);
		if ((x - 1) < 0) cout << "Invalid move. Cannot go up further.";
		else
		{
			int temp = puzzle[x - 1][y];
			puzzle[x - 1][y] = 0;
			puzzle[x][y] = temp;
		}
	}

	else if (s == "down")
	{
		int x; int y;
		pos(x, y, 0);
		if ((x + 1) > 3) cout << "Invalid move. Cannot go down further";
		else
		{
			int temp = puzzle[x + 1][y];
			puzzle[x + 1][y] = 0;
			puzzle[x][y] = temp;
		}
	}

	else if (s == "left")
	{
		int x; int y;
		pos(x, y, 0);
		if ((y - 1) < 0) cout << "Invalid move. Cannot go left further";
		else
		{
			int temp = puzzle[x][y - 1];
			puzzle[x][y - 1] = 0;
			puzzle[x][y] = temp;
		}
	}

	else if (s == "right")
	{
		int x; int y;
		pos(x, y, 0);
		if ((y + 1) > 3) cout << "Invalid move. Cannot go right further";
		else
		{
			int temp = puzzle[x][y + 1];
			puzzle[x][y + 1] = 0;
			puzzle[x][y] = temp;
		}
	}
}

void eightPuzzle::restart()
{

}

void eightPuzzle::solve()
{
	eightPuzzle test = eightPuzzle(puzzle);
	queue<eightPuzzle> frontier;
	frontier.push(test);
	test.print();
	cout << endl;
	test.move("up");
	test.print();
	cout << endl;
	test = frontier.front();
	test.print();
	cout << endl;
}

bool eightPuzzle::isSolved()
{
	return true;
}

void eightPuzzle::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << to_string(puzzle[i][j]) + " ";
		}

		cout << endl;
	}
}

eightPuzzle::~eightPuzzle()
{
}
