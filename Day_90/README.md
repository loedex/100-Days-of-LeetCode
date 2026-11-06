<div align="center">

# Day 90: Maximum Product of Three Numbers

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-628-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Array%20%26%20Sorting-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

You are given an integer array `nums`.

Find three numbers whose product is **maximum** and return the maximum product.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `nums = [1,2,-3]` | `-6` | The only three numbers are `1`, `2` and `-3`, so the product is `1 * 2 * -3 = -6`. |
| 2 | `nums = [1,2,3,4]` | `24` | The largest product comes from the three greatest numbers: `2 * 3 * 4 = 24`. |
| 3 | `nums = [-1,-2,-3]` | `-6` | The only three numbers are `-1`, `-2` and `-3`, so the product is `-6`. |

### Constraints

- `3 <= nums.length <= 10^4`
- `-1000 <= nums[i] <= 1000`

---

## Intuition

At first glance, the answer looks simple: **multiply the three largest numbers**. That works when all numbers are positive, but negative numbers change the picture.

Remember the sign rule: **a negative times a negative is a positive**. So two very negative numbers can combine into a large positive value:

```text
[-10, -10, 1, 2, 3]

Three largest:        3 * 2 * 1         =   6
Two smallest + max:   (-10) * (-10) * 3 = 300   <-- larger!
```

This means the maximum product always comes from one of **two candidates**:

| Candidate | Formed by | Best when |
|:---------:|-----------|-----------|
| **Option 1** | The three **largest** numbers | The array is mostly positive. |
| **Option 2** | The two **smallest** numbers (most negative) and the **largest** number | The array has big negative numbers whose product becomes positive. |

Once the array is sorted, all these numbers sit at known positions: the largest at the end, the smallest at the start.

### Why only these two options?

The product of three numbers is large only if it is positive with large magnitudes (or, if every option is negative, the least negative). Consider the possible sign patterns:

- **Three positives:** use the three largest values (Option 1).
- **Two negatives and one positive:** the two negatives multiply to a positive, so use the two most negative values and the largest positive (Option 2).
- **All negatives:** the product is negative, so the best choice is the numbers closest to zero, which are the three largest values (Option 1).
- **One negative and two positives, or three negatives mixed in:** these never beat the options above.

So comparing Option 1 and Option 2 always covers the best answer.

---

## Approach

**Sort the array, then compare two candidate products.**

1. Sort `nums` in ascending order.
2. Compute **Option 1**: the product of the last three elements, `nums[n-1] * nums[n-2] * nums[n-3]`.
3. Compute **Option 2**: the product of the first two elements and the last element, `nums[0] * nums[1] * nums[n-1]`.
4. Return the **larger** of the two.

### Dry Run

**Example 2: `nums = [1,2,3,4]`**

| Step | Action | Value |
|:----:|--------|:-----:|
| 1 | Sorted array | `[1, 2, 3, 4]` |
| 2 | Option 1: `4 * 3 * 2` | `24` |
| 3 | Option 2: `1 * 2 * 4` | `8` |
| 4 | `max(24, 8)` | **`24`** |

**Example with negatives: `nums = [-10, -10, 1, 3, 2]`**

| Step | Action | Value |
|:----:|--------|:-----:|
| 1 | Sorted array | `[-10, -10, 1, 2, 3]` |
| 2 | Option 1: `3 * 2 * 1` | `6` |
| 3 | Option 2: `(-10) * (-10) * 3` | `300` |
| 4 | `max(6, 300)` | **`300`** |

**Example 3: `nums = [-1,-2,-3]`**

| Step | Action | Value |
|:----:|--------|:-----:|
| 1 | Sorted array | `[-3, -2, -1]` |
| 2 | Option 1: `(-1) * (-2) * (-3)` | `-6` |
| 3 | Option 2: `(-3) * (-2) * (-1)` | `-6` |
| 4 | `max(-6, -6)` | **`-6`** |

---

## Solution (C++)

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        // Option 1: Product of the three largest elements
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        // Option 2: Product of the two smallest (negative) elements and the largest element
        int option2 = nums[0] * nums[1] * nums[n - 1];
        
        return std::max(option1, option2);
    }
};
```

---

## Complexity Analysis

Let `n` be the length of `nums`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n log n)` | Sorting dominates the running time. The two product calculations take constant time. |
| **Space** | `O(log n)` | Auxiliary stack space used by the sorting algorithm. The input array is sorted in place. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Exactly 3 elements | Both options use the same three numbers, so either gives the correct answer. |
| All positive numbers | Option 1 wins. |
| All negative numbers | Option 1 gives the least negative product, which is the maximum. |
| Two large negatives and a positive | Option 2 wins, because two negatives make a positive. |
| Array contains zeros | Handled naturally. A zero only matters if every other choice is worse. |
| Integer overflow | The largest possible product is `1000 * 1000 * 1000 = 10^9`, which fits safely in a 32-bit `int` (maximum about `2.1 * 10^9`). |

---

## Key Takeaways

- **Negative numbers can change the answer.** Always consider the case where two negatives multiply into a positive.
- After sorting, the best candidates sit at **both ends** of the array: the three largest at the end, and the two smallest at the start.
- Checking constraints (`|nums[i]| <= 1000`) confirms that `int` is large enough and no `long long` is needed.
- Note that `std::sort` **modifies the input array** in place.

### Alternative Approach

Sorting is not strictly necessary. A **single pass** can track the **three largest** values and the **two smallest** values while scanning the array, then compare the same two candidates. This reduces the time complexity to `O(n)` with `O(1)` extra space, at the cost of slightly more code.

| Approach | Time | Space |
|----------|:----:|:-----:|
| **Sorting (this solution)** | `O(n log n)` | `O(log n)` |
| **Single pass** | `O(n)` | `O(1)` |

---

## Related Problems

- Maximum Product Subarray (LeetCode 152)
- Third Maximum Number (LeetCode 414)
- Maximum Product of Two Elements in an Array (LeetCode 1464)
- Largest Perimeter Triangle (LeetCode 976)