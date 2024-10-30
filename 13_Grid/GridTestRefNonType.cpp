import grid;
#include <iostream>
#include <string>

using namespace std;

namespace {
	int defaultInt{ 11 };
}

int main()
{
	Grid<int, defaultInt> myIntGrid;
	
	Grid<int, defaultInt> myIntGrid2{ myIntGrid };
	myIntGrid2.at(1, 2) = 3;

	cout << myIntGrid.at(1, 2).value_or(-1) << endl;
	cout << myIntGrid2.at(1, 2).value_or(-1) << endl;
	return 0;
}