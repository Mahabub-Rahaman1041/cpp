#include <iostream>

// Function to check if the array is in ascending order
bool isAscending(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

// Function to check if the array is in descending order
bool isDescending(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid array size." << std::endl;
        return 1;
    }

    int arr[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> arr[i])) {
            std::cout << "Invalid input. Please enter integers only." << std::endl;
            return 1;
        }
    }

    if (isAscending(arr, size)) {
        std::cout << "The array is in ascending order." << std::endl;
    } else if (isDescending(arr, size)) {
        std::cout << "The array is in descending order." << std::endl;
    } else {
        std::cout << "The array is not in any specific order." << std::endl;
    }

    return 0;
}
