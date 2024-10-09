/*
Problem Statement:
Count the number of digits in a number using recursion.

Approach:
1. Base Case:
   If the number is 0, return 0.

2. Recursive Case:
   Return 1 + countDigits(n / 10).

Code -
*/
#include <iostream>
using namespace std;

int countDigits (int n)
{
    if (n == 0)
        return 0;
    return
        1 + countDigits (n / 10);
}

int main()
{
    int n ;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Number of digits in " << n << ": " << countDigits (n) << endl;
    return 0;
}
/*
◾ Time Complexity:
  The time complexity is O(log(n)) as the number of digits is proportional to the logarithm of the number.

◾ Space Complexity:
  The space complexity is O(log(n)) for the recursion stack.

Example Inputs and Outputs:

1. Input: Enter the number: 12345
   Output: Number of digits in 12345: 5

2. Input: Enter the number: 100
   Output: Number of digits in 100: 3

*/
