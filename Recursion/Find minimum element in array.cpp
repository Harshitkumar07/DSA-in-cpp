#include<iostream>
using namespace std;

int findMin(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return min(arr[n - 1], findMin(arr, n - 1));
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Minimum element: " << findMin(arr, n) << endl;
    return 0;
}
