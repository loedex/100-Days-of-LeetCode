# 263. Ugly Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topic](https://img.shields.io/badge/Topic-Math-blue)
![Language](https://img.shields.io/badge/Language-C++-00599C?logo=cplusplus)
![Status](https://img.shields.io/badge/Status-Solved-success)

---

## 📋 Problem Statement

> An **ugly number** is a positive integer whose prime factors are limited to **2**, **3**, and **5**.

Given an integer `n`, return `true` if `n` is an **ugly number**, otherwise return `false`.

🔗 [View on LeetCode](https://leetcode.com/problems/ugly-number/)

---

## 🧪 Examples

### Example 1
```
Input:  n = 6
Output: true
Reason: 6 = 2 × 3  →  both 2 and 3 are valid prime factors
```

### Example 2
```
Input:  n = 1
Output: true
Reason: 1 has no prime factors, so it is trivially ugly (by convention)
```

### Example 3
```
Input:  n = 14
Output: false
Reason: 14 = 2 × 7  →  7 is NOT an allowed prime factor
```

---

## 📐 Constraints

| Constraint | Value |
|---|---|
| Range of `n` | `-2³¹ <= n <= 2³¹ - 1` |

---

## 💡 Intuition

Think of it this way — if a number is *only* made up of 2s, 3s, and 5s multiplied together, then we should be able to **completely divide it down to 1** using just those three factors.

Like peeling an onion 🧅:
- Keep dividing by `2` until you can't anymore
- Then keep dividing by `3` until you can't anymore
- Then keep dividing by `5` until you can't anymore
- If **nothing is left** (i.e., `n == 1`), it's an ugly number!

---

## 🚀 Approach — Prime Factor Reduction

### Step-by-Step Walkthrough

| Step | What We Do |
|------|------------|
| **1** | Guard against `n <= 0` — ugly numbers must be **positive** |
| **2** | Divide `n` by `2` repeatedly until it's no longer divisible |
| **3** | Divide `n` by `3` repeatedly until it's no longer divisible |
| **4** | Divide `n` by `5` repeatedly until it's no longer divisible |
| **5** | Check if `n == 1` — if yes ✅ ugly, if no ❌ not ugly |

### Dry Run — `n = 12`

```
n = 12
÷ 2 → n = 6
÷ 2 → n = 3
÷ 3 → n = 1   ✅  →  return true
```

### Dry Run — `n = 14`

```
n = 14
÷ 2 → n = 7
7 % 3 ≠ 0  →  skip
7 % 5 ≠ 0  →  skip
n = 7 ≠ 1  ❌  →  return false
```

---

## 💻 Solution

```cpp
class Solution {
public:
    bool isUgly(int n) {

        // Ugly numbers must be positive
        if (n <= 0) return false;
        
        // Repeatedly divide by 2, 3, and 5
        int factors[] = {2, 3, 5};
        for (int f : factors) {
            while (n % f == 0) {
                n /= f;
            }
        }
        
        // If n becomes 1, it's an ugly number
        return n == 1;
    }
};
```

---

## 📊 Complexity Analysis

| | Complexity | Explanation |
|---|---|---|
| **Time** | `O(log n)` | Each division reduces `n` significantly (at minimum halved each step) |
| **Space** | `O(1)` | No extra data structures — only the input integer is modified |

---

## 🔑 Key Takeaways

- **Always handle edge cases first** — non-positive integers are never ugly.
- **Prime factorization by trial** is a clean and effective strategy for small, known factor sets.
- Modifying the input `n` directly (no extra variable) keeps space usage minimal.
- The loop over `{2, 3, 5}` makes the code **easy to extend** if the factor set ever changes.

---

## 🏷️ Tags

`Math` · `Prime Factorization` · `Easy` · `C++`