#include "TableTop.h"

TableTop::~TableTop() {
	for (int i = 0; i < length; i++) {
		delete[] table[i];
		delete[] bestTable[i];
	}
	delete[] table;
	delete[] bestTable;
}

void TableTop::insertSquare(Square dot) {
	for (int i = dot._y; i < dot._y + dot._length; i++)
	{
		for (int j = dot._x; j < dot._x + dot._length; j++)
		{
			table[i][j] = amount + 1;
		}
	}
	amount++;
}

void TableTop::removeSquare(Square dot) {
	for (int i = dot._y; i < dot._y + dot._length; i++)
	{
		for (int j = dot._x; j < dot._x + dot._length; j++)
		{
			table[i][j] = 0;
		}
	}
	amount--;
}

void TableTop::setBestTable() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			bestTable[i][j] = table[i][j];
		}
	}
}

bool TableTop::checkForFill() {
	for (int i = length - 1; i >= 0; --i) {
		for (int j = length - 1; j >= 0; --j) {
			if (table[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool TableTop::checkForPlace(int x, int y, int n) {
	if (x >= length || y >= length) {
		return false;
	}
	if (x + n > length || y + n > length) {
		return false;
	}
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (table[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void TableTop::backtracking() {

	Square dot;
	dot._x = 0;
	dot._y = 0;
	dot._length = length / 2 + 1;
	current.push_back(dot);
	insertSquare(dot);
	if (length % 3 != 0 || length % 5 != 0) {
		dot._length = length / 2;
		dot._x = length / 2 + 1;
		current.push_back(dot);
		insertSquare(dot);
		dot._x = 0;
		dot._y = length / 2 + 1;
		current.push_back(dot);
		insertSquare(dot);
	}

	do {
		while (amount < bestAmount && !(checkForFill())) {
			for (int y = 0; y < length; y++) {
				for (int x = 0; x < length; x++) {
					if (table[y][x] == 0) {
						for (int i = length - 1; i > 0; i--) {
							countOfOp++;
							if (checkForPlace(x, y, i)) {
								dot._x = x;
								dot._y = y;
								dot._length = i;
								break;
							}
						}
						insertSquare(dot);
						//std::cout << "Placed square at: " << dot._x << " " << dot._y << " " << dot._length << "\n";
						current.push_back(dot);
					}
				}
			}
		}
		if (bestAmount > amount) {
			bestAmount = amount;
			setBestTable();
			best = current;
		}
		while (!(current.empty()) && current[current.size() - 1]._length == 1) {
			removeSquare(current[current.size() - 1]);
			current.pop_back();
		}

		if (!(current.empty())) {
			dot = current[current.size() - 1];
			current.pop_back();
			removeSquare(dot);
			dot._length -= 1; 
			insertSquare(dot);
			current.push_back(dot);
		}
	} while (amount < (bestAmount * 3) && !(current.empty()));
}

void TableTop::printResult(int mul) {
	Square dot;
	std::cout /*<< "Minimum number of squares: "*/ << bestAmount << std::endl;
	//std::cout<< "Count of operations: " << countOfOp << "\n";
	while (!(best.empty()))
	{
		if(best.size() != bestAmount)
			std::cout << std::endl;

		dot = best[best.size() - 1];
		best.pop_back();
		std::cout << dot._x * mul + 1 << " " << dot._y * mul + 1 << " " << dot._length * mul;
	}

}