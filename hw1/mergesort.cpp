#include <iostream>
#include <fstream>

using namespace std;

int merge(int sortArray[], int left, int middle, int right) {
	int i, j, k;
	int numLeftArr = middle - left + 1;
	int numRightArr = right - middle;
	int leftArr[numLeftArr], rightArr[numRightArr];

	//copy the original array into the two left and right subarrays
	for (i = 0; i < numLeftArr; i++) {
		leftArr[i] = sortArray[left + i];
	}
	for (j = 0; j < numRightArr; j++) {
		rightArr[j] = sortArray[middle + 1 + j];
	}

	//merge the two arrays together, checking for smaller values and adding them to the sorted array in order
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
	//fill the array with any remaining values not previously sorted
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
	//while the subarrays do not have one value, split them up
	if (right > left) {
		//split according to middle index to create two equal subarrays
		middle = (left + right) / 2;
		//call sort on both the left and right subarrays
		sort(arr, left, middle);
		sort(arr, middle + 1, right);

		//finally merge the two subarrays back together
		merge(arr, left, middle, right);
	}
}

int main() {
	//create file descriptor variable
	ifstream fileIn;
	ofstream fileOut;
	int numSorted = 0;

	//open file and read numbers from the file into an array to be sorted
	fileIn.open("data.txt");
	fileIn >> numSorted;
	fileOut.open("merge.out");

	while (!fileIn.eof()) {
		int numArray[numSorted];
		for (int i = 0; i < numSorted; i++) {
			fileIn >> numArray[i];
		}

		//function to sort array using merge sort recursively
		sort(numArray, 0, numSorted - 1);

		//output sorted array to file
		for (int j = 0; j < numSorted; j++) {
			fileOut << numArray[j] << " ";
		}
		fileOut << endl;

		fileIn >> numSorted;
	}

	fileIn.close();
	fileOut.close();
	return 0;
}