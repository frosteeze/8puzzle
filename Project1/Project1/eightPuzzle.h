#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <queue>

using namespace std;

class eightPuzzle
{
private:
	int puzzle[3][3];
	bool odd;


public:
	eightPuzzle();
	eightPuzzle(int input[3][3]);
	int heuristics1();
	int heuristics2();
	bool isSolved();
	void move(string s);
	void restart();
	bool isOdd();
	bool check(int n);
	void pos(int &x, int &y, int pos);
	void solve();
	void print();
	~eightPuzzle();
};

