#include <iostream>

using namespace std;

// Function to simulate the checking process
bool ismahabubCopy(int mid, int mahabubRollNo) {
    // Simulating the roll number on the copy at position 'mid'
    // Let's assume the roll numbers are consecutive integers starting from 1
    return mid == mahabubRollNo;
}

int findmahabubCopy(int totalStudents, int mahabubRollNo) {
    int low = 1;
    int high = totalStudents;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (ismahabubCopy(mid, mahabubRollNo)) {
            return mid;
        } else if (mid < mahabubRollNo) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Mahabub's copy not found
}

int main() {
    int totalStudents, mahabubRollNo;
    cout << "Enter the total number of students: ";
    cin >> totalStudents;
    cout << "Enter Mahabub's roll number: ";
    cin >> mahabubRollNo;

    int position = findmahabubCopy(totalStudents, mahabubRollNo);
    if (position != -1) {
        cout << "Mahabub's copy is at position: " << position << endl;
    } else {
        cout << "Mahabub's copy not found in the pile." << endl;
    }

    return 0;
}
