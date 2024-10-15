/*
Problem Statement:
Check if a number is prime within a given range using recursion.

Approach:
1. Base Case:
  If n <= 1, return false (not prime).

2. Recursive Case:
  Check divisibility by all numbers from 2 to sqrt(n).

Code -
*/
#include <iostream>
using namespace std;

bool isPrime (int n, int i)
{
    if (i * i > n) {
        return true;
    }
    if (n % i == 0) {
        return false;
    }
    return isPrime (n, i + 1);
}

bool isPrimes (int n)
{
    if (n <= 1) {
        return false;
    }
    return isPrime (n, 2);
}

int main()
{
    int low = 1, high = 10;
    for (int n = low; n <= high; ++n) {
        cout << n << (isPrimes (n) ? " is prime." : " is not prime.") << endl;
    }
    return 0;
}
/*
◾ Time Complexity: O(sqrt(n))
  The function checks divisibility up to the square root of each number in the range,
  leading to a time complexity of O(sqrt(n)) for each number.

◾ Space Complexity: O(sqrt(n))
  The recursion depth is proportional to the square root of n, as it checks divisibility incrementally.

Example Inputs and Outputs:

Input: Range: 1 to 10

Output:
    1 is not prime.
    2 is prime.
    3 is prime.
    4 is not prime.
    5 is prime.
    6 is not prime.
    7 is prime.
    8 is not prime.
    9 is not prime.
    10 is not prime.
*/
