#include <iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

}

int main() {
    int size1, size2;

    cout << "Enter size of first array: ";
    cin >> size1;

    int arr1[size1];
    cout << "Enter " << size1 << " elements for the first array (in sorted order): ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> size2;

    int arr2[size2];
    cout << "Enter " << size2 << " elements for the second array (in sorted order): ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int merged[size1 + size2];

    merge(arr1, size1, arr2, size2, merged);

    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
