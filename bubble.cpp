#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) { // Corrected loop condition
            if(arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Added space for readability
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 1, 5, 2, 3}; // Corrected array initialization
    int n = sizeof(arr) / sizeof(arr[0]); // Corrected size calculation
    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}