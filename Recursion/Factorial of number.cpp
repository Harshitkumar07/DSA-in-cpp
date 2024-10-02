//Problem Statement:
//Find the factorial of a given number n using recursion.

//Approach:

//1. The factorial of a number n is defined as n * (n-1) * (n-2) * ... * 1.
//2. Base Case: If n == 0 or n == 1, the factorial is 1.
//3. Recursive Case: If n > 1, return n * factorial(n - 1).

//Code :

#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factorial of " << num << " is : " << factorial(num) << endl;
    return 0;
}

//◾ Time Complexity:
  //◾ O(n) because we make a recursive call for each number from n down to 1.

//◾ Space Complexity:
  //◾ O(n) due to the recursion stack that grows linearly with n.

//Example Inputs and Outputs:

//1. Input: Enter a number: 5
  // Output: Factorial of 5 is : 120

//2. Input: Enter a number: 0
  // Output: Factorial of 0 is : 1

//3. Input: Enter a number: 7
  // Output: Factorial of 7 is : 5040

