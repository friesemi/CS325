#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int merge(int sortArray[], int left, int middle, int right) {
	int i, j, k;
	int numLeftArr = middle - left + 1;
	int numRightArr = right - middle;
	int leftArr[numLeftArr], rightArr[numRightArr];

	for (i = 0; i < numLeftArr; i++) {
		leftArr[i] = sortArray[left + i];
	}
	for (j = 0; j < numRightArr; j++) {
		rightArr[j] = sortArray[middle + 1 + j];
	}

	i = 0; j = 0; k = left;
	while (i < numLeftArr && j < numRightArr) {
		if (leftArr[i] <= rightArr[j]) {
			sortArray[k] = leftArr[i];
			i++;
		}
		else if (leftArr[i] > rightArr[j]) {
			sortArray[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < numLeftArr) {
		sortArray[k] = leftArr[i];
		i++; k++;
	}
	while (j < numRightArr) {
		sortArray[k] = rightArr[j];
		j++; k++;
	}
}

int sort(int arr[], int left, int right) {
	int middle = 0;
	if (right > left) {
		middle = (left + right) / 2;
		sort(arr, left, middle);
		sort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}

int main(int argc, char *argv[]) {
	clock_t start;
	double duration;
	start = clock();

	int numSorted = atoi(argv[1]);
	srand(time(NULL));

	int numArray[numSorted];
	for (int i = 0; i < numSorted; i++) {
		numArray[i] = rand() % 10001;
		cout << numArray[i] << " ";
	}
	cout << endl;

	//function to sort array using merge sort recursively
	sort(numArray, 0, numSorted - 1);

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	//print out merged array and the time it took to execute
	for (int j = 0; j < numSorted; j++) {
		cout << numArray[j] << " ";
	}
	cout << endl;
	cout << "The merge sort took: " << duration << " seconds" << endl;

	return 0;
}