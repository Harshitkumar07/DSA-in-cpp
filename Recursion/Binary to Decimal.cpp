/*
Problem Statement:
Convert a binary number to decimal using recursion.

Approach:
1. Base Case:
   If the binary number is empty, return 0.

2. Recursive Case:
   Return the last digit (b % 10) times the power of 2 plus the decimal value of the remaining binary number.

Code -
*/
#include <iostream>
#include<cmath>
using namespace std;

int binaryToDecimal (int n, int exp = 0)
{
    if (n == 0) {
        return 0;
    }
    return (n % 10) * pow (2, exp) + binaryToDecimal (n / 10, exp + 1);
}

int main()
{
    int n ;
    cout<<"Enter the number: ";
    cin>>n;
    cout << "Decimal of " << n << ": " << binaryToDecimal (n) << endl;
    return 0;
}
/*
◾ Time Complexity: O(log(n))
  Each recursive call divides n by 2, leading to a logarithmic number of recursive calls (base 2).
◾ Space Complexity: O(log(n))
  The recursion depth is proportional to log(n) since each call reduces the number by half.

Example Inputs and Outputs:
1. Input: Enter the number: 1010
   Output: Decimal of 1010: 10

2. Input: Enter the number: 1011
   Output: Decimal of 1011: 19
*/
