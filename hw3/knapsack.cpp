#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream inFile;
	//variable declarations, change totalWeight to change outcome
	int weights[5], values[5], remainWeight, totalWeight = 8, totalValues = 0;
	int finalX = 0, finalY = 0;

	//open and read from the data file
	int i = 0;
	inFile.open("data.txt");
	while (i < 5) {
		inFile >> weights[i];
		inFile >> values[i];
		i++;
	}

	totalValues = sizeof(values) / sizeof(int);
	int table[totalWeight + 1][totalValues + 1];
	//populate first row and coloumn with 0's
	for (int i = 0; i < totalWeight + 1; i++) {
		table[i][0] = 0;
	}
	for (int j = 0; j < totalValues + 1; j++) {
		table[0][j] = 0;
	}

	//use bottomsup to calculate optimal solution
	//i is my item number; j is my weight to compare against
	for (int i = 1; i < totalValues + 1; i++) {
		for (int j = 0; j < totalWeight + 1; j++) {
			//can be a part of the solution
			if (weights[i - 1] <= j) {
				if ((values[i - 1] + table[i - 1][j - weights[i - 1]]) > table[i - 1][j]) {
					table[i][j] = values[i - 1] + table[i - 1][j - weights[i - 1]];
					//update the indices of the final solution
					finalX = i;
					finalY = j;
				}
				else
					table[i][j] = table[i - 1][j];
			}
			//can't be a part of the solution
			else
				table[i][j] = table[i - 1][j];
		}
	}

	//print out the final optimal solution
	cout << "The optimal solution is: " << table[finalX][finalY] << endl;
	return 0;
}