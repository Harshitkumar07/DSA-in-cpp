/*
Problem Statement:
Find the greatest common divisor (GCD) of two numbers using recursion.

Approach:
1. Euclidean Algorithm:
   The GCD of two numbers a and b can be found using the formula:
   GCD(a, b) = GCD(b, a % b) until b becomes 0, at which point a is the GCD.

2. Base Case:
   If b == 0, return a because the GCD of a and 0 is a.

3. Recursive Case:
   For every recursive step, the function reduces b and computes a % b until the base case is reached.

Code -
*/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << ": " << gcd(a, b) << endl;
    return 0;
}

/*

Time Complexity:
◾  The Euclidean algorithm runs in logarithmic time based on the smaller of the two numbers.
◾  Time Complexity: O(log(min(a, b)))

Space Complexity:
◾  The space complexity depends on the recursion depth, which is proportional to the number of recursive calls made, governed by the Euclidean algorithm.
◾  Space Complexity: O(log(min(a, b)))

Example Inputs and Outputs:
1. Input: Enter two numbers: 48
          16
   Output: GCD of 48 and 18 : 6

2. Input: Enter two numbers: 101
          103
   Output: GCD of 101 and 103 : 1

3. Input: Enter two numbers: 56
          98
   Output: GCD of 56 and 98 : 14

*/
