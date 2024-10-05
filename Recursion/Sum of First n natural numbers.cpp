/*
Problem Statement:
Calculate the sum of the first N natural numbers using recursion.

Approach:
1. Base Case:
   If n is 0, return 0.

2. Recursive Case:
   Return n + sum(n - 1).

Code -
*/

#include<iostream>
using namespace std;

int sumOfN(int n) {
    if (n == 0)
        return 0;
    return n + sumOfN(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers: " << sumOfN(n) << endl;
    return 0;
}

/*

Time Complexity: O(n)
◾ Each number is added once, so there are n recursive calls.

Space Complexity: O(n)
◾ The recursion depth is proportional to n.

Example Inputs and Outputs:

1. Input: Enter a number: 5
   Output: Sum of first 5 natural numbers: 15

2. Input: Enter a number: 10
   Output: Sum of first 10 natural numbers: 55

*/
