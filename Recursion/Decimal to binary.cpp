/*
Problem Statement:
Convert a decimal number to binary using recursion.

Approach:
1. Base Case:
   If n is 0, return an empty string.

2. Recursive Case:
   Return the binary representation of the remaining number plus the last digit (n % 2).

Code -
*/
#include <iostream>
using namespace std;

string decimalToBinary (int n)
{
    if (n == 0) {
        return "";
    }
    return decimalToBinary (n / 2) + to_string (n % 2);
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    string binary = decimalToBinary (n);
    cout << "Binary of " << n << ": " << (binary.empty() ? "0" : binary) << endl;
    return 0;
}
/*
◾ Time Complexity: O(log(n))
  Each recursive call divides n by 2, leading to a logarithmic number of recursive calls (base 2).

◾ Space Complexity: O(log(n))
  The recursion depth is proportional to log(n) since each call reduces the number by half.

Example Inputs and Outputs:
1. Input: Enter the number: 10
   Output: Binary of 10: 1010

2. Input: Enter the number: 10
   Output: Binary of 10: 1010
*/
