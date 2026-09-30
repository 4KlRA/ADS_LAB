#inculde <iostream>
using namespace std;

int pq (int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxElement = pq(arr, n);
    cout << "The maximum element in the array is: " << maxElement << endl;
    return 0;
}