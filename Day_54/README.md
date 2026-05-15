# 414. Third Maximum Number

![LeetCode](https://img.shields.io/badge/LeetCode-414-orange?style=flat-square&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Topic](https://img.shields.io/badge/Topic-Array-lightgrey?style=flat-square)
![Status](https://img.shields.io/badge/Status-Solved-success?style=flat-square)

---

## Table of Contents

- [Problem Statement](#problem-statement)
- [Examples](#examples)
- [Constraints](#constraints)
- [Approach & Intuition](#approach--intuition)
- [Algorithm Walkthrough](#algorithm-walkthrough)
- [Complexity Analysis](#complexity-analysis)
- [Code](#code)
- [Edge Cases](#edge-cases)
- [Key Takeaways](#key-takeaways)

---

## Problem Statement

Given an integer array `nums`, return the **third distinct maximum** number in the array.  
If the third distinct maximum does not exist, return the **maximum** number.

> **Note:** The word *distinct* here means we count unique values only — duplicates of the same number are treated as a single occurrence.

---

## Examples

### Example 1

```
Input:  nums = [3, 2, 1]
Output: 1
```
**Explanation:** The three distinct maximums are `3`, `2`, and `1`. The third maximum is `1`.

---

### Example 2

```
Input:  nums = [1, 2]
Output: 2
```
**Explanation:** Only two distinct numbers exist. Since a third maximum does not exist, we return the overall maximum, which is `2`.

---

### Example 3

```
Input:  nums = [2, 2, 3, 1]
Output: 1
```
**Explanation:** The three distinct maximums are `3`, `2`, and `1` (duplicates of `2` are ignored). The third maximum is `1`.

---

## Constraints

| Property        | Value                                      |
|-----------------|--------------------------------------------|
| Array Size      | `1 <= nums.length <= 10⁴`                  |
| Element Range   | `-2³¹ <= nums[i] <= 2³¹ - 1` (`INT` range)|

---

## Approach & Intuition

The goal is to track the **top 3 distinct maximum values** seen so far in a single pass through the array.

### Why Not Sort?

Sorting would solve this in `O(n log n)` time, but we can do better — **O(n)** — by maintaining just three variables representing the 1st, 2nd, and 3rd largest distinct values seen so far.

### The `LLONG_MIN` Trick

Since the problem allows values as small as `INT_MIN` (`-2,147,483,648`), we **cannot** use `INT_MIN` as a sentinel "unset" value — a valid input might actually equal `INT_MIN`, which would cause a false positive match.

Instead, we use `LLONG_MIN` (the minimum value of `long long`, approximately `-9.2 × 10¹⁸`) as our initial placeholder. This guarantees that no valid `int` input can ever equal our sentinel, eliminating any ambiguity.

---

## Algorithm Walkthrough

We maintain three `long long` variables:

| Variable | Represents             | Initial Value |
|----------|------------------------|---------------|
| `first`  | 1st largest (maximum)  | `LLONG_MIN`   |
| `second` | 2nd largest            | `LLONG_MIN`   |
| `third`  | 3rd largest            | `LLONG_MIN`   |

**For each number in `nums`:**

1. **Skip duplicates** — if `num` equals `first`, `second`, or `third`, ignore it.
2. **Update the top three** using a cascading shift:
   - If `num > first` → shift `first → second → third`, set `first = num`
   - Else if `num > second` → shift `second → third`, set `second = num`
   - Else if `num > third` → set `third = num`

**At the end:**

- If `third` is still `LLONG_MIN`, a third distinct maximum was never found → return `first`.
- Otherwise, return `third`.

### Visual Dry Run — `nums = [2, 2, 3, 1]`

| Step | num | Action                     | first | second | third |
|------|-----|----------------------------|-------|--------|-------|
| Init | —   | —                          | -∞    | -∞     | -∞    |
| 1    | 2   | 2 > first (-∞) → update    | 2     | -∞     | -∞    |
| 2    | 2   | Duplicate of first → skip  | 2     | -∞     | -∞    |
| 3    | 3   | 3 > first (2) → cascade    | 3     | 2      | -∞    |
| 4    | 1   | 1 > third (-∞) → update    | 3     | 2      | 1     |

`third != LLONG_MIN` → return `1` ✅

---

## Complexity Analysis

| Metric           | Value    | Explanation                                              |
|------------------|----------|----------------------------------------------------------|
| **Time**         | `O(n)`   | Single pass through the array                            |
| **Space**        | `O(1)`   | Only three variables used, regardless of input size      |

---

## Code

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // We use long long to handle the case where INT_MIN is in the input
        long long first  = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third  = LLONG_MIN;

        for (int num : nums) {
            // Skip duplicates
            if (num == first || num == second || num == third) continue;

            if (num > first) {
                third  = second;
                second = first;
                first  = num;
            } else if (num > second) {
                third  = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If third hasn't been updated, return the first max
        return (third == LLONG_MIN) ? (int)first : (int)third;
    }
};
```

---

## Edge Cases

| Scenario                         | Input              | Expected Output | Reason                                          |
|----------------------------------|--------------------|-----------------|-------------------------------------------------|
| Fewer than 3 distinct elements   | `[1, 2]`           | `2`             | No third max exists → return maximum            |
| All elements are duplicates      | `[5, 5, 5]`        | `5`             | Only one distinct value → return maximum        |
| `INT_MIN` present in input       | `[1, 2, INT_MIN]`  | `INT_MIN`       | `INT_MIN` is a valid 3rd max, must not be skipped|
| Array with a single element      | `[42]`             | `42`            | Only one element → return it as the maximum     |
| Three distinct negatives         | `[-1, -2, -3]`     | `-3`            | Third max among negatives is `-3`               |

---

## Key Takeaways

- **Sentinel value matters** — always think carefully about the range of valid input values before choosing a placeholder. `INT_MIN` would silently break this solution; `LLONG_MIN` keeps it safe.
- **Cascading updates** — the order of the `if / else if` checks is critical. Checking `num > first` first and cascading downward ensures we never skip or double-count a position.
- **O(1) space** — maintaining a fixed number of tracking variables is a common and elegant technique for "top-K" problems when K is small and known.
- **Duplicate handling** — the early `continue` guard is essential for correctness. Without it, the same number could occupy two of the three slots.

---

*Solved with a single-pass O(n) time, O(1) space approach using cascading maximum tracking.*