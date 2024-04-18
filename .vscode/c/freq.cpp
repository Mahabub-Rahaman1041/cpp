#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Using unordered_map to store frequency of elements
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; ++i) {
        frequencyMap[arr[i]]++;
    }

    cout << "Element\tFrequency" << endl;
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}
