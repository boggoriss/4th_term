#include "TableTop.h"
#include <ctime>

class TableTop;

void devidedByTwo(int size) {
	std::cout << 4 << std::endl;
	std::cout << "1 1 " << size << std::endl;
	std::cout << 1 + size << " 1 " << size << std::endl;
	std::cout << "1 " << 1 + size << " " << size << std::endl;
	std::cout << 1 + size << " " << 1 + size << " " << size;
}


int main() {
	int length;
	//std::cout << "Please, input length of table's side:\n";
	std::cin >> length;
	int mul = 1;
	//TableTop table(length, 1);
	bool devByTwo = false;
	if (length % 2 == 0) {
		devByTwo = true;
	}
	else {
		if (length % 3 == 0) {
			mul = length / 3;
			length = 3;
		}
		if(length % 5 == 0){
			mul = length / 5;
			length = 5;
		}
	}

	if (devByTwo) {
		devidedByTwo(length / 2);
	}
	else {
		TableTop table(length, mul);
		table.backtracking();
		table.printResult(mul);
	}
}



/*
srand(time(0));
if (squareSideLength % 2 == 0)// проверка возможности оптимизации
{
	devided_by_two(squareSideLength / 2);
}
else
{
	if (squareSideLength % 3 == 0)
	{
		mul = squareSideLength / 3;
		squareSideLength = 3;
	}
	else if (squareSideLength % 5 == 0)
	{
		mul = squareSideLength / 5;
		squareSideLength = 5;
	}
	Table table(squareSideLength, mul);
	// table.backtracking();
	//table.print_result(mul);
	std::cout << table << "\n";
}
cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы
*/