/*
Problem Statement:
A group of people stand in a circle, and every k-th person is eliminated until only one person remains.

Approach:
1. Base Case:
   If there's only one person, the survivor is at index 0.

2. Recursive Case:
   For n people and a step k, the position of the survivor is given by:
   Josephus(n) = (Josephus(n-1) + k) % n
   where Josephus(1) = 0.

Code - 
*/
#include<iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the step rate: ";
    cin >> k;
    cout << "The last person standing is at position: " << josephus(n, k) + 1 << endl;
    return 0;
}

/*
Time Complexity:
 The time complexity is O(n) due to the recursion.

Space Complexity:
 The space complexity is O(n) for the recursion stack.

Example Inputs and Outputs:

1. Input: Enter the number of people: 7
          Enter the step rate: 3
   Output: The last person standing is at position: 4

2. Input: Enter the number of people: 10
          Enter the step rate: 2
   Output: The last person standing is at position: 5
*/
