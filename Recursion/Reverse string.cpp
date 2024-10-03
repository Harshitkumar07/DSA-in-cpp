/*
Problem Statement:
Reverse a string using recursion.

Approach:

1. Base Case: If the start index is greater than or equal to the end index, we stop recursion (the string is reversed).
2. Recursive Step: Swap the characters at the start and end positions, then recursively call the function for the next pair of characters (start + 1 and end - 1).

Code:
*/
#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end) {
    if (start >= end) {
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    reverseString(str, 0, str.length() - 1);
    cout << "Reversed string: " << str << endl;

    return 0;
}
/*
Time and Space Complexity:

◾ Time Complexity: O(n), where n is the length of the string. Each character is swapped once, and there are n/2 recursive calls.
◾ Space Complexity: O(n), as the recursion depth can go up to n/2 levels, requiring space for the call stack.

Sample Input and Output:

1. Input: Enter a string: hello
   Output: Reversed string: olleh

2. Input: Enter a string: Reverse
   Output: Reversed string: esreveR
*/
