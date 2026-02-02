#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int nums[] = {12, -15, -23, 7, 24, -2};
    int size = 6;

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < size; i++) {
        smallest = min(nums[i], smallest);
        largest = max(nums[i], largest);
    }

    cout << "smallest = " << smallest << endl;
    cout << "largest = " << largest << endl;

    return 0;
}

