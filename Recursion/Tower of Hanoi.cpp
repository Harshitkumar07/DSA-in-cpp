/*
Problem Statement:
Solve the Tower of Hanoi problem with n disks.

Approach:
1. Base Case:
  If there is only 1 disk, move it directly from the source rod to the destination rod.

2. Recursive Case:

  Move the top n-1 disks from the source rod to the auxiliary rod, using the destination rod as a helper.
  Move the nth disk from the source rod to the destination rod.
  Move the n-1 disks from the auxiliary rod to the destination rod using the source rod as a helper.

Code -
*/

#include<iostream>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    // A is the source, C is the destination, B is auxiliary
    return 0;
}
/*
◾ Time Complexity: O(2^n)
  The problem reduces to solving two smaller subproblems with n-1 disks, making it an exponential time problem.

◾ Space Complexity: O(n)
  The recursion depth is proportional to the number of disks n.

Example Inputs and Outputs:

1. Input: n = 2
  Output:
    Move disk 1 from A to B
    Move disk 2 from A to C
    Move disk 1 from B to C

2. Input: n = 3
  Output:
    Move disk 1 from A to C
    Move disk 2 from A to B
    Move disk 1 from C to B
    Move disk 3 from A to C
    Move disk 1 from B to A
    Move disk 2 from B to C
    Move disk 1 from A to C
*/
