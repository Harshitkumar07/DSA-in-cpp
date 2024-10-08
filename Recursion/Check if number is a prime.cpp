/*
Problem Statement:
Check if a number is prime using recursion.

Approach:
◾ Base Cases:
  ◾ If n <= 1, return false (not prime).
  ◾ If n <= 3, return true (2 and 3 are prime).
◾ Recursive Case:
  ◾ Check divisibility by all numbers from 2 to sqrt(n).

Code :
*/

#include<iostream>
using namespace std;

bool isPrime(int n, int i = 2) {
    if (n <= 2)
       return (n == 2);
    if (n % i == 0)
       return false;
    if (i * i > n)
       return true;
    return isPrime(n, i + 1);
}

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
    if (isPrime(n))
        cout << n << " is prime." << endl;
    else
        cout << n << " is not prime." << endl;
    return 0;
}

/*
◾ Time Complexity: O(sqrt(n))
The function checks divisibility only up to the square root of n, leading to a time complexity of O(sqrt(n)).

◾ Space Complexity: O(sqrt(n))
The recursion depth is proportional to the square root of n because it checks divisibility incrementally up to that point.

Example Inputs and Outputs:

1. ◾ Input: Enter a number :  7
   ◾ Output: 7 is prime.

2. ◾ Input: Enetr a number :  10
   ◾ Output: 10 is not prime.
*/
