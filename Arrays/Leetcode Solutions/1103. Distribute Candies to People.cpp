** Leetcode Problem 1103 :- **

We distribute some number of candies, to a row of n = num_people people in the following way:
We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.
Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.
This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.  The last person will receive all of our remaining candies (not necessarily one more than the previous gift).
Return an array (of length num_people and sum candies) that represents the final distribution of candies.

Example 1:
Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].

Example 2:
Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].

** Code :- **

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0, candyCount = 1;
        while (candies > 0) {
            ans[i] += min(candyCount, candies);
            candies -= min(candyCount, candies);
            i = (i + 1) % num_people;
            candyCount++;
        }
        return ans;
    }
};

** Time Complexity :- **

Step 1: Iterating Through Candy Distribution
The algorithm distributes candies one by one, incrementing the amount given to each person.
It continues until all candies are distributed.
If C is the total number of candies, the number of iterations follows the sequence:
1+2+3+...+k≤C
The sum of the first k natural numbers is: k(k+1)/2≤C
Solving for k, we get:
k=O(C)
Since each step involves O(1) operations, the total time complexity is O(√C).

Total Time Complexity :
Best Case: O(1) → If candies is small, very few iterations occur.
Worst Case: O(√C) → The loop runs until the sum of numbers reaches candies.
Overall: O(√C) (Square Root Complexity)

** Space Complexity :- **

Step 1: Storage for the Result Vector
The algorithm uses a vector ans of size num_people to store the distributed candies.
This requires O(num_people) space.
No other significant auxiliary space is used.

Total Space Complexity :
Best Case: O(num_people) → Space usage is constant for a fixed number of people.
Worst Case: O(num_people) → The same applies even if candies is large.
Overall: O(num_people) (Linear Space Complexity in Terms of Participants)
