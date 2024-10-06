/*

Problem Statement:
Calculate x^n (x raised to the power of n) using recursion.

Approach:
1. Base Case:
   If n == 0, return 1 because any number raised to the power of 0 is 1.

2. Recursive Case:
   If n > 0, the function will recursively multiply x with the result of power(x, n - 1).

For example, to calculate x^n, we break it down into x * x^(n-1). The recursion continues until n reaches 0,
at which point it returns 1.

*/

#include<iostream>
using namespace std;

int power(int base, int exp) {
    if(exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int main() {
    int base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    cout << "Power: " << power(base, exp) << endl;
    return 0;
}

/*

Time Complexity:
◾ The function makes n recursive calls to compute the power.
  Time Complexity: O(n)

Space Complexity:
◾ The recursion depth is equal to n, so the space complexity is proportional to the number of recursive calls.
  Space Complexity: O(n)

Example Inputs and Outputs:

1. Input: Enter base and exponent: 2
          3
   Output: 2^3 is 8

2. Input: Enter base and exponent: 5
          4
   Output: 5^4 is 625

3. Input: Enter base and exponent: 10
          0
   Output: 10^0 is 1

*/
