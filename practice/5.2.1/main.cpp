# include <iostream>
template <typename T>
void insertion_sort(T *data, int n) {
    // begin with second character
    for (int k{1}; k<n; k++) {
        T cur{data[k]};  //to relocate cur=data[k]
        int j{k};
        while (j>0 && cur < data[j-1]) {
            data[j] = std::move(data[j-1]); // move right
            j--;
        }
        data[j] = cur; //proper place for cur
    }
}

int main() {
    int arr[]{5, 2, 7, 1, 5, 6, 3, 4, 5, -1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort<int>(arr, size);

    std::cout << "Sorted integers: ";
    for (int i{0}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}