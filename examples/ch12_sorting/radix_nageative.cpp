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

void RadixSort(int* numbers, int numbersSize) {
    std::vector<std::vector<int>> buckets(10);
    int copyBackIndex;

    // Find the max length, in number of digits
    int maxDigits = RadixGetMaxLength(numbers, numbersSize);

    int pow10 = 1;
    for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
        // Put numbers into buckets
        for (int i = 0; i < numbersSize; i++) {
            int num = numbers[i];
            int bucketIndex = (abs(num) / pow10) % 10;
            buckets[bucketIndex].push_back(num);
        }

        // Copy buckets back into numbers array
        copyBackIndex = 0;
        for (int i = 0; i < 10; i++) {
            std::vector<int>& bucket = buckets[i];
            for (int j = 0; j < bucket.size(); j++) {
                numbers[copyBackIndex] = bucket[j];
                copyBackIndex++;
            }
            bucket.clear();
        }
        pow10 *= 10;
    }

    std::vector<int> negatives;
    std::vector<int> nonNegatives;
    for (int i = 0; i < numbersSize; i++) {
        int num = numbers[i];
        if (num < 0) {
            negatives.push_back(num);
        }
        else {
            nonNegatives.push_back(num);
        }
    }

    // Copy sorted content to array - negatives in reverse, then non-negatives
    copyBackIndex = 0;
    for (int i = negatives.size() - 1; i >= 0; i--) {
        numbers[copyBackIndex] = negatives[i];
        copyBackIndex++;
    }
    for (int i = 0; i < nonNegatives.size(); i++) {
        numbers[copyBackIndex] = nonNegatives[i];
        copyBackIndex++;
    }
}

int main() {
    int array[] = {-100, 91, -82, -73, 64, -55, 46, -37, 28, -19};
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