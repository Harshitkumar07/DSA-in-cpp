/*
Problem Statement:
Find the nth triangular number using recursion.

Approach:

1. Base Case:
  If n is 1, return 1.

2. Recursive Case:
  Return n + triangular(n - 1).

Code -
*/
#include <iostream>
using namespace std;

int triangular(int n) {
    if (n == 1) return 1;  // Base case
    return n + triangular(n - 1);  // Recursive case
}

int main() {
    int n ;
    cout<<"Enter the number: ";
    cin>>n;
    cout << "The " << n << "th triangular number is: " << triangular(n) << endl;
    return 0;
}
/*
◾ Time Complexity: O(n)
  Each recursive call reduces n by 1, leading to n calls until n reaches 0.

◾ Space Complexity: O(n)
  The recursion stack grows with each call, leading to a space complexity of O(n).

Example Inputs and Outputs:

1. Input: n = 5
  Output: The 5th triangular number is: 15

2. Input: n = 3
  Output: The 3rd triangular number is: 6

*/
