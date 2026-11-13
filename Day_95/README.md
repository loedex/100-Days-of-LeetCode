<div align="center">

# Day 95: 4Sum II

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-454-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Hash%20Table-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given four integer arrays `nums1`, `nums2`, `nums3`, and `nums4`, all of length `n`, return the number of tuples `(i, j, k, l)` such that:

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

### Examples

| Example | Input | Output |
|:-------:|-------|:------:|
| 1 | `nums1 = [1,2]`, `nums2 = [-2,-1]`, `nums3 = [-1,2]`, `nums4 = [0,2]` | `2` |
| 2 | `nums1 = [0]`, `nums2 = [0]`, `nums3 = [0]`, `nums4 = [0]` | `1` |

**Example 1 explanation:** the two tuples are:

1. `(0, 0, 0, 1)`: `1 + (-2) + (-1) + 2 = 0`
2. `(1, 1, 0, 0)`: `2 + (-1) + (-1) + 0 = 0`

### Constraints

- `n == nums1.length == nums2.length == nums3.length == nums4.length`
- `1 <= n <= 200`
- `-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28`

---

## Intuition

The most direct idea is four nested loops that try every combination of `(i, j, k, l)`:

```text
n * n * n * n  =  n^4  combinations
```

With `n = 200`, that is `200^4 = 1.6 billion` checks, which is far too slow.

The trick is to **split the problem in half** (a technique often called *meet in the middle*). Rewrite the condition:

```text
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
        ==>  nums1[i] + nums2[j]  ==  -(nums3[k] + nums4[l])
```

Now there are two independent halves:

- **Left half:** every sum `a + b` from `nums1` and `nums2`.
- **Right half:** every sum `c + d` from `nums3` and `nums4`.

We need to count how many pairs of (left sum, right sum) add up to zero. If we **remember** every left sum in a hash map, then for each right sum we can look up its opposite in constant time, instead of searching again.

This reduces the work from `O(n^4)` to `O(n^2)`.

---

## Approach

**Store pair-sum frequencies in a hash map, then look up complements.**

**Step 1: Count all sums from `nums1` and `nums2`**

For every pair `(a, b)`, increase the count of `a + b` in an `unordered_map<int, int>`. The map stores `sum -> how many pairs produce this sum`.

**Step 2: Look up complements from `nums3` and `nums4`**

For every pair `(c, d)`, compute `target = -(c + d)`. If `target` exists in the map, then every pair that produced it forms a valid tuple with `(c, d)`, so add its stored **frequency** to the answer.

**Step 3: Return the total**

### Why store frequencies and not just "seen or not seen"?

The problem counts **tuples**, so several different pairs `(i, j)` can produce the same sum, and each one forms a separate valid tuple. For example, if the sum `0` appears twice in the left half, then every matching right-half pair contributes **2** to the answer, not 1.

### Dry Run

**Example 1:** `nums1 = [1,2]`, `nums2 = [-2,-1]`, `nums3 = [-1,2]`, `nums4 = [0,2]`

**Step 1: Build the map from `nums1` and `nums2`**

| `a` | `b` | `a + b` |
|:---:|:---:|:-------:|
| 1 | -2 | -1 |
| 1 | -1 | 0 |
| 2 | -2 | 0 |
| 2 | -1 | 1 |

Resulting map: `{ -1: 1, 0: 2, 1: 1 }`

**Step 2: Check complements from `nums3` and `nums4`**

| `c` | `d` | `c + d` | `target = -(c + d)` | In map? | Added | `totalTuples` |
|:---:|:---:|:-------:|:-------------------:|:-------:|:-----:|:-------------:|
| -1 | 0 | -1 | 1 | Yes (count 1) | +1 | 1 |
| -1 | 2 | 1 | -1 | Yes (count 1) | +1 | 2 |
| 2 | 0 | 2 | -2 | No | 0 | 2 |
| 2 | 2 | 4 | -4 | No | 0 | 2 |

**Result: `2`**

---

## Solution (C++)

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       std::unordered_map<int, int> sumCount;
        
        // Step 1: Store frequencies of sums from nums1 and nums2
        for (int a : nums1) {
            for (int b : nums2) {
                sumCount[a + b]++;
            }
        }
        
        int totalTuples = 0;
        
        // Step 2: Check complements from nums3 and nums4
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                auto it = sumCount.find(target);
                if (it != sumCount.end()) {
                    totalTuples += it->second;
                }
            }
        }
        
        return totalTuples; 
    }
};
```

---

## Complexity Analysis

Let `n` be the length of each array.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n^2)` | Two double loops of `n^2` iterations each, with `O(1)` average hash map operations. |
| **Space** | `O(n^2)` | The map can hold up to `n^2` distinct sums (at most 40,000 entries when `n = 200`). |

**Comparison with brute force:**

| Approach | Time | Operations for `n = 200` |
|----------|:----:|:------------------------:|
| Four nested loops | `O(n^4)` | About 1,600,000,000 |
| **Hash map, meet in the middle (this solution)** | `O(n^2)` | About 80,000 |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `n = 1` | A single tuple exists, and the answer is `1` only if the four values sum to `0`. |
| All zeros (Example 2) | The map holds `{0: 1}`, and the lookup for `0` succeeds, giving `1`. |
| Many pairs with the same sum | Handled by storing **frequencies**, so each duplicate sum counts separately. |
| No valid tuples | No complement is ever found, so the answer is `0`. |
| Integer overflow in sums | Each value is at most `2^28` in magnitude, so a pair sum is at most `2^29`, which fits in `int`. |
| Overflow in the answer | The maximum possible count is `200^4 = 1.6 * 10^9`, which is below the `int` limit of about `2.147 * 10^9`. |

---

## Key Takeaways

- **Meet in the middle:** splitting a four-way problem into two two-way halves turns `O(n^4)` into `O(n^2)`.
- A **hash map of frequencies** answers the question "how many earlier items match this one?" in constant time.
- When counting *combinations of indices*, store **how many times** a value occurs, not just whether it occurs.
- Always check the constraints for overflow. Here, the bounds `2^28` and `n <= 200` are chosen so that plain `int` is safe.
- The same "store one half, look up the other" idea powers Two Sum and many related problems.

### Alternative Approach

Another option is to build two sorted arrays of all pair sums (`nums1 + nums2` and `nums3 + nums4`) and use a **two-pointer sweep**, counting equal runs. This takes `O(n^2 log n)` time because of the sorting, and avoids hashing, but the hash map solution is simpler and faster on average.

---

## Related Problems

- Two Sum (LeetCode 1)
- 3Sum (LeetCode 15)
- 4Sum (LeetCode 18)
- Subarray Sum Equals K (LeetCode 560)
- Number of Good Pairs (LeetCode 1512)