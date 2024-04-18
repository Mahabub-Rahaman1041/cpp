#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    int pos;
    cin>>pos;
    if(pos>=n)
    return 0;
}


#include <iostream>
#include <vector>

int main() {
    // Define an array
    std::vector<int> arr = {1, 2, 3, 4, 5};

    // Insertion
    arr.push_back(6); // Insert 6 at the end of the array

    // Deletion
    arr.pop_back(); // Remove the last element of the array

    // Output the array elements
    std::cout << "Array after insertion and deletion: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
