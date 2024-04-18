#include <iostream>
#include <vector>
using namespace std;
void insertElement(vector<int> &arr, int position, int element) {
    arr.insert(arr.begin() + position, element);
}

void deleteElement(vector<int> &arr, int position) {
    arr.erase(arr.begin() + position);
}

int main() {
    int n;
   cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements for the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int insertPosition, insertElementValue;
   
   cout << "Enter the position to insert an element: ";
    
    cin >> insertPosition;
    
    cout << "Enter the value to insert: ";
   cin >> insertElementValue;

    insertElement(arr, insertPosition, insertElementValue);

    cout << "Array after insertion:\n";
    for (int num : arr) {
        cout << num << " ";
    }
   cout << "\n";

    int deletePosition;
    cout << "Enter the position to delete an element: ";
   cin >> deletePosition;

    deleteElement(arr, deletePosition);

    cout << "Array after deletion:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
