#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	//initialize file descriptor variables
	ifstream fileIn;
	ofstream fileOut;

	//variables used for making change
	int exponent, total, base, result, totalCoins = 0;

	//open files and read in first base variable
	fileIn.open("data.txt");
	fileOut.open("change.txt");
	fileIn >> base;

	//loop until the eof of the file is reached to account for multiple lines
	while(!fileIn.eof()){
		//read in other variables from data.txt and loop until total is 0
		fileIn >> exponent >> total;
		while (total != 0) {
			//check if the denomination is too big and decrement the exponent and number of coins
			if (pow(base, exponent) > total) {
				exponent--;
				totalCoins = 0;
			}
			//if the denomination fits in the total, reduce the total and increment the number of coins
			else {
				total -= pow(base, exponent);
				result = pow(base, exponent);
				totalCoins++;
				//save the result and number of coins if it is the last iteration of the denomination to avoid duplicate writing
				if (pow(base, exponent) > total) {
					fileOut << result << " " << totalCoins << endl << endl;
				}
			}

		}
		fileOut << endl;
		fileIn >> base;
	}

	//close file descriptors
	fileIn.close();
	fileOut.close();
	return 0;
}