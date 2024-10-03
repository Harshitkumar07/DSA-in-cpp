/*
Problem Statement:
Reverse a number using recursion.

Approach:
1. Base Case:
   If the number is 0, return 0.

2. Recursive Case:
   Combine the last digit and the reversed number of the remaining digits.

Code:
*/
#include<iostream>
using namespace std;

int revNum(int n, int rev = 0)
{
    if (n == 0) {
        return rev;
    }
    return revNum(n / 10, rev * 10 + n % 10);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reversed number: " << revNum(n) << endl;
    return 0;
}
/*
Time Complexity:
◾ The time complexity is O(log(n)) as the number of digits is proportional to the logarithm of the number.

Space Complexity:
◾ The space complexity is O(log(n)) for the recursion stack.

Example Inputs and Outputs:
1. Input: Enter a number: 12345
   Output: Reversed number: 54321

2. Input: Enter a number: 100
   Output: Reversed number: 1
*/
