#include <iostream>

bool isPalindromic(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (arr[i] != arr[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 2, 1}; // Example array, you can change it as needed
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isPalindromic(arr, size)) {
        std::cout << "The array is palindromic." << std::endl;
    } else {
        std::cout << "The array is not palindromic." << std::endl;
    }

    return 0;
}
