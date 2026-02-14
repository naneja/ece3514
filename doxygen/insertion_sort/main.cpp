#include "insertion_sort.hpp"

/**
 * @brief Demonstrates insertion_sort on an integer array.
 */
int main() {

    // Example unsorted integer array
    int arr[]{5, 2, 7, 1, 5, 6, 3, 4, 5, -1, 0};

    // Compute number of elements
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort array
    insertion_sort<int>(arr, size);

    // Output sorted results
    std::cout << "Sorted integers: ";
    for (int i{0}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
