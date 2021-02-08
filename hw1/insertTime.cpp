#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
	clock_t start;
	double duration;
	start = clock();

	int numSorted = atoi(argv[1]);
	srand(time(NULL));

	int numArray[numSorted];
	for (int i = 0; i < numSorted; i++) {
		numArray[i] = rand() % 10001;
	}
	for (int q = 0; q < numSorted; q++) {
		cout << numArray[q] << " ";
	}
	cout << endl;

	//sort the array using insertion sort
	int j, k, holder;
	for (j = 1; j < numSorted; j++) {
		holder = numArray[j];
		k = j - 1;

			//loop checking each value from the right to the left if the holder is less than the lower array number
		while (k >= 0 && numArray[k] > holder) {
			//swap the values if necessary moving the value farther to the left until it is the smallest integer
			numArray[k + 1] = numArray[k];
			k = k - 1;
		}
		numArray[k + 1] = holder;
	}

	//calculate the time it took to run the sorting algorithm
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	//output the sorted array and the time it took to execute
	for (int l = 0; l < numSorted; l++) {
		cout << numArray[l] << " ";
	}
	cout << endl;
	cout << "The insert sort took: " << duration << " seconds" << endl;

	return 0;
}