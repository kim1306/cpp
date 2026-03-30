#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::ifstream inputFile("data.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open data.txt" << std::endl;
        return 1;
    }

    int N; // the first number in file == count of values
    if (!(inputFile >> N)) {
        std::cerr << "Error: Could not read the count N." << std::endl;
        return 1;
    }

    // Creating the dynamic array via a float pointer
    float* dataArray = new float[N];

    float sum = 0.0;
    for (int i = 0; i < N; ++i) {
        inputFile >> dataArray[i];
        sum += dataArray[i];
    }

    inputFile.close();

    float mean = sum / N;
    float sumSqDiff = 0.0;
    for (int i = 0; i < N; ++i) {
        sumSqDiff += std::pow(dataArray[i] - mean, 2); //formula for getting sd.1
    }//(dataArray[i] - mean)**2

    float stdDev = std::sqrt(sumSqDiff / (N - 1)); //formula for getting sd.2
    //sqrt= square root

    std::cout << std::fixed << std::setprecision(2);
    // setprecision forces a set number of digits after the decimal point,
    std::cout << "The number of floating point values (N): " << N << std::endl;
    std::cout << "The mean of the floating point values: " << mean << std::endl;
    std::cout << "The sample standard deviation (s): " << stdDev << std::endl;

    // Clean up dynamic memory
    delete[] dataArray;

    return 0;
}
