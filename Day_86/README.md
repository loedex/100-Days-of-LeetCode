<div align="center">

# Day XX: Arranging Coins

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-441-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Runtime](https://img.shields.io/badge/Runtime-0%20ms%20(100%25)-brightgreen?style=for-the-badge)

</div>

---

## Problem Statement

You have `n` coins and you want to build a staircase with these coins. The staircase consists of `k` rows where the `i`-th row has exactly `i` coins. The last row of the staircase **may be incomplete**.

Given the integer `n`, return the number of **complete rows** of the staircase you will build.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `n = 5` | `2` | Rows 1 and 2 are complete (1 + 2 = 3 coins). Row 3 needs 3 coins but only 2 remain. |
| 2 | `n = 8` | `3` | Rows 1, 2 and 3 are complete (1 + 2 + 3 = 6 coins). Row 4 needs 4 coins but only 2 remain. |

### Constraints

- `1 <= n <= 2^31 - 1`

---

## Intuition

To build `k` complete rows, we need:

```text
1 + 2 + 3 + ... + k  =  k(k + 1) / 2   coins
```

This is the sum of the first `k` natural numbers (a **triangular number**). So the question becomes:

> What is the largest `k` such that `k(k + 1) / 2 <= n`?

Since `n` can be as large as about 2.1 billion, building the staircase row by row would work but is unnecessary. This inequality can be solved directly with **mathematics** in constant time.

---

## Approach

**Solve the quadratic inequality using the quadratic formula.**

**Step 1: Set up the inequality**

```text
k(k + 1) / 2 <= n
k^2 + k <= 2n
k^2 + k - 2n <= 0
```

**Step 2: Find the positive root of `k^2 + k - 2n = 0`**

Using the quadratic formula with `a = 1`, `b = 1`, `c = -2n`:

```text
k = (-1 + sqrt(1 + 8n)) / 2
```

We take the **positive** root only, since the number of rows cannot be negative.

**Step 3: Take the floor**

The exact root is usually a fraction, but we need the number of **complete** rows, so we round **down**. In C++, converting a positive `double` to `int` **truncates** the decimal part, which is exactly the floor operation. That is why the function returns the value directly.

### Why `8.0 * n` instead of `8 * n`?

Because `n` can be up to `2^31 - 1`, the expression `8 * n` would **overflow** a 32-bit `int`. Writing `8.0` forces the calculation to use `double`, which safely holds the larger value.

### Dry Run

**Example 1: `n = 5`**

| Step | Expression | Value |
|:----:|-----------|:-----:|
| 1 | `1 + 8.0 * 5` | `41.0` |
| 2 | `sqrt(41.0)` | `6.403...` |
| 3 | `-1 + 6.403...` | `5.403...` |
| 4 | `5.403... / 2` | `2.701...` |
| 5 | Convert to `int` (truncate) | **`2`** |

**Example 2: `n = 8`**

| Step | Expression | Value |
|:----:|-----------|:-----:|
| 1 | `1 + 8.0 * 8` | `65.0` |
| 2 | `sqrt(65.0)` | `8.062...` |
| 3 | `-1 + 8.062...` | `7.062...` |
| 4 | `7.062... / 2` | `3.531...` |
| 5 | Convert to `int` (truncate) | **`3`** |

---

## Solution (C++)

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + 8.0 * n)) / 2;
    }
};
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(1)` | The answer is computed with a fixed number of arithmetic operations, regardless of the size of `n`. |
| **Space** | `O(1)` | No extra data structures are used. |

---

## Submission Result

| Metric | Result |
|--------|--------|
| **Status** | Accepted (1336 / 1336 test cases passed) |
| **Runtime** | 0 ms, beats 100.00% of C++ submissions |
| **Memory** | 8.81 MB, beats 28.52% of C++ submissions |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `n = 1` | `sqrt(9) = 3`, so `(3 - 1) / 2 = 1`. One complete row. |
| Perfect staircase (e.g. `n = 6`) | `sqrt(49) = 7`, so `(7 - 1) / 2 = 3`. The square root is exact, so the result is exactly `3`. |
| Largest input `n = 2^31 - 1` | `8.0 * n` is computed in `double`, so there is no integer overflow. |
| Incomplete last row | The fractional part is truncated, so partial rows are not counted. |

---

## Key Takeaways

- Recognizing the **triangular number** pattern `k(k + 1) / 2` turns a simulation problem into a formula.
- Solving `k^2 + k - 2n <= 0` with the quadratic formula gives the answer in constant time.
- Using `8.0 * n` avoids integer overflow near the upper constraint.
- Converting a positive `double` to `int` in C++ acts as a floor operation.

### Alternative Approaches

| Approach | Time | Space | Idea |
|----------|:----:|:-----:|------|
| **Simulation** | `O(sqrt(n))` | `O(1)` | Subtract `1, 2, 3, ...` from `n` until there are not enough coins for the next row. |
| **Binary Search** | `O(log n)` | `O(1)` | Search for the largest `k` where `k(k + 1) / 2 <= n`. Uses `long long` to avoid overflow. |
| **Math Formula (this solution)** | `O(1)` | `O(1)` | Solve the quadratic directly. |

---

## Related Problems

- Sqrt(x) (LeetCode 69)
- Valid Perfect Square (LeetCode 367)
- Pascal's Triangle (LeetCode 118)
- Climbing Stairs (LeetCode 70)