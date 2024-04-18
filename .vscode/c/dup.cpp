#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> removeDuplicates(int arr[], int n) {
    unordered_set<int> seen;
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
