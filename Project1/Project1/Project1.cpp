// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "eightPuzzle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	eightPuzzle test;
	test.print();
	cout << endl;
	test.move("up");
	test.print();
	cout << endl;
	test.move("down");
	test.print();
	cout << endl;
	test.move("left");
	test.print();
	cout << endl;
	test.move("right");
	test.print();
	cout << endl;
	test.isOdd();
	cout << endl << test.heuristics1();
	cout << endl << test.heuristics2() << endl << "\n\n\n\n";
	test.solve();
	system("pause");
	return 0;
}

