#include<iostream>
using namespace std;

void printTo1(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    printTo1(n - 1);
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printTo1(n);
    return 0;
}
