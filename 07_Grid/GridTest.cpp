import grid;
#include <vector>
#include <deque>
#include <iostream>
#include <optional>

using namespace std;

int main()
{
	Grid<int, vector<optional<int>>> myIntVectorGrid;
	Grid<int, deque<optional<int>>> myIntDequeGrid;

	myIntVectorGrid.at(3, 4) = 5;
	cout << myIntVectorGrid.at(3, 4).value_or(0) << endl;

	myIntDequeGrid.at(1, 2) = 3;
	cout << myIntDequeGrid.at(1, 2).value_or(0) << endl;
}
