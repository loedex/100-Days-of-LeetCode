# 202. Happy Number

![LeetCode](https://img.shields.io/badge/LeetCode-202-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-JavaScript-yellow?style=for-the-badge&logo=javascript)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=for-the-badge)

---

## 📝 Problem Statement

Write an algorithm to determine if a number `n` is a **happy number**.

A **happy number** is defined by the following process:

- Starting with any positive integer, replace the number by the **sum of the squares of its digits**.
- Repeat the process until the number equals `1` (where it will stay), or it **loops endlessly in a cycle** that does not include `1`.
- Those numbers for which this process **ends in 1** are happy.

Return `true` if `n` is a happy number, and `false` if not.

---

## 📌 Examples

### Example 1

```
Input:  n = 19
Output: true
```

**Explanation:**

```
1² + 9²       = 1 + 81  = 82
8² + 2²       = 64 + 4  = 68
6² + 8²       = 36 + 64 = 100
1² + 0² + 0²  = 1       ✅ Happy!
```

### Example 2

```
Input:  n = 2
Output: false
```

**Explanation:** The process enters an infinite cycle and never reaches `1`.

---

## 💡 Approach — Hash Set (Cycle Detection)

The tricky part of this problem is knowing **when to stop**. Two things can happen:

| Outcome | Condition |
|---------|-----------|
| ✅ Happy | `n` eventually becomes `1` |
| ❌ Not Happy | `n` enters an **infinite cycle** — the same number repeats |

> The key insight: if we ever **see the same number twice**, we're stuck in a cycle → return `false`.  
> We detect this using a **Hash Set** (`seen`) that tracks every number we've visited.

### Algorithm Steps:

1. Keep a `Set` called `seen` to remember visited numbers.
2. Loop while `n !== 1` **AND** `n` hasn't been seen before.
3. Inside the loop:
   - Add `n` to `seen`.
   - Replace `n` with the sum of the squares of its digits (via helper `sumOfSquareOfDigits`).
4. After the loop, if `n === 1` → return `true`, else `false`.

### Helper Function — `sumOfSquareOfDigits`:

- Uses `num % 10` to extract the **last digit**.
- Squares it and adds to `totalSum`.
- Uses `Math.floor(num / 10)` to chop off the last digit.
- Repeats until all digits are processed.

---

## 🧠 Complexity Analysis

| | Complexity |
|---|---|
| **Time**  | O(log n) per step, bounded by cycle length |
| **Space** | O(log n) — numbers stored in the `seen` set before a cycle is detected |

---

## 💻 Solution (JavaScript)

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    const seen = new Set()
    while(n !== 1 && !(seen.has(n))){
        seen.add(n);
        n = sumOfSquareOfDigits(n);
    }
    return n == 1;
};

var sumOfSquareOfDigits = function(num){
    let totalSum = 0
    while(num > 0){
        let digit = num % 10;
        totalSum += digit * digit;
        num = Math.floor(num / 10);
    }
    return totalSum;
}
```

---

## 🔍 Step-by-Step Walkthrough

Let's trace `n = 19`:

| Step | `n` (before) | `seen` set          | `sumOfSquareOfDigits(n)` | `n` (after) |
|------|--------------|---------------------|--------------------------|-------------|
| 1    | 19           | `{}`                | 1² + 9² = 82             | 82          |
| 2    | 82           | `{19}`              | 8² + 2² = 68             | 68          |
| 3    | 68           | `{19, 82}`          | 6² + 8² = 100            | 100         |
| 4    | 100          | `{19, 82, 68}`      | 1² + 0² + 0² = 1         | 1           |
| 5    | 1            | `{19, 82, 68, 100}` | Loop exits: `n === 1` ✅  | —           |

Return `true` 🎉

---

## ⚠️ Why Can't We Loop Forever?

You might wonder — what if it never reaches 1 and the set just keeps growing? The answer is:

> For any number `n`, the sequence of values produced is **bounded**. Numbers with 3+ digits always reduce to something smaller. Eventually, the sequence **must** either hit `1` or revisit a number — and our `seen` set catches the revisit immediately.

---

## ⚠️ Edge Cases

| Input | Expected | Reason                          |
|-------|----------|---------------------------------|
| `1`   | `true`   | Already 1, loop never runs      |
| `7`   | `true`   | Classic happy number            |
| `2`   | `false`  | Enters cycle: 2→4→16→37→58→89→145→42→20→4... |
| `4`   | `false`  | Enters same cycle as 2          |

---

## ✅ Submission Results

| Metric            | Value     | Beats          |
|-------------------|-----------|----------------|
| Runtime           | 0 ms      | 🏆 **100.00%** |
| Memory            | 56.36 MB  | 29.56%         |
| Test Cases Passed | 420 / 420 | ✅ All Passed  |

---

## 🔗 Problem Link

[LeetCode 202 — Happy Number](https://leetcode.com/problems/happy-number/)

---

## 👨‍💻 Author

**Husnain Ahmad**

---

> 💬 *Feel free to open an issue or pull request if you have a more optimized approach!*