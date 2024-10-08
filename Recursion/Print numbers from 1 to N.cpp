/*
Problem Statement:
Print numbers from 1 to N using recursion.

Approach:
1. Base Case:
   If n is 0, return.

2. Recursive Case:
   Call the function with n-1 and then print n.

Code -

*/

#include<iostream>
using namespace std;

void printToN(int n) {
    if (n == 0)
        return;
    printToN(n - 1);
    cout << n << " ";
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printToN(n);
    return 0;
}

/*
Time Complexity: O(n)
◾ Each number is printed once, so there are n recursive calls.

Space Complexity: O(n)
◾ The recursion depth is proportional to n.

Example Inputs and Outputs:
1. Input: Enter a number: 7
   Output: Numbers from 1 to 5: 1 2 3 4 5 6 7

2. Input: Enter a number: 5
   Output: Numbers from 1 to 3: 1 2 3 4 5

*/
