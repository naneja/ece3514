#include <iostream>
#include <vector>
#include <cstdlib> // for abs()

// Returns the length, in number of digits, of an integer value
int RadixGetLength(int value) {
    if (value == 0)
        return 1;

    int digits{0};
    while (value != 0) {
        digits++;
        value /= 10;
    }
    return digits;
}

// Returns the maximum length, 
// in number of digits, out of all array elements
int RadixGetMaxLength(const int* numbers, int numbersSize) {
    int maxDigits{0};
    for (int i{0}; i < numbersSize; i++) {
        int digitCount = RadixGetLength(numbers[i]);
        if (digitCount > maxDigits) {
            maxDigits = digitCount;
        }
    }
    return maxDigits;
}

void RadixSort(int* array, int arraySize) {
    std::vector<std::vector<int>> buckets(10);
    int digitIndex;
    int maxDigits = RadixGetMaxLength(array, arraySize);
    
    // Start with the least significant digit
    int pow10 = 1;
    for (digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
        for (int i{0}; i < arraySize; i++) {
            int bucketIndex = abs(array[i] / pow10) % 10;
            buckets[bucketIndex].push_back(array[i]);
        }
        int copyBackIndex = 0;
        for (int i = 0; i < 10; i++) {
            for (int j{0}; j < buckets[i].size(); j++) {
                array[copyBackIndex] = buckets[i].at(j);
                copyBackIndex++;
            }
            buckets[i].clear();
        }
        pow10 *= 10;
    }
}

int main() {
    int array[] = {100, 91, 82, 73, 64, 55, 46, 37, 28, 19};
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Original array: ";
    for (int n : array) std::cout << n << " ";
    std::cout << "\n";

    RadixSort(array, size);

    std::cout << "Sorted array: ";
    for (int n : array) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}