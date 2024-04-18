#include <iostream>

using namespace std;

class Stack {
private:
    int *arr; // Pointer to array to hold stack elements
    int maxSize; // Maximum size of the stack
    int top; // Index of the top element of the stack

public:
    // Constructor to initialize the stack with a user-given array and size
    Stack(int size) {
        arr = new int[size]; // Allocate memory for the array
        maxSize = size;
        top = -1; // Initialize top as -1 to indicate an empty stack
    }

    // Destructor to deallocate memory
    ~Stack() {
        delete[] arr;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == maxSize - 1;
    }

    // Function to push an element onto the stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot push element.\n";
            return;
        }
        arr[++top] = element;
        cout << "Pushed " << element << " onto the stack.\n";
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop element.\n";
            return -1; // Return -1 to indicate failure
        }
        return arr[top--];
    }

    // Function to display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack contents: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    char choice;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                stack.push(element);
                break;
            }
            case '2': {
                int poppedElement = stack.pop();
                if (poppedElement != -1)
                    cout << "Popped " << poppedElement << " from the stack.\n";
                break;
            }
            case '3':
                stack.display();
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != '4');

    return 0;
}
