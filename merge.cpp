#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    // Merging the two halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements of left half, if any
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements of right half, if any
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the merged elements back into the original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;

        // Recursively sort the first half
        mergeSort(arr, st, mid);
        // Recursively sort the second half
        mergeSort(arr, mid + 1, end);
        // Merge the sorted halves
        merge(arr, st, mid, end);
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1);

    // Output the sorted array
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
