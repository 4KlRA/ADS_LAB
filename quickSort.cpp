#include <iostream>
using namespace std;

int N;

void traverse(int arr[], int pivot) {
    for (int i = 0; i < N; i++)
        if (arr[i] == pivot)
            cout << "[" << arr[i] << "]";
        else cout << arr[i] << " ";
    cout << "\n\n";
}

int partition(int arr[], int beg, int end) {
    int loc = beg;
    int left = beg;
    int right = end;
    int pivot = arr[loc];
    cout << "\nPivot: " << pivot << "\n";
    traverse(arr, pivot);
    while (left < right) {
        while (arr[loc] <= arr[right] && loc != right)
            right--;
        if (loc == right) {
            int temp;
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        traverse(arr, pivot);
        while (arr[left] <= arr[loc] && loc != left) 
            left++;
        if (loc == left) {
            int temp;
            temp = arr[loc];
            arr[loc] = arr[left];
            arr[left] = temp;
            loc = left;
        }
        traverse(arr, pivot);
        cout << "Pivot [" << arr[loc] << "] placed at position " << loc + 1 << "\n\n";
        return loc;
    }
}

void quickSort(int arr[], int beg, int end) {
    if (beg < end) {
        int loc = partition(arr, beg, end);
        quickSort(arr, beg, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}

int main {
    int a[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    N = sizeof(a) / sizeof(a[0]);
    cout << "Original array: ";
    traverse(a, -1);
    cout << "\n--- Partiion step ---\n";
    quickSort(a, 0, N - 1);
    cout << "\nSorted array: ";
    traverse(a, -1);

    return 0;
}