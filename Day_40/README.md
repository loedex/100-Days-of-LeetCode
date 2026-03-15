# 📈 LeetCode 122 — Best Time to Buy and Sell Stock II

## 📌 Problem Description

**Difficulty:** Medium  
**Topics:** Array, Greedy, Dynamic Programming

You are given an integer array `prices` where:

```
prices[i] = price of a stock on day i
```

You may decide to **buy and/or sell the stock on any day**.

### Rules

- You can hold **at most one share** at a time.
- You **can buy and sell multiple times**.
- You may **buy and sell on the same day**.

Your task is to return the **maximum profit** you can achieve.

---

## 🧠 Example

### Example 1

**Input**

```
prices = [7,1,5,3,6,4]
```

**Output**

```
7
```

**Explanation**

```
Buy on day 2 (price = 1)
Sell on day 3 (price = 5)
Profit = 4

Buy on day 4 (price = 3)
Sell on day 5 (price = 6)
Profit = 3
```

Total profit:

```
4 + 3 = 7
```

---

### Example 2

**Input**

```
prices = [1,2,3,4,5]
```

**Output**

```
4
```

**Explanation**

Buy on day 1 and sell on day 5.

---

### Example 3

**Input**

```
prices = [7,6,4,3,1]
```

**Output**

```
0
```

**Explanation**

Prices keep decreasing, so no profit is possible.

---

## 🚀 Approach — Greedy Strategy

Instead of finding the **best single transaction**, we capture **every profitable increase**.

### Key Idea

If:

```
prices[i] > prices[i-1]
```

Then we add the profit:

```
profit += prices[i] - prices[i-1]
```

This effectively simulates buying yesterday and selling today whenever the price increases.

---

## 🔍 Steps

1. Initialize `profit = 0`
2. Traverse the array starting from index `1`
3. Compare current price with previous price
4. If current price is greater, add the difference to profit
5. Return total profit

---

## 💻 C++ Solution

```cpp
class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] > prices[i-1]) {
                profit += (prices[i] - prices[i-1]);
            }
        }

        return profit;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(n)
```

We traverse the array once.

---

### Space Complexity

```
O(1)
```

No additional space is used.

---

## 🎯 Key Concepts

- Greedy Algorithm
- Array Traversal
- Profit Accumulation
- Optimization Strategy

---

## 📚 LeetCode Problem

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

---

## 👨‍💻 Author

Husnain Ahmad

---

## ✅ Summary

✔ Greedy approach captures every profitable transaction  
✔ Handles multiple buy/sell operations  
✔ Efficient **O(n)** time solution  
✔ Constant **O(1)** space usage

```