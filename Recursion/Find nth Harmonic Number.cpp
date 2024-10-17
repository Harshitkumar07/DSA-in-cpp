/*
Problem Statement:
Find the nth harmonic number using recursion.

Approach:
1. Base Case:
  If n is 1, return 1.

2. Recursive Case:
 Return 1/n + harmonic(n - 1).

Code -
*/
#include <iostream>
using namespace std;

double harmonic(int n) {
    if (n == 1) return 1;  // Base case
    return 1.0 / n + harmonic(n - 1);  // Recursive case
}

int main() {
    int n ;
    cout<<"Enter the number: ";
    cin>>n;
    cout << "The " << n << "th harmonic number is: " << harmonic(n) << endl;
    return 0;
}
/*
◾ Time Complexity: O(n)
  The function recursively sums the harmonic values up to n, making n recursive calls.

◾ Space Complexity: O(n)
  The recursion depth is proportional to n, resulting in O(n) space complexity due to the recursive stack.

Example Inputs and Outputs:

1. Input: n = 5
  Output: The 5th harmonic number is: 2.28333

2. Input: n = 3
  Output: The 3rd harmonic number is: 1.83333
*/
