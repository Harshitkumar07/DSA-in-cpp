/*
Problem Statement:
Generate all permutations of a string using recursion.

Approach:
1. Base Case:
  If the string has only one character, the only permutation is the string itself.

2. Recursive Case:

  For each character in the string, fix that character and recursively find permutations of the remaining characters.
  The result for each recursive call is concatenated with the fixed character to form full permutations.

Code -
*/

#include<iostream>
#include<string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]);  // backtrack
        }
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    permute(input, 0, input.length() - 1);
    return 0;
}

/*
◾ Time Complexity: O(n!)
  The number of permutations of a string of length n is n!.

◾ Space Complexity: O(n)
  The depth of the recursion is proportional to the string length, leading to O(n) space complexity.

Example Inputs and Outputs:

1. Input: "ABC"
   Output:
            ABC
            ACB
            BAC
            BCA
            CAB
            CBA

2. Input: "AB"
   Output:
           AB
           BA
*/
