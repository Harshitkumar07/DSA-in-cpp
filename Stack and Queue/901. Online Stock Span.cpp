** Leetcode Problem 901 :- **

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:
StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.

Example 1:

Input :
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output :
[null, 1, 1, 1, 2, 1, 4, 6]
Explanation :
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6

** Code :- **

class StockSpanner {
public:
    StockSpanner() {}

    vector<int> span;
    vector<int> stock;
    stack<int> s;

    int next(int price) {
        int i = stock.size();
        stock.push_back(price);
        span.push_back(1);

        while (!s.empty() && stock[s.top()] <= price) {
            s.pop();
        }
        if (!s.empty()) {
            span[i] = i - s.top();
        } else {
            span[i] = i + 1;
        }
        s.push(i);
        return span[i];
    }
};

** Time Complexity :- **
    
Step 1: Processing Each Price
Each call to next(price) inserts a new stock price and calculates its span.
The algorithm uses a monotonic decreasing stack to efficiently find the span.
The while loop ensures that each element is pushed and popped from the stack only once.
The total number of stack operations (push + pop) over all calls is O(N).
Total Time Complexity :
Best Case: O(1) → If stock prices are strictly decreasing, each price is simply pushed onto the stack.
Worst Case: O(N) → If stock prices are strictly increasing, each price causes multiple elements to be popped from the stack before being pushed.
Amortized Complexity: O(1) per call, leading to O(N) for N calls.

** Space Complexity :- **
    
Step 1: Storage for Prices and Spans
The stock and span vectors store all previous prices and their spans, requiring O(N) space for N calls.
The stack stores indices of stock prices in a monotonic decreasing order.
In the worst case (strictly increasing prices), the stack holds all N elements, leading to O(N) space usage.
Total Space Complexity :
Best Case: O(1) → If stock prices are strictly decreasing, the stack always contains one element at a time.
Worst Case: O(N) → If stock prices are strictly increasing, the stack stores all indices.
Overall: O(N) (Linear Space Complexity)
