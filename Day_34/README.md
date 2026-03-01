# 🟢 LeetCode 121 – Best Time to Buy and Sell Stock

**Difficulty:** Easy  
**Topics:** Array, Dynamic Programming

---

## 📘 Problem Statement

You are given an array **prices** where:

```
prices[i]
```

represents the price of a stock on day **i**.

You want to maximize your profit by:

- Buying on one day
- Selling on a future day

Return:

```
Maximum possible profit
```

If no profit is possible:

```
Return 0
```

---

## 🧾 Example

### Example 1

**Input**

```
prices = [7,1,5,3,6,4]
```

**Output**

```
5
```

**Explanation**

```
Buy at price = 1
Sell at price = 6

Profit = 6 - 1 = 5
```

---

### Example 2

**Input**

```
prices = [7,6,4,3,1]
```

**Output**

```
0
```

**Explanation**

```
No profitable transaction possible
```

---

## 💡 Key Idea

We need:

```
Maximum (Sell Price - Buy Price)
```

Where:

```
Buy Day < Sell Day
```

---

## 🧠 Approach

### Step 1 — Track Minimum Price

Keep track of:

```
Minimum price seen so far
```

```
minPriceDay
```

---

### Step 2 — Calculate Profit

For every day:

```
profit = currentPrice - minPriceDay
```

---

### Step 3 — Update Maximum Profit

Keep track of:

```
maxProfit
```

---

### Step 4 — Return Result

Return:

```
maxProfit
```

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|----------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

### Explanation

- Single loop → O(n)
- No extra memory → O(1)

---

## 💻 C++ Implementation

```cpp
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int minPriceDay = INT_MAX;
        int maxProfit = INT_MIN;
        
        for(int i=0; i<prices.size(); i++){
            
            // Update minimum price
            if(prices[i] < minPriceDay){
                minPriceDay = prices[i];
            }
            
            // Calculate profit
            int profit = prices[i] - minPriceDay;
            
            // Update maximum profit
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};
```

---

## 🔎 Dry Run

### Input

```
prices = [7,1,5,3,6,4]
```

---

### Step-by-Step

| Day | Price | Min Price | Profit | Max Profit |
|-----|------|----------|--------|-----------|
| 1 | 7 | 7 | 0 | 0 |
| 2 | 1 | 1 | 0 | 0 |
| 3 | 5 | 1 | 4 | 4 |
| 4 | 3 | 1 | 2 | 4 |
| 5 | 6 | 1 | 5 | 5 |
| 6 | 4 | 1 | 3 | 5 |

---

### Final Answer

```
5
```

---

## 🚀 Why This Solution Works

✔ One pass solution  
✔ Very efficient  
✔ No extra memory  
✔ Simple logic

---

## 📌 Important Notes

- Must buy before selling
- Minimum price must come first
- Works for large inputs

---

⭐ This is a classic **Greedy Algorithm** problem.

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast