# 18. 4Sum

**Difficulty:** Medium
**Topics:** Array, Two Pointers, Sorting
**LeetCode Link:** [https://leetcode.com/problems/4sum/](https://leetcode.com/problems/4sum/)

## Problem Statement

Given an array `nums` of `n` integers and an integer `target`, return **all unique quadruplets**
`[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are **distinct**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

### Example 1

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

### Example 2

```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```

### Constraints

- `1 <= nums.length <= 200`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

## Approach

This solution extends the classic **two-pointer technique** used in 3Sum to a 4th dimension:

1. **Sort** the array — this enables two-pointer scanning and easy duplicate skipping.
2. **Fix the first two numbers** with nested loops (`i` and `j`).
3. For the remaining two numbers, use **two pointers** (`left` and `right`) that move
   toward each other based on whether the current sum is less than, greater than, or
   equal to the target.
4. **Skip duplicates** at every level (`i`, `j`, `left`, `right`) to ensure only unique
   quadruplets are added to the result.
5. **Prune early** using the sorted order:
   - If the smallest possible sum for the current `i` (or `i, j`) already exceeds the
     target, no further progress is possible — `break`.
   - If the largest possible sum for the current `i` (or `i, j`) is still less than the
     target, the current choice is too small — `continue`.

Pruning keeps the algorithm fast in practice by skipping large chunks of the search space
that can't possibly contain a valid answer.

> **Note:** Sums are computed using `long long` to avoid integer overflow, since
> `nums[i]` can be as large as `10^9` and we're summing four of them.

## Complexity

| Metric | Complexity |
|--------|------------|
| Time   | O(n³)      |
| Space  | O(1) (excluding the output array) |

The two outer loops (`i`, `j`) give O(n²), and the two-pointer scan for each pair gives
an additional O(n), resulting in O(n³) overall. Sorting takes O(n log n), which is
dominated by the O(n³) search.

## Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        if (n < 4) return ans;

        // Step 1: Sort the array to use two-pointer technique
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Pruning: smallest possible sum with current nums[i] exceeds target
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // Pruning: largest possible sum with current nums[i] is smaller than target
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Avoid duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Sub-pruning for second loop
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long curr_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (curr_sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (curr_sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
```

## How to Run

1. Save the code above as `Solution.cpp` (or add it to your LeetCode C++ workspace).
2. Compile with a C++11 or later compiler:
   ```bash
   g++ -std=c++17 -o solution Solution.cpp
   ```
3. Or paste it directly into the [LeetCode editor](https://leetcode.com/problems/4sum/) and hit **Submit**.