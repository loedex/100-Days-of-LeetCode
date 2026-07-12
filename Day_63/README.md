# LeetCode 15 — 3Sum

A C++ solution to [LeetCode 15: 3Sum](https://leetcode.com/problems/3sum/), using **sorting + two pointers** to find all unique triplets that sum to zero.

## Problem

Given an integer array `nums`, return all unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

**Example**

```
Input:  nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

## Approach

1. **Sort the array first.** Sorting makes it possible to use two pointers efficiently and makes duplicate values sit next to each other, which is key for skipping duplicates.
2. **Fix one number** (`nums[i]`) with a loop, and search for the other two using a **two-pointer** scan on the rest of the array:
   - `left` starts right after `i`.
   - `right` starts at the end of the array.
3. **Move the pointers based on the sum:**
   - If `nums[i] + nums[left] + nums[right] == 0` → found a triplet! Record it, then move both pointers inward.
   - If the sum is **less than 0** → move `left` right (we need a bigger number).
   - If the sum is **greater than 0** → move `right` left (we need a smaller number).
4. **Skip duplicates** at every level (`i`, `left`, and `right`) so the same triplet isn't added more than once.
5. **Early exit:** once `nums[i] > 0`, no triplet starting from here can sum to zero (since the array is sorted and everything after is also positive), so we `break` out of the loop entirely.

## Complexity

| | Complexity |
|---|---|
| Time | `O(n²)` — one loop for `i`, nested two-pointer scan for `left`/`right` |
| Space | `O(1)` extra (excluding the output array); sort is typically `O(log n)` |

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};
```

## Why the duplicate-skipping matters

Without the duplicate checks, an input like `[-1, -1, 0, 1, 1]` would produce the same triplet `[-1, 0, 1]` multiple times. The three duplicate-skip lines (`i > 0 && nums[i] == nums[i-1]`, and the two `while` loops for `left`/`right`) make sure each unique triplet is only added **once**.