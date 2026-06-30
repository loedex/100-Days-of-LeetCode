# 342. Power of Four

![LeetCode](https://img.shields.io/badge/LeetCode-342-orange?style=flat-square&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Topic](https://img.shields.io/badge/Topic-Math%20%7C%20Bit%20Manipulation-purple?style=flat-square)

---

## 📌 Problem Statement

Given an integer `n`, return `true` if it is a power of four. Otherwise, return `false`.

An integer `n` is a power of four if there exists an integer `x` such that `n == 4^x`.

> 🔗 [View on LeetCode](https://leetcode.com/problems/power-of-four/)

---

## 🧪 Examples

**Example 1**
```
Input:  n = 16
Output: true
Explanation: 16 = 4^2
```

**Example 2**
```
Input:  n = 5
Output: false
Explanation: There is no integer x such that 4^x = 5.
```

**Example 3**
```
Input:  n = 1
Output: true
Explanation: 1 = 4^0
```

---

## 💡 Intuition & Approach

This solution uses a simple **iterative division** strategy — no bit tricks required, just clean repeated division:

1. **Reject non-positive numbers immediately.** Powers of four are always positive (`4^0 = 1`, `4^1 = 4`, `4^2 = 16`, …), so any `n <= 0` can never qualify.
2. **Keep dividing by 4** as long as `n` is evenly divisible by `4` (`n % 4 == 0`). Each successful division strips away one factor of `4`.
3. **Check what's left.** If `n` is truly a power of four, this process will whittle it all the way down to `1`. If it stops at any other number, `n` was never a pure power of four to begin with.

For example, walking through `n = 64`:
```
64 % 4 == 0  →  n = 16
16 % 4 == 0  →  n = 4
4  % 4 == 0  →  n = 1
loop ends (1 % 4 != 0)  →  return (n == 1) → true ✅
```

And for `n = 32` (a power of two, but **not** of four):
```
32 % 4 == 0  →  n = 8
8  % 4 != 0  →  loop ends
return (n == 1) → false ✅  (since n is 8, not 1)
```

---

## ✅ Solution

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        // Powers of four must be positive
        if (n <= 0) return false;
        
        // Keep dividing by 4 if there is no remainder
        while (n % 4 == 0) {
            n /= 4;
        }
        
        // If we reached 1, it's a power of four
        return n == 1;
    }
};
```

---

## 📊 Complexity Analysis

| | Complexity | Reason |
|---|---|---|
| **Time** | `O(log₄ n)` | We divide `n` by `4` repeatedly until it's no longer divisible |
| **Space** | `O(1)` | No extra data structures, just the loop variable itself |

---

## 🔍 Notes & Alternative Approaches

This loop-based solution is great because it's **easy to read and reason about** — perfect for understanding the problem before optimizing. If you want to go further, here are two common follow-ups:

| Approach | Idea |
|---|---|
| **Bit Manipulation (O(1))** | A power of four is a power of two (`n & (n-1) == 0`) where the single set bit sits at an **even position**. This can be checked with a precomputed bitmask like `0x55555555`. |
| **Logarithm Trick** | Check if `log(n) / log(4)` is a whole number — but this is risky due to floating-point precision errors, so it's generally avoided in interviews. |

The iterative version above is fully correct and intuitive — a great first solution before exploring the `O(1)` bitwise trick as a bonus challenge!

---

## 🏷️ Tags

`Math` · `Bit Manipulation` · `Iteration`

---

## 📁 Repository Structure

```
342-power-of-four/
├── README.md
└── solution.cpp
```