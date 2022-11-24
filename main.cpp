#include <iostream>
#include <fstream>
#include <string>

#define ARRAY_SIZE 1001

int getMax(int &a, int &b);

void inputArray(std::string &A, int *array);

void outputArray(int *matrix);

void sumNumbers(int *arrayA, int *arrayB, int *arrayResult);

void multiplyNumbers(int *arrayA, int *arrayB, int *arrayResult){
    int lenA = arrayA[0];
    int lenB = arrayB[0];
    for (int i = 1; i < lenB; i++){
        for (int j = 1; j < lenA; j++){
            arrayResult[j] += arrayA[j] * arrayB[i];
            int getNext;
            if (arrayResult[i] > 9){
                getNext = arrayResult[i] / 10;
                arrayResult[i] = arrayResult[i] % 10;
                arrayResult[i + 1] += getNext;
            }
        }
    }
}


int main() {
	int arrayA[ARRAY_SIZE] = { 0 };int arrayB[ARRAY_SIZE] = { 0 };
	int arrayResultSum[ARRAY_SIZE] = {0 }; int arrayResultMultiply[ARRAY_SIZE] = {0 };
	std::ifstream file(R"(D:\C++Project\Additional2\input.txt)"); //, std::ios::in
	std::string A; std::string B;
	file >> A >> B;
	file.close();
	arrayA[0] = A.length();
	arrayB[0] = B.length();
	inputArray(A, arrayA);
	inputArray(B, arrayB);
	sumNumbers(arrayA, arrayB, arrayResultSum);
    multiplyNumbers(arrayA, arrayB, arrayResultMultiply);
//    outputArray(arrayResultSum);
    outputArray(arrayResultMultiply);

	return 0;
}


int getMax(int &a, int &b) {
    if (a > b)
        return a;
    return b;
}

void inputArray(std::string &A, int *array) {
    int len = array[0];
    for (int i = 1;   i <= len ;i++) {
        array[i] = A[len-i] - '0';
    }
}

void outputArray(int *matrix) {
    int len = matrix[0];
    for (int i = len; i > 0; i--) {
        std::cout << matrix[i];
    }
    std::cout << std::endl;
}


void sumNumbers(int *arrayA, int *arrayB, int *arrayResult) {
    int len = getMax(arrayA[0], arrayB[0]);
    arrayResult[0] = len;
    for (int i = 1; i <= len; i++) {
        int getNext;
        arrayResult[i] += arrayA[i] + arrayB[i];
        if (arrayResult[i] > 9){
            getNext = arrayResult[i] / 10;
            arrayResult[i] = arrayResult[i] % 10;
            arrayResult[i + 1] += getNext;
        }
    }

}