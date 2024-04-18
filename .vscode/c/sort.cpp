#include <iostream>
#include <vector>

// Function to merge two arrays
std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> mergedArray;
    int i = 0, j = 0;

    // Merge elements until one of the arrays is exhausted
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    // Merge remaining elements of arr1
    while (i < arr1.size()) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    // Merge remaining elements of arr2
    while (j < arr2.size()) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    int n, m;
    std::cout << "Enter the size of the first array: ";
    std::cin >> n;
    std::vector<int> arr1(n);
    std::cout << "Enter elements of the first array:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr1[i];
    }

    std::cout << "Enter the size of the second array: ";
    std::cin >> m;
    std::vector<int> arr2(m);
    std::cout << "Enter elements of the second array:\n";
    for (int i = 0; i < m; ++i) {
        std::cin >> arr2[i];
    }

    // Merge the arrays
    std::vector<int> merged = mergeArrays(arr1, arr2);

    // Display the merged array
    std::cout << "Merged array:\n";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
