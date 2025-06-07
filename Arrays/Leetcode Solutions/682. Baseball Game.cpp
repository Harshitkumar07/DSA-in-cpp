** Leetcode Problem 682 :- **

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.
The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

Example 1:
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

Example 3:
Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.

** Code :- **

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto ch : operations) {
            if (ch == "+") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1 + temp2);
            } else if (ch == "D") {
                st.push(st.top() * 2);
            } else if (ch == "C") {
                st.pop();
            } else {
                st.push(stoi(ch));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

** Time Complexity :- **

Let n be the number of operations in the input vector.
Step-by-step:
Processing each operation:
You iterate through each operation once: O(n)

For each operation:
"+": Pop and push → constant operations → O(1)
"D" and "C": Push or pop → O(1)
Number string → stoi(ch) → O(1) (since input strings are small and bounded in length)

Final summation of stack:
At most n elements in the stack → O(n)

Total Time Complexity :-
Best Case: O(n) (All operations are valid and simple)
Worst Case: O(n) (All operations require stack manipulation)
Overall: O(n)

** Space Complexity :- **

Stack usage:
Each number is pushed onto the stack
In worst case, all n operations are number pushes → O(n)

Auxiliary space:
A few integer variables (e.g., temp1, temp2, sum) → O(1)

Total Space Complexity :-
Best Case: O(1) (If all operations are "C" and stack remains small)
Worst Case: O(n) (All operations are valid and increase stack size)
Overall: O(n)
