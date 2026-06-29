# 908. Smallest Range I

![LeetCode](https://img.shields.io/badge/LeetCode-908-orange?style=flat-square&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Math-purple?style=flat-square)

---

## 📌 Problem Statement

Given an integer array `nums` and an integer `k`, in one move you may choose **any index** `i` in `nums` and replace `nums[i]` with any value in the range `[nums[i] - k, nums[i] + k]`.

The **score** of `nums` is the difference between the maximum and minimum elements in `nums`.

Return the **minimum score** after applying **at most one such move** to each element.

> 🔗 [View on LeetCode](https://leetcode.com/problems/smallest-range-i/)

---

## 🧪 Examples

**Example 1**
```
Input:  nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
```

**Example 2**
```
Input:  nums = [0, 10], k = 2
Output: 6
Explanation: Increase nums[0] by 2 → 2, decrease nums[1] by 2 → 8. Score = 8 - 2 = 6.
```

**Example 3**
```
Input:  nums = [1, 3, 6], k = 3
Output: 0
Explanation: Increase nums[0] to 4, keep nums[1] at 3, decrease nums[2] to 3. Score = 4 - 3 = 0 (or less).
```

---

## 💡 Intuition & Approach

The key insight is:

- To **minimize** the score, we want to **raise the minimum** as high as possible and **lower the maximum** as low as possible.
- The best we can do is raise `min_val` by `k` → `min_val + k`
- And lower `max_val` by `k` → `max_val - k`
- So the minimized score becomes: `(max_val - k) - (min_val + k)` = `max_val - min_val - 2k`

If this value is **negative or zero**, it means the ranges overlap and we can achieve a score of `0`.

```
Minimized Score = max(0, max_val - min_val - 2 * k)
```

We only need the **global minimum** and **global maximum** — no sorting, no extra passes.

---

## ✅ Solution

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestRangeI(std::vector<int>& nums, int k) {
        // Find the minimum and maximum elements in a single pass
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        
        // Calculate the minimized difference
        int potential_score = max_val - min_val - 2 * k;
        
        // If the score is negative or zero, it means we can make the difference 0
        return std::max(0, potential_score);
    }
};
```

---

## 📊 Complexity Analysis

| | Complexity | Reason |
|---|---|---|
| **Time** | `O(n)` | Single pass via `std::minmax_element` |
| **Space** | `O(1)` | Only two variables stored, no extra memory |

---

## 🔍 Key C++ Details

| Feature | Usage |
|---|---|
| `std::minmax_element` | Returns iterators to both min and max in one pass |
| Structured bindings `auto [a, b]` | C++17 feature for clean unpacking of pairs |
| `std::max(0, x)` | Clamps the result to a minimum of `0` |

---

## 🏷️ Tags

`Array` · `Math` · `C++17` · `Greedy`

---

## 📁 Repository Structure

```
908-smallest-range-i/
├── README.md
└── solution.cpp
```