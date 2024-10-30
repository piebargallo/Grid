import grid;

int main()
{
	Grid<int> myIntGrid;		// Initial value is 0
	Grid<int, 10> myIntGrid2;	// Initial value is 10

	myIntGrid.at(1, 2) = 3;
	return 0;
}
