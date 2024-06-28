import grid;
#include <iostream>
#include <string>

using namespace std;

int main()
{
	{
		Grid<int, 10, 10> myGrid;
		Grid<int, 10, 10> anotherGrid;

		myGrid.at(2, 3) = 45;
		anotherGrid = myGrid;

		cout << anotherGrid.at(2, 3).value_or(0) << endl;
	}

	{
		Grid<int, 2, 2> myIntGrid;				
		Grid<const char*, 2, 2> myStringGrid;	
		//  Grid<2, 3> test;					

		myStringGrid.at(1, 1) = "Hello";
		Grid<const char*, 2, 2> myStringGridCopy{ myStringGrid };
		myStringGridCopy.at(1, 1) = "World.";

		cout << myStringGrid.at(1, 1).value_or("") << endl;
		cout << myStringGridCopy.at(1, 1).value_or("") << endl;
	}
}
