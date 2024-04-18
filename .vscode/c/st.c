#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> removeDuplicates(int arr[], int n) {
    unordered_set<int> seen;
    vector<int> result;

    for (int i = 0; i < n; ++i) {#include<stdio.h>
#define MAX_SIZE 1000

// Function to push an element onto the stack
void push(int stack[], int *top, int element) {
    if (*top < MAX_SIZE - 1) {
        (*top)++;
        stack[*top] = element;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (*top >= 0) {
        int element = stack[*top];
        (*top)--;
        return element;
    } else {
        printf("Stack underflow\n");
        return -1; // Assuming -1 as an indicator for an error condition
    }
}

int main() {
    printf("\t\tSUBMITTED BY AMRITA CHEL ");
    printf("\n");
    printf("\t\tENROLLMENT NUMBER: 22UEI058");
    printf("\n");
    printf("\n");
    int M[MAX_SIZE], N[MAX_SIZE]; // Arrays representing stacks M and N
    int topM = -1, topN = -1; // Variables to track the tops of stacks
    int P; // Given integer P
    int cumulativeSum = 0; // Cumulative sum of removed numbers
    int maxScore = 0; // Maximum possible score for BB

    // Input P, size of stacks M and N
    printf("Value of P? ");
    scanf("%d", &P);

    int sizeM, sizeN;
    printf("Enter the size of stack M: ");
    scanf("%d", &sizeM);

    printf("Enter the elements of stack M: ");
    for (int i = sizeM - 1; i >= 0; --i) {
        int element;
        scanf("%d", &element);
        push(M, &topM, element);
    }

    printf("Enter the size of stack N: ");
    scanf("%d", &sizeN);

    printf("Enter the elements of stack N: ");
    for (int i = sizeN - 1; i >= 0; --i) {
        int element;
        scanf("%d", &element);
        push(N, &topN, element);
    }

    // Simulate the game and find the maximum score
    while (topM >= 0 || topN >= 0) {
        if (topM >= 0 && topN >= 0) {
            if (M[topM] >= N[topN]) {
                cumulativeSum += pop(M, &topM);
            } else {
                cumulativeSum += pop(N, &topN);
            }
        } else if (topM >= 0) {
            cumulativeSum += pop(M, &topM);
        } else if (topN >= 0) {
            cumulativeSum += pop(N, &topN);
        }

        // Check if BB loses
        if (cumulativeSum > P) {
            printf("BB loses with a cumulative sum of %d\n", cumulativeSum);
            break;
        }

        // Update the maximum score
        if (cumulativeSum > maxScore) {
            maxScore = cumulativeSum;
        }
    }

    // Output the maximum score
    printf("Maximum score for BB: %d\n", maxScore);

   return 0;
}

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
