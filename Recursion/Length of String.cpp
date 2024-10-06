/*
Problem Statement:
Find the length of a string using recursion.

Approach:
1. Base Case:
   If the string is empty, return 0.

2. Recursive Case:
   Return 1 plus the length of the rest of the string.

Code-

*/

#include<iostream>
using namespace std;

int LenofStr(string s) {
    if (s == "")
        return 0;
    return 1 + LenofStr(s.substr(1));
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of the string: " << LenofStr(s) << endl;
    return 0;
}
/*

Time Complexity:
◾ The time complexity is O(n) as each character is visited once.

Space Complexity:
◾ The space complexity is O(n) for the recursion stack.

Example Inputs and Outputs:
1. Input: Enter a string: Recursion
   Output: Length of the string: 9

2. Input: Enter a string: ui
   Output: Length of the string: 2

*/
