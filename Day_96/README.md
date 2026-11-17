<div align="center">

# Day XX: Summary Ranges

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-228-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Array-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Runtime](https://img.shields.io/badge/Runtime-0%20ms%20(100%25)-brightgreen?style=for-the-badge)

</div>

---

## Problem Statement

You are given a **sorted unique** integer array `nums`.

A **range** `[a, b]` is the set of all integers from `a` to `b` (inclusive).

Return the **smallest sorted list of ranges** that cover all the numbers in the array exactly. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` that is in one of the ranges but not in `nums`.

Each range `[a, b]` in the list should be output as:

- `"a->b"` if `a != b`
- `"a"` if `a == b`

### Examples

| Example | Input | Output |
|:-------:|-------|--------|
| 1 | `nums = [0,1,2,4,5,7]` | `["0->2","4->5","7"]` |
| 2 | `nums = [0,2,3,4,6,8,9]` | `["0","2->4","6","8->9"]` |

**Example 1 explanation:** the ranges are `[0,2] -> "0->2"`, `[4,5] -> "4->5"` and `[7,7] -> "7"`.

### Constraints

- `0 <= nums.length <= 20`
- `-2^31 <= nums[i] <= 2^31 - 1`
- All the values of `nums` are **unique**.
- `nums` is sorted in **ascending** order.

---

## Intuition

Because the array is **sorted and has no duplicates**, consecutive numbers sit right next to each other. A run such as `4, 5, 6` appears as a block, and a **gap** (the next number is not exactly one more than the current number) marks the end of a block.

So the problem becomes:

> Walk through the array once. Remember where the current block started. Whenever the block ends, write it down and start a new one.

A block ends at index `i` when either:

1. `i` is the **last element**, or
2. `nums[i] + 1 != nums[i + 1]` (there is a gap after `nums[i]`).

When the block ends, there are two cases for the output string:

- The block has a single number (`start == nums[i]`), so output just `"start"`.
- The block has several numbers, so output `"start->nums[i]"`.

---

## Approach

**One pass with a `start` marker.**

1. If the array is empty, return an empty list.
2. Set `start = nums[0]`.
3. For each index `i` from `0` to `n - 1`:
   - Check whether the block ends here: `i == n - 1` **or** `nums[i] + 1 != nums[i + 1]`.
   - If it ends:
     - If `start == nums[i]`, add `"start"` to the result.
     - Otherwise, add `"start->nums[i]"`.
     - If there is a next element, set `start = nums[i + 1]` to begin the next block.
4. Return the result.

### Why `long long`?

The values can be as large as `2^31 - 1` and as small as `-2^31`, the full range of a 32-bit `int`. Comparing neighbors with a subtraction such as `nums[i + 1] - nums[i]` could overflow for extreme pairs like `-2^31` and `2^31 - 1`. Casting to `long long` before adding makes the comparison safe, and `std::to_string` works directly on a `long long` as well.

In this solution the check `i == n - 1 ||` also protects the last element thanks to short-circuit evaluation. The `long long` cast is an extra safety layer, and it is a good habit whenever input values touch the limits of `int`.

### Dry Run

**Example 1: `nums = [0,1,2,4,5,7]`**, starting with `start = 0`

| `i` | `nums[i]` | Block ends? | Reason | Action | `start` after |
|:---:|:---------:|:-----------:|--------|--------|:-------------:|
| 0 | 0 | No | `0 + 1 == 1` | continue | 0 |
| 1 | 1 | No | `1 + 1 == 2` | continue | 0 |
| 2 | 2 | **Yes** | `2 + 1 = 3 != 4` | `start != 2`, so add `"0->2"` | 4 |
| 3 | 4 | No | `4 + 1 == 5` | continue | 4 |
| 4 | 5 | **Yes** | `5 + 1 = 6 != 7` | `start != 5`, so add `"4->5"` | 7 |
| 5 | 7 | **Yes** | last element | `start == 7`, so add `"7"` | 7 |

**Result: `["0->2", "4->5", "7"]`**

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> res;
        int n = nums.size();
        if (n == 0) return res;
        
        long long start = nums[0];
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || (long long)nums[i] + 1 != nums[i + 1]) {
                if (start == nums[i]) {
                    res.push_back(std::to_string(start));
                } else {
                    res.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));
                }
                if (i + 1 < n) {
                    start = nums[i + 1];
                }
            }
        }
        return res;
    }
};
```

---

## Complexity Analysis

Let `n` be the length of `nums`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n)` | The array is scanned exactly once. |
| **Space** | `O(1)` | Only a few variables are used, not counting the output list. |

---

## Submission Result

| Metric | Result |
|--------|--------|
| **Status** | Accepted |
| **Runtime** | 0 ms, beats 100.00% of C++ submissions |
| **Memory** | 9.17 MB, beats 63.88% of C++ submissions |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Empty array | Returns an empty list immediately. |
| Single element (e.g. `[5]`) | The block ends at `i == n - 1` with `start == nums[0]`, giving `["5"]`. |
| All numbers consecutive (e.g. `[1,2,3,4]`) | One block, giving `["1->4"]`. |
| No consecutive numbers (e.g. `[1,3,5]`) | Every element is its own block, giving `["1","3","5"]`. |
| Negative numbers | Handled the same way; `std::to_string` prints the minus sign. |
| Extreme values (`-2^31` and `2^31 - 1`) | The `long long` cast prevents overflow in the comparison. |

---

## Key Takeaways

- A **sorted, duplicate-free** array turns "find groups of consecutive numbers" into a simple single scan.
- Tracking a `start` marker and closing a block when a **gap** appears is a reusable pattern for interval and grouping problems.
- Checking `i == n - 1` **first** avoids reading `nums[i + 1]` out of bounds.
- Always think about **overflow** when inputs reach the limits of `int`; widening to `long long` is a cheap and safe fix.

---

## Related Problems

- Missing Ranges (LeetCode 163)
- Merge Intervals (LeetCode 56)
- Insert Interval (LeetCode 57)
- Data Stream as Disjoint Intervals (LeetCode 352)
- Longest Consecutive Sequence (LeetCode 128)