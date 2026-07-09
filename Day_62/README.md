# 303. Range Sum Query - Immutable

A C++ solution to [LeetCode 303](https://leetcode.com/problems/range-sum-query-immutable/) using the **Prefix Sum** technique.

## 📋 Problem

Given an integer array `nums`, handle multiple queries of the following type:

> Calculate the **sum of the elements** of `nums` between indices `left` and `right` **inclusive**, where `left <= right`.

You need to implement the `NumArray` class:

- `NumArray(int[] nums)` — Initializes the object with the integer array `nums`.
- `int sumRange(int left, int right)` — Returns the sum of the elements of `nums` between indices `left` and `right` **inclusive**.

### Example

```
Input:
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]

Output:
[null, 1, -1, -3]

Explanation:
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

## 💡 Approach: Prefix Sum

The naive approach — looping from `left` to `right` on every `sumRange` call — takes **O(n)** time *per query*. If `sumRange` is called many times, that adds up fast.

Instead, we precompute a **prefix sum array** once, up front. `prefixSum[i]` stores the sum of all elements *before* index `i`:

```
prefixSum[0] = 0
prefixSum[i] = nums[0] + nums[1] + ... + nums[i - 1]
```

Once we have this array, the sum of any range `[left, right]` is just a **subtraction**:

```
sumRange(left, right) = prefixSum[right + 1] - prefixSum[left]
```

That's it — no looping needed at query time. 🎉

### Why the extra `+1` size?

`prefixSum` is built with size `n + 1` (not `n`) so that `prefixSum[0] = 0` acts as a clean "empty sum" base case. This avoids messy edge-case checks when `left == 0`.

## 🧠 Code

```cpp
class NumArray {
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        // Allocate space for n + 1 elements, initialized to 0
        prefixSum.resize(n + 1, 0);

        // Build the prefix sum array
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // Difference of two prefix sums gives the sum of the range
        return prefixSum[right + 1] - prefixSum[left];
    }
};
```

## ⏱️ Complexity Analysis

| Operation                | Time Complexity | Space Complexity |
|---------------------------|:----------------:|:------------------:|
| `NumArray` (constructor)  | O(n)             | O(n)               |
| `sumRange` (per query)    | **O(1)**         | O(1)               |

- **n** = length of `nums`
- The one-time O(n) cost of building `prefixSum` pays off massively if `sumRange` is called repeatedly, since each query becomes constant time instead of linear.

## 🔑 Key Takeaway

Whenever you see a problem that asks for **repeated range-sum queries on an immutable array**, think **Prefix Sum** first. Precompute once, query in O(1) forever after.