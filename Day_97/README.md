<div align="center">

# Day XX: 3Sum Closest

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-16-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Two%20Pointers-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given an integer array `nums` of length `n` and an integer `target`, find **three integers** in `nums` such that their sum is **closest** to `target`.

Return the **sum** of the three integers.

You may assume that each input would have **exactly one solution**.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `nums = [-1,2,1,-4]`, `target = 1` | `2` | The sum closest to `1` is `2`, from `-1 + 2 + 1`. |
| 2 | `nums = [0,0,0]`, `target = 1` | `0` | The only possible sum is `0 + 0 + 0 = 0`. |

### Constraints

- `3 <= nums.length <= 500`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`

---

## Intuition

The direct approach is to try every group of three numbers with three nested loops:

```text
n * n * n  =  O(n^3)  combinations
```

For `n = 500`, that is more than 20 million triplets. It works, but there is a much smarter way.

The key is to **sort the array first**. Once the numbers are in order, we can fix one number and use **two pointers** (one at each end of the remaining part) to search for the best pair. The pointers tell us which way to move:

| Situation | What it means | Action |
|-----------|---------------|--------|
| `currentSum < target` | The sum is too small | Move `left` right to get a **larger** value |
| `currentSum > target` | The sum is too large | Move `right` left to get a **smaller** value |
| `currentSum == target` | Perfect match | Return immediately, nothing can be closer |

Sorting is what makes this decision possible. In a sorted array, moving `left` forward can only keep the value the same or increase it, and moving `right` backward can only keep it the same or decrease it.

---

## Approach

**Sort, then fix one number and sweep the rest with two pointers.**

1. **Sort** `nums` in ascending order.
2. Initialize `closestSum` with the sum of the first three numbers. This gives us a valid starting answer to compare against.
3. For each index `i` from `0` to `n - 3`:
   - Set `left = i + 1` and `right = n - 1`.
   - While `left < right`:
     - Compute `currentSum = nums[i] + nums[left] + nums[right]`.
     - If `currentSum` is **closer** to `target` than `closestSum` (compare absolute differences), update `closestSum`.
     - If `currentSum < target`, move `left` forward.
     - If `currentSum > target`, move `right` backward.
     - If `currentSum == target`, return it immediately.
4. Return `closestSum`.

### Why compare with `abs(sum - target)`?

"Closest" means the smallest **distance** to the target, regardless of whether the sum is above or below it. The absolute difference measures exactly that distance.

### Why is it safe to return early on an exact match?

The smallest possible distance is `0`. If a sum equals `target`, no other sum can be closer, so we can stop right away.

### Dry Run

**Example 1: `nums = [-1,2,1,-4]`, `target = 1`**

After sorting: `[-4, -1, 1, 2]`. Initial `closestSum = -4 + -1 + 1 = -4`, with distance `|-4 - 1| = 5`.

| `i` | `left` | `right` | Triplet | `currentSum` | Distance | Better? | `closestSum` | Pointer move |
|:---:|:------:|:-------:|---------|:------------:|:--------:|:-------:|:------------:|--------------|
| 0 | 1 | 3 | `-4, -1, 2` | -3 | 4 | Yes (4 < 5) | -3 | sum < target, `left++` |
| 0 | 2 | 3 | `-4, 1, 2` | -1 | 2 | Yes (2 < 4) | -1 | sum < target, `left++` |
| 1 | 2 | 3 | `-1, 1, 2` | 2 | 1 | Yes (1 < 2) | 2 | sum > target, `right--` |

For `i = 0`, the pointers meet after the second step. For `i = 1`, they meet after the third. The loop over `i` ends because `i < n - 2 = 2`.

**Result: `2`**

---

## Solution (C++)

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};
```

---

## Complexity Analysis

Let `n` be the length of `nums`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n^2)` | Sorting costs `O(n log n)`. The outer loop runs `n` times, and each two-pointer sweep takes `O(n)`, giving `O(n^2)` in total, which dominates. |
| **Space** | `O(log n)` | Only a few variables are used. The `O(log n)` comes from the stack space of the sort. The input array is sorted in place. |

**Comparison with brute force:**

| Approach | Time | Operations for `n = 500` |
|----------|:----:|:------------------------:|
| Three nested loops | `O(n^3)` | About 20,000,000 |
| **Sort and two pointers (this solution)** | `O(n^2)` | About 250,000 |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Exactly 3 elements | `closestSum` starts as their sum and the loop confirms it, so that sum is returned. |
| Exact match exists | Returned immediately, since no sum can be closer. |
| Duplicate values | Handled naturally. We return a **sum**, not the triplets, so there is no need to skip duplicates. |
| All negative or all positive numbers | The two-pointer movement still finds the sum nearest to `target`. |
| Target far from any possible sum | The result is simply the smallest or largest achievable sum. |
| Integer overflow | The largest possible sum is `3 * 1000 = 3000`, and differences stay below about `13,000`, so `int` is safe. |

---

## Key Takeaways

- **Sorting enables two pointers.** Once the data is ordered, each comparison tells us exactly which pointer to move.
- Fixing one element reduces the 3-number problem to a **2-number** problem (the classic Two Sum II pattern).
- **Initialize the answer with a real candidate** (the first three numbers), not with a placeholder such as `INT_MAX`, to avoid overflow in the difference calculation.
- This approach is the same backbone as 3Sum and 4Sum. Only the target comparison changes.

### Alternative Approach

A small optimization is to **skip duplicate values** of `nums[i]` (for example `if (i > 0 && nums[i] == nums[i - 1]) continue;`). It avoids repeating identical work, but it is optional here because the problem asks for a single sum and not for unique triplets.

---

## Related Problems

- 3Sum (LeetCode 15)
- 3Sum Smaller (LeetCode 259)
- 4Sum (LeetCode 18)
- Two Sum II: Input Array Is Sorted (LeetCode 167)
- Valid Triangle Number (LeetCode 611)