#include <iostream>
#include <utility>  // for std::move

/**
 * @brief Sorts an array using the insertion sort algorithm.
 *
 * Reorders the elements in the range [data, data + n) into
 * non-decreasing order using insertion sort.
 *
 * @tparam T Type of elements stored in the array.
 *
 * @param data Pointer to the first element of the array.
 * @param n Number of elements in the array.
 *
 * @pre data must point to a valid array of at least n elements.
 * @pre Type T must support:
 *      - Move assignment
 *      - Copy construction
 *      - operator< comparison
 *
 * @complexity
 *      Worst-case:  O(n^2) comparisons and moves
 *      Best-case:   O(n) (already sorted input)
 *
 * @note Stable sorting algorithm.
 *
 * @warning Behavior is undefined if data is null and n > 0.
 */
template <typename T>
void insertion_sort(T* data, int n) {

    // Begin with the second element since a single element is trivially sorted
    for (int k{1}; k < n; k++) {

        // Store current element to be positioned correctly
        T cur{data[k]};
        int j{k};

        // Shift elements greater than cur one position to the right
        while (j > 0 && cur < data[j - 1]) {
            data[j] = std::move(data[j - 1]);  // move element to the right
            j--;
        }

        // Place stored element into its correct position
        data[j] = cur;
    }
}
