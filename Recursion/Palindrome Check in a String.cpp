/*
Problem Statement:
Check if a string is a palindrome using recursion.

Approach:
1. Base Case:
   If the string has zero or one character, it's a palindrome.

2. Recursive Case:
   Compare the first and last characters. If they are equal, check if the substring (excluding the first and last characters)
              is a palindrome.
   For a string s, the recursive check can be written as:
              isPalindrome(s, i, j) = s[i] == s[j] && isPalindrome(s, i+1, j-1).

Code -
*/
#include<iostream>
using namespace std;

bool isPalindrome (string str, int start, int end)
{
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome (str, start + 1, end - 1);
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;
    if (isPalindrome (input, 0, input.length() - 1)) {
        cout << input << " is a palindrome." << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }
    return 0;
}

/*
◾ Time Complexity: O(n)
  Each pair of characters is compared, and the recursion happens n/2 times.

◾ Space Complexity: O(n)
  The recursion depth is n/2, so the space complexity is linear in terms of the string length.

Example Inputs and Outputs:

1. Input: Enter a string: racecar
   Output: racecar is a palindrome.

2. Input: Enter a string: hello
   Output: hello is not a palindrome.

3. Input: Enter a string: madam
   Output: madam is a palindrome.

*/
