#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int badSort(int sortArray[], float a, int left, int right) {
	//base case for recursion, swapping if only two values in array need to be swapped
	int n = (right - left + 1);
	if ((n == 2) && (sortArray[left] > sortArray[right])) {
		swap(sortArray[left], sortArray[right]);
	}
	else if (n > 2) {
		//create two arrays, split by m
		int m = ceil(a * n);
		if (m == n)
			m = n - 1;

		//sort the left subarray split by m
		badSort(sortArray, a, left, left + m - 1);
		//sort right subarray split by m
		badSort(sortArray, a, right - m + 1, right);
		//sort left subarray again to verify correctness
		badSort(sortArray, a, left, left + m - 1);
	}
}


int main(int argc, char* argv[]) {
	//simple error handling to check number of args
	if (argc != 2) {
		cout << "Incorrect number of arguments provided: should be executable + alpha value" << endl;
		return 1;
	}
	
	float a = atof(argv[1]);
	int m = 0, numSorted = 0;
	ifstream fileIn;
	ofstream fileOut;

	//open input and output files
	fileIn.open("data.txt");
	fileIn >> numSorted;
	fileOut.open("bad.out");

	//loop for each line of numbers that need to be sorted
	while (!fileIn.eof()) {
		int sortArray[numSorted];
		//read in values of array to be sorted
		for (int i = 0; i < numSorted; i++) {
			fileIn >> sortArray[i];
		}

		//sort the values using bad sort
		badSort(sortArray, a, 0, numSorted - 1);

		//output sorted array to file
		for (int j = 0; j < numSorted; j++) {
			fileOut << sortArray[j] << " ";
		}
		fileOut << endl;

		fileIn >> numSorted;
	}

	fileIn.close();
	fileOut.close();
	return 0;
}