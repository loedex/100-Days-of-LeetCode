# 🟨 LeetCode 1252 — Cells with Odd Values in a Matrix

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)
![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Math%20%7C%20Simulation-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=flat-square)

---

## 📋 Problem Statement

> **Source:** [LeetCode 1252](https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/)

There is an `m × n` matrix initialized with all `0`s. You are also given an array `indices` where each `indices[i] = [rᵢ, cᵢ]` represents an operation that:

- Increments **all** elements in **row** `rᵢ` by `1`
- Increments **all** elements in **column** `cᵢ` by `1`

Return the **number of cells** with **odd values** in the matrix after applying **all** the operations.

### Example

```
Input:  m = 2, n = 3, indices = [[0,1],[1,1]]
Output: 6

Matrix after all operations:
  [1, 3, 1]
  [1, 3, 1]
  ─────────
  Odd cells: 6
```

### Constraints

| Parameter    | Constraint              |
|--------------|-------------------------|
| `m`          | `1 ≤ m ≤ 50`            |
| `n`          | `1 ≤ n ≤ 50`            |
| `indices`    | `1 ≤ indices.length ≤ 100` |
| `indices[i]` | `0 ≤ rᵢ < m`, `0 ≤ cᵢ < n` |

---

## 💡 Intuition

Instead of simulating the full matrix (which would be expensive), notice that the final value of any cell `(i, j)` is simply:

```
cell(i, j) = rowCounts[i] + colCounts[j]
```

A cell is **odd** when this sum is odd — meaning **exactly one** of `rowCounts[i]` or `colCounts[j]` is odd (not both, not neither).

This allows us to count odd cells mathematically without ever building the matrix.

---

## 🚀 Approach — Frequency Counting (Optimized)

### Algorithm Walkthrough

**Step 1 — Build frequency arrays**

Count how many times each row and column is incremented.

```
indices = [[0,1],[1,1]]

rowCounts = [1, 1]    ← row 0 hit once, row 1 hit once
colCounts = [0, 2, 0] ← col 1 hit twice
```

**Step 2 — Count odd rows and columns**

```
oddRows = 2  (both row 0 and row 1 have count = 1, which is odd)
oddCols = 0  (col 1 has count = 2, which is even)
```

**Step 3 — Apply the counting formula**

A cell `(i, j)` is odd when exactly one of its row/col count is odd:

```
oddCells = (oddRows × evenCols) + (evenRows × oddCols)
         = (oddRows × (n - oddCols)) + ((m - oddRows) × oddCols)
         = (2 × 3) + (0 × 0)
         = 6 ✅
```

---

## 🧑‍💻 Solution

```cpp
#include <vector>

class Solution {
public:
    int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
        // Track the count of increments for each row and column
        std::vector<int> rowCounts(m, 0);
        std::vector<int> colCounts(n, 0);

        // Populate the frequency arrays
        for (const auto& index : indices) {
            rowCounts[index[0]]++;
            colCounts[index[1]]++;
        }

        // Count how many rows and columns have an odd number of increments
        int oddRows = 0;
        for (int i = 0; i < m; ++i) {
            if (rowCounts[i] % 2 != 0) {
                oddRows++;
            }
        }

        int oddCols = 0;
        for (int j = 0; j < n; ++j) {
            if (colCounts[j] % 2 != 0) {
                oddCols++;
            }
        }

        // Apply the counting formula
        return (oddRows * (n - oddCols)) + ((m - oddRows) * oddCols);
    }
};
```

---

## 📊 Complexity Analysis

| Metric           | Value                              | Explanation                                           |
|------------------|------------------------------------|-------------------------------------------------------|
| **Time**         | `O(k + m + n)`                     | `k` = length of `indices`; one pass each over m and n |
| **Space**        | `O(m + n)`                         | Two auxiliary frequency arrays                        |

> **Versus Brute Force** `O(k × (m + n))` time and `O(m × n)` space — this approach avoids building the full matrix entirely.

---

## 🧪 Test Cases

| m | n | indices                  | Expected Output |
|---|---|--------------------------|-----------------|
| 2 | 3 | `[[0,1],[1,1]]`          | `6`             |
| 2 | 2 | `[[1,1],[0,0]]`          | `0`             |
| 1 | 1 | `[[0,0]]`                | `1`             |
| 3 | 3 | `[[0,0],[1,1],[2,2]]`    | `3`             |

---

## 📁 Project Structure

```
leetcode-1252/
├── README.md          ← You are here
└── solution.cpp       ← C++ solution
```

---

## 🔗 Related Problems

| # | Title | Difficulty |
|---|-------|------------|
| 1094 | Car Pooling | Medium |
| 1109 | Corporate Flight Bookings | Medium |
| 598  | Range Addition II | Easy |

---

*Solved with ❤️ in C++*