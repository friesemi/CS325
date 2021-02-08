#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//create file descriptor variable
	ifstream fileIn;
	ofstream outFile;
	int numSorted = 0;

	//open file and read numbers from the file into an array to be sorted
	fileIn.open("data.txt");
	fileIn >> numSorted;
	outFile.open("insert.out");

	while(!fileIn.eof()){
		int numArray[numSorted];
		for (int i = 0; i < numSorted; i++) {
			fileIn >> numArray[i];
		}

		//sort the array using insertion sort
		int j, k, holder;
		for (int j = 1; j < numSorted; j++) {
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

		//save to output file
		for (int l = 0; l < numSorted; l++) {
			outFile << numArray[l] << " ";
		}
		outFile << endl;
	
		fileIn >> numSorted;
	}

	fileIn.close();
	outFile.close();
	return 0;
}