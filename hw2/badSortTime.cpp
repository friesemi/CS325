#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
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


int main() {
	clock_t start;
	double duration;
	srand(time(NULL));

	//change a value to 3/4 or 2/3
	float a = .66;
	//change numSorted to desired amount of values to sort
	int numSorted = 1200;

	int sortArray[numSorted];
	//fill array with random variables
	for (int i = 0; i < numSorted; i++) {
		sortArray[i] = rand() % 10001;
	}

	//start beginning of clock to get running time of sort
	start = clock();
	//sort the values using bad sort
	badSort(sortArray, a, 0, numSorted - 1);
	//get final running time of sort
	duration = (clock() - start)/(double)CLOCKS_PER_SEC;

	cout << "The bad sort took: " << duration << " milliseconds" << endl;
		
	return 0;
}