/*
Problem Statement:
Find the sum of the digits of a number using recursion.

Approach:
1. Base Case: If n == 0, return 0.

2. Recursive Case: The sum of digits of n is n % 10 + sumOfDigits(n / 10).

Code -

*/

#include<iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of digits: " << sumOfDigits(n) << endl;
    return 0;
}

/*
Time Complexity:
◾ Time Complexity is O(log n) because the number is reduced by a factor of 10 at each step, leading to logarithmic growth.

Space Complexity:
◾ Space Complexity is O(log n) due to the recursion stack that grows proportionally to the number of digits in n.

Example Inputs and Outputs:
◾ Input: Enter a number: 123
  Output: Sum of digits of 123 is 6

◾ Input: Enter a number: 4567
  Output: Sum of digits of 4567 is 22

◾ Input: Enter a number: 0
  Output: Sum of digits of 0 is 0

*/
