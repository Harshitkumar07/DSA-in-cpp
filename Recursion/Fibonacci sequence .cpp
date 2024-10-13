/*
Problem Statement:
Find the nth Fibonacci number using recursion.

Approach:

The Fibonacci sequence is defined as:
  1. Fib(0) = 0, Fib(1) = 1, and Fib(n) = Fib(n-1) + Fib(n-2) for n >= 2.

  2. Base Cases: If n == 0, return 0; if n == 1, return 1.

  3. Recursive Case: For n > 1, return Fib(n-1) + Fib(n-2).

Code -
*/

#include<iostream>
using namespace std;

int fibo (int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibo (n - 1) + fibo (n - 2);
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibo (n) << endl;
    return 0;
}

/*
Time Complexity:
  ◾ O(2^n) because at each step, two recursive calls are made, leading to exponential growth.

Space Complexity:
  ◾ O(n) due to the depth of the recursion stack, which can go up to n.

Example Inputs and Outputs:
1. Input: Enter the number : 5
   Output: Fibonacci of 5 is 5

2. Input: Enter the number : 10
   Output: Fibonacci of 10 is 55

3. Input: Enter the number : 0
   Output: Fibonacci of 0 is 0
*/
