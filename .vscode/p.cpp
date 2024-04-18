#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    if (isPalindrome(arr, size)) {
        cout << "The array is palindromic." << endl;
    } else {
        cout << "The array is not palindromic." << endl;
    }

    return 0;
}
