#include<iostream>
using namespace std;

int (int n, int k) {
    if (n == 1)
        return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the step rate: ";
    cin >> k;
    cout << "The last person standing is at position: " << josephus(n, k) + 1 << endl;
    return 0;
}
