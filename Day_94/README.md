<div align="center">

# Day 94: Pascal's Triangle

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-118-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Dynamic%20Programming-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Runtime](https://img.shields.io/badge/Runtime-0%20ms%20(100%25)-brightgreen?style=for-the-badge)

</div>

---

## Problem Statement

You are given an integer `numRows`.

Return the first `numRows` of **Pascal's triangle**.

In Pascal's triangle, each number is the **sum of the two numbers directly above it**, and the first and last number on each row must be equal to `1`.

```text
Row 0:            1
Row 1:          1   1
Row 2:        1   2   1
Row 3:      1   3   3   1
Row 4:    1   4   6   4   1
```

### Examples

| Example | Input | Output |
|:-------:|-------|--------|
| 1 | `numRows = 5` | `[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]` |
| 2 | `numRows = 1` | `[[1]]` |

### Constraints

- `1 <= numRows <= 30`

---

## Intuition

Look closely at the triangle. Two rules describe everything:

1. **The edges are always `1`.** The first and last element of every row equal `1`.
2. **Every inner element is the sum of the two elements above it**, one up-left and one directly up-right:

```text
row[i][j] = row[i-1][j-1] + row[i-1][j]
```

This is a small example of **dynamic programming**: each new row is built from the previous row, which we have already computed and stored.

Another useful fact is that row `i` (counting from 0) always contains exactly `i + 1` elements.

---

## Approach

**Build the triangle row by row, using the previous row to compute the next.**

1. Create an empty list `triangle` that will hold all the rows.
2. For each row index `i` from `0` to `numRows - 1`:
   - Create a new `row` of size `i + 1`, with **every element initialized to `1`**. This takes care of both edge elements automatically.
   - For each **inner** position `j` from `1` to `i - 1`, set `row[j] = triangle[i-1][j-1] + triangle[i-1][j]`.
   - Append `row` to `triangle`.
3. Return `triangle`.

### Why initialize everything to 1?

Since the first and last elements of every row are `1`, filling the whole row with `1` first means we only need to compute the **inner** elements. This removes the need for special cases at the edges.

### Why is `triangle[i - 1]` always safe to access?

The inner loop `for (int j = 1; j < i; ++j)` only runs when `i >= 2`. For rows 0 and 1, the loop body never executes (there are no inner elements), so the code never reads from a row that does not exist yet.

### Dry Run

**Example 1: `numRows = 5`**

| Row `i` | Initial `row` | Inner updates | Final row |
|:-------:|:-------------:|---------------|:---------:|
| 0 | `[1]` | none | `[1]` |
| 1 | `[1, 1]` | none | `[1, 1]` |
| 2 | `[1, 1, 1]` | `row[1] = 1 + 1 = 2` | `[1, 2, 1]` |
| 3 | `[1, 1, 1, 1]` | `row[1] = 1 + 2 = 3`, `row[2] = 2 + 1 = 3` | `[1, 3, 3, 1]` |
| 4 | `[1, 1, 1, 1, 1]` | `row[1] = 1 + 3 = 4`, `row[2] = 3 + 3 = 6`, `row[3] = 3 + 1 = 4` | `[1, 4, 6, 4, 1]` |

**Result: `[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]`**

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;
        
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1);
            
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
```

---

## Complexity Analysis

Let `n = numRows`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n^2)` | Row `i` has `i + 1` elements, so the total work is `1 + 2 + ... + n`, which is about `n^2 / 2`. |
| **Space** | `O(n^2)` | The output itself stores all `n(n + 1) / 2` numbers. Beyond the output, only one temporary row is used. |

---

## Submission Result

| Metric | Result |
|--------|--------|
| **Status** | Accepted |
| **Runtime** | 0 ms, beats 100.00% of C++ submissions |
| **Memory** | 9.52 MB, beats 83.25% of C++ submissions |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `numRows = 1` | Only row 0 is built, giving `[[1]]`. |
| `numRows = 2` | Rows `[1]` and `[1,1]`. The inner loop never runs. |
| Largest input `numRows = 30` | The biggest value is `C(29, 14) = 77,558,760`, which fits safely in a 32-bit `int`. |
| Edge elements | Always `1`, thanks to the initial fill. |
| Symmetry | Every row reads the same forwards and backwards. |

---

## Key Takeaways

- **Reusing previous results** is the heart of dynamic programming: each row is computed from the one before it.
- Initializing the row with `1`s removes the need for special handling of the first and last elements.
- Row `i` has `i + 1` elements, which makes the sizing of each row simple.
- Pascal's triangle values are **binomial coefficients** `C(n, k)`, which count the number of ways to choose `k` items from `n`.

### Related to Pascal's Triangle II

The follow-up problem asks for only one row using `O(rowIndex)` extra space. That version keeps a **single array** and updates it **in place from right to left**, instead of storing every row as this solution does.

---

## Related Problems

- Pascal's Triangle II (LeetCode 119)
- Triangle (LeetCode 120)
- Unique Paths (LeetCode 62)
- Climbing Stairs (LeetCode 70)