#include <iostream>
#include <fstream>
#include <string>

#define ARRAY_SIZE 1001


void inputArray(std::string &A, int *arrayA) {
	int len = arrayA[0];
	std::cout << len << std::endl;
	for (int i = len; i > 0; i--) {
		arrayA[i] = A[i-1] - '0';
		//std::cout << arrayA[i] << " ";
	}		
}

int getMax(int &a, int &b) {
	if (a > b)
		return a;
	return b;
}

void sumNumbers(int *arrayA, int *arrayB, int *arrayResult) {
	int len = getMax(arrayA[0], arrayB[0]);
	//std::cout << len << std::endl;
	for (int i = 1; i <= len; i++) {
		int getNext = arrayA[i] + arrayB[i];
		if (getNext < 10)
			arrayResult[i] += getNext;
		else {
			arrayResult[i] += getNext % 10;
			if (arrayResult[i] > 10) {
				getNext = getNext / 10;
				arrayResult[i + 1] += 1;
			}
			//getNext = getNext / 10;
			arrayResult[i + 1] += 1;
		}
		std::cout << arrayResult[i] << " ";
	}
	
}


int main() {
	int arrayA[ARRAY_SIZE] = { 0 };int arrayB[ARRAY_SIZE] = { 0 };
	int arrayResult[ARRAY_SIZE] = { 0 };
	std::ifstream file("input.txt"); //, std::ios::in
	std::string A; std::string B;
	file >> A >> B;
	std::cout << A << std::endl << B << std::endl; //
	file.close();
	arrayA[0] = A.length();
	arrayB[0] = B.length();
	inputArray(A, arrayA);
	inputArray(B, arrayB);
	sumNumbers(arrayA, arrayB, arrayResult);
	//std::cout << arrayB[5] << std::endl; //<< B
	system("pause");
	return 0;
}
