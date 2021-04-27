#pragma once
#include <iostream>
#include <vector>
#include <ctime>

struct Square {					// A structure representing square. 
	int _x = 0;		
	int _y = 0;
	int _length = 0;
	Square(int x = 0, int y = 0, int length = 0) : _x(x), _y(y), _length(length) {};
};

class TableTop {
private:
	int mul;

	int length;					// Length of square.
	int** table;				// Arrangement of squares.
	int** bestTable;			// Best arrangement of squares.

	int amount;					// Amount of squares.
	int bestAmount;				// Best amount of squares.

	std::vector<Square> current;
	std::vector<Square> best;
	unsigned int countOfOp;		// Count of operations.

public:
	TableTop(int length, int mul) : length(length), amount(0), bestAmount(length*length), countOfOp(0) {
		this->mul = mul;
		table = new int* [length];
		bestTable = new int* [length];
		for (int i = 0; i < length; i++) {
			table[i] = new int[length];
			bestTable[i] = new int[length];
			for (int j = 0; j < length; j++) {
				table[i][j] = 0;
				bestTable[i][j] = 0;
			}
		}
		// backtracking();
		// printResult(this->mul);
	}

	~TableTop();

	void insertSquare(Square dot);
	void removeSquare(Square dot);

	void setBestTable();							// Set best square arrangement.
	bool checkForFill();							// Checking for fillnes.
	bool checkForPlace(int x, int y, int m);		// Checking for ability to place new n-size square. 

	void backtracking();							// Main method in class that representing square.
	void printResult(int mul);
};

