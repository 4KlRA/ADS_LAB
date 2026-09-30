#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        return binarySearch(arr, mid + 1, high, target);
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }
    int* arr = new int[n];
    cout << "Enter the elements of the array in ascending order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cout << "Enter the target value to search for: ";
    cin >> target;
    int loc = binarySearch(arr, 0, n - 1, target);
    if (loc != -1) 
        cout << "Element found at index: " << loc << endl;
    else
        cout << "Element not found in the array." << endl;
    delete[] arr;
}