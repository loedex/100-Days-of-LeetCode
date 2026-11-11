<div align="center">

# Day 93: Pascal's Triangle II

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-119-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Dynamic%20Programming-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given an integer `rowIndex`, return the `rowIndex`-th (**0-indexed**) row of Pascal's triangle.

In Pascal's triangle, each number is the **sum of the two numbers directly above it**:

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
| 1 | `rowIndex = 3` | `[1,3,3,1]` |
| 2 | `rowIndex = 0` | `[1]` |
| 3 | `rowIndex = 1` | `[1,1]` |

### Constraints

- `0 <= rowIndex <= 33`

### Follow-up

Could you optimize your algorithm to use only `O(rowIndex)` extra space?

---

## Intuition

Each number in a row is built from the row above it:

```text
row[i][j] = row[i-1][j-1] + row[i-1][j]
```

The simple way is to build the whole triangle and return the last row, but that stores every row and uses `O(rowIndex^2)` space.

Notice that to build the next row, we only need the **previous row**. Better still, we can reuse a **single array** and update it **in place**, turning the previous row into the next one. This satisfies the follow-up and needs only `O(rowIndex)` space.

---

## Approach

**Update a single array in place, working from right to left.**

1. Create an array `row` of size `rowIndex + 1`, filled with `0`.
2. Set `row[0] = 1`. Row 0 is `[1]`, and the first element of every row is always `1`.
3. For each row `i` from `1` to `rowIndex`:
   - Loop `j` **backwards** from `i` down to `1`.
   - Update `row[j] += row[j - 1]`.
4. Return `row`.

The last element of every row is `1`. This happens automatically: when `j = i`, `row[i]` starts as `0`, so `row[i] += row[i-1]` copies the previous last element, which is `1`.

### Why traverse backwards?

Each update `row[j] += row[j - 1]` needs the **old** value of `row[j - 1]` (from the previous row). If we went left to right, `row[j - 1]` would already have been overwritten with its **new** value before we use it, giving wrong results.

Going right to left guarantees that `row[j - 1]` has not been touched yet when we need it.

**What goes wrong going forwards?** Take row 2, starting from `[1, 1, 0]`:

| Direction | Steps | Result | Correct? |
|-----------|-------|:------:|:--------:|
| Forward (left to right) | `row[1] = 1 + 1 = 2`, then `row[2] = 0 + 2 = 2` (uses the **new** `row[1]`) | `[1, 2, 2]` | No |
| Backward (right to left) | `row[2] = 0 + 1 = 1`, then `row[1] = 1 + 1 = 2` | `[1, 2, 1]` | Yes |

### Dry Run

**Example 1: `rowIndex = 3`**

Start: `row = [1, 0, 0, 0]`

| Row `i` | `j` | Operation | `row` after |
|:-------:|:---:|-----------|:-----------:|
| 1 | 1 | `row[1] += row[0]` | `[1, 1, 0, 0]` |
| 2 | 2 | `row[2] += row[1]` | `[1, 1, 1, 0]` |
| 2 | 1 | `row[1] += row[0]` | `[1, 2, 1, 0]` |
| 3 | 3 | `row[3] += row[2]` | `[1, 2, 1, 1]` |
| 3 | 2 | `row[2] += row[1]` | `[1, 2, 3, 1]` |
| 3 | 1 | `row[1] += row[0]` | `[1, 3, 3, 1]` |

**Result: `[1, 3, 3, 1]`**

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
       std::vector<int> row(rowIndex + 1, 0);
        row[0] = 1; // The 0th element is always 1

        for (int i = 1; i <= rowIndex; ++i) {
            // Traverse backwards to update in-place without losing previous values
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }

        return row; 
    }
};
```

---

## Complexity Analysis

Let `k = rowIndex`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(k^2)` | The nested loops perform `1 + 2 + ... + k` updates, which is about `k^2 / 2`. |
| **Space** | `O(k)` | A single array of size `k + 1`, which is the output itself. No extra rows are stored. This meets the follow-up requirement. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `rowIndex = 0` | The array is `[1]`. The outer loop never runs, so `[1]` is returned. |
| `rowIndex = 1` | One update gives `[1, 1]`. |
| Largest input `rowIndex = 33` | The largest value in that row is `C(33, 16) = 1,166,803,110`, which is below the `int` limit of `2,147,483,647`. No overflow occurs. |
| Symmetry | Every row reads the same forwards and backwards, which makes a handy sanity check. |

---

## Key Takeaways

- **Rolling array / in-place DP:** when a row depends only on the previous row, one array is enough.
- **Iteration direction matters.** Going backwards protects values you still need.
- The constraint `rowIndex <= 33` is chosen so that every value fits in a 32-bit `int`.
- Pascal's triangle values are the **binomial coefficients** `C(n, k)`, which count the ways to choose `k` items from `n`.

### Alternative Approach

Each element can also be computed directly from the previous one in the same row using the binomial coefficient formula:

```text
C(n, k) = C(n, k - 1) * (n - k + 1) / k
```

This builds the row in `O(k)` time with `O(1)` extra space. A `long long` is needed for the intermediate multiplication to avoid overflow.

| Approach | Time | Space |
|----------|:----:|:-----:|
| **Full triangle** | `O(k^2)` | `O(k^2)` |
| **In-place rolling array (this solution)** | `O(k^2)` | `O(k)` |
| **Binomial formula** | `O(k)` | `O(k)` for the output |

---

## Related Problems

- Pascal's Triangle (LeetCode 118)
- Triangle (LeetCode 120)
- Unique Paths (LeetCode 62)
- Climbing Stairs (LeetCode 70)