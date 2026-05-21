# 258. Add Digits 🔢

<div align="center">

![LeetCode](https://img.shields.io/badge/LeetCode-258-orange?style=for-the-badge&logo=leetcode&logoColor=white)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![Topic](https://img.shields.io/badge/Topic-Math-purple?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Number_Theory-red?style=for-the-badge)

</div>

---

## 📌 Problem Statement

> Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

**LeetCode Link:** [Add Digits - Problem #258](https://leetcode.com/problems/add-digits/)

---

## 🧪 Examples

### Example 1
```
Input:  num = 38
Output: 2

Explanation:
  38  →  3 + 8 = 11
  11  →  1 + 1 = 2
  ✅ Single digit reached → return 2
```

### Example 2
```
Input:  num = 0
Output: 0

Explanation:
  0 is already a single digit → return 0
```

---

## 🚧 Constraints

| Constraint | Value |
|---|---|
| Minimum value of `num` | `0` |
| Maximum value of `num` | `2³¹ - 1` (i.e., `2147483647`) |

---

## 💡 Intuition & Approach

### 🔄 Iterative Digit Summing (Simulation)

The idea is beautifully simple — we keep **summing the digits** of the number in a loop until we're left with a **single-digit number** (i.e., `num < 10`).

#### Step-by-step Walkthrough for `num = 38`:

```
Iteration 1:
  num = 38
  sum = (38 % 10) + (3 % 10) = 8 + 3 = 11
  num = 11

Iteration 2:
  num = 11
  sum = (11 % 10) + (1 % 10) = 1 + 1 = 2
  num = 2

num < 10 → STOP → return 2 ✅
```

#### How does extracting digits work?
```
num = 38

Step 1: num % 10 = 8   (last digit)  →  sum = 8
        num / 10 = 3   (remove last digit)

Step 2: num % 10 = 3   (last digit)  →  sum = 8 + 3 = 11
        num / 10 = 0   (no more digits)

num = sum = 11   → continue outer loop
```

---

## 💻 Solution Code (C++)

```cpp
class Solution {
public:
    int addDigits(int num) {
        // Keep looping until num becomes a single digit
        while (num >= 10) {
            int sum = 0;

            // Extract and sum all digits of num
            while (num > 0) {
                sum += num % 10;   // Add the last digit
                num /= 10;         // Remove the last digit
            }

            num = sum;             // Replace num with its digit sum
        }

        return num;                // num is now a single digit
    }
};
```

---

## 📊 Complexity Analysis

| Metric | Value | Explanation |
|---|---|---|
| ⏱️ **Time Complexity** | `O(log n)` | Each outer iteration reduces `num` significantly (digit sum ≪ num). For a 32-bit integer, this converges in very few passes. |
| 🧠 **Space Complexity** | `O(1)` | No extra data structures — only a couple of integer variables used. |

---

## 🌳 Dry Run — Visual Trace

```
num = 9875

Pass 1: 9 + 8 + 7 + 5 = 29   →   num = 29
Pass 2: 2 + 9       = 11   →   num = 11
Pass 3: 1 + 1       =  2   →   num = 2

2 < 10 ✅ → return 2
```

---

## 🔁 Alternative Approach: Digital Root Formula (O(1))

> 💡 **Bonus Insight for curious minds!**

There's a mathematical trick called the **Digital Root**, based on number theory:

```
If num == 0:         return 0
If num % 9 == 0:     return 9
Otherwise:           return num % 9
```

Which can be written in one line:
```cpp
return (num == 0) ? 0 : (num % 9 == 0 ? 9 : num % 9);
// Or even shorter:
return 1 + (num - 1) % 9;
```

This runs in **O(1)** time and space — but requires understanding the **modulo-9 property** of digit sums. The simulation approach (used in our solution) is more intuitive and beginner-friendly!

---

## 🗂️ Related Problems

| Problem | Difficulty | Topic |
|---|---|---|
| [202. Happy Number](https://leetcode.com/problems/happy-number/) | Easy | Math, Hash Set |
| [1342. Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) | Easy | Math, Bit Manipulation |
| [1085. Sum of Digits in the Minimum Number](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/) | Easy | Math |

---

## 🏷️ Tags

`Math` · `Number Theory` · `Simulation` · `Digital Root` · `Easy`

---

<div align="center">

⭐ **If this helped you, consider giving the repo a star!** ⭐

*Happy Coding! Keep solving, keep growing. 🚀*

</div>