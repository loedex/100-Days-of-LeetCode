# 697. Degree of an Array

A clean C++ solution to [LeetCode 697 - Degree of an Array](https://leetcode.com/problems/degree-of-an-array/), using a single-pass hash map approach.

## 📋 Problem Statement

Given a non-empty array of non-negative integers `nums`, the **degree** of the array is defined as the maximum frequency of any one of its elements.

Your task is to find the **smallest possible length** of a contiguous subarray of `nums` that has the **same degree** as `nums`.

### Example 1

```
Input:  nums = [1, 2, 2, 3, 1]
Output: 2
Explanation: The degree is 2 (both 1 and 2 appear twice).
             Subarrays with degree 2: [2, 2] and [1, 2, 2, 3, 1] (the whole array).
             The shortest one is [2, 2], with length 2.
```

### Example 2

```
Input:  nums = [1, 2, 2, 3, 1, 4, 2]
Output: 6
Explanation: The degree is 3, because the element 2 appears 3 times.
             The shortest subarray with degree 3 is [2, 2, 3, 1, 4, 2], length 6.
```

## 💡 Intuition

Here's the key insight that unlocks this problem: for any number that reaches the array's maximum frequency, the **shortest subarray containing all of its occurrences** simply spans from its **first appearance** to its **last appearance**.

So instead of checking every possible subarray (which would be slow), we only need three pieces of information for each number as we scan the array once:

1. **How many times it appears** → its frequency (`count`)
2. **The index where it first appears** → `first_seen`
3. **The index where it last appears** → `last_seen`

Once we know these, the answer boils down to:

> Among all numbers that share the array's maximum frequency (the "degree"), find the one whose `(last_seen - first_seen + 1)` is smallest.

## 🛠️ Approach

1. **Single pass through `nums`** to build three hash maps:
   - `count[num]` — frequency of `num`
   - `first_seen[num]` — index of `num`'s first occurrence
   - `last_seen[num]` — index of `num`'s most recent occurrence
   - Along the way, track the running maximum frequency as `degree`.

2. **Second pass, over the hash map (not the array)** to check every number whose frequency equals `degree`. For each of those, compute the subarray length `last_seen - first_seen + 1`, and keep the smallest one found.

3. Return the smallest length.

## ⏱️ Complexity

| Metric | Complexity | Why |
|---|---|---|
| Time  | `O(n)` | We scan `nums` once, then scan the hash map (at most `n` unique keys) once. |
| Space | `O(n)` | Three hash maps, each holding at most one entry per unique number. |

## 🧑‍💻 Code

```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first_seen;
        unordered_map<int, int> last_seen;
        
        int degree = 0;
        
        // Populate the maps and find the overall degree
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            // Log the first time we see this number
            if (first_seen.count(num) == 0) {
                first_seen[num] = i;
            }
            
            // Continuously update the last time we've seen it
            last_seen[num] = i;
            
            // Increment frequency and update the maximum degree found so far
            count[num]++;
            degree = max(degree, count[num]);
        }
        
        int min_length = nums.size();
        
        // Check lengths of subarrays for all elements that match the maximum degree
        for (const auto& [num, freq] : count) {
            if (freq == degree) {
                int length = last_seen[num] - first_seen[num] + 1;
                min_length = min(min_length, length);
            }
        }
        
        return min_length;
    }
};
```

## 🚀 How to Run

1. Copy `Solution` class into your LeetCode C++ editor, **or**
2. Compile locally:
   ```bash
   g++ -std=c++17 -o solution solution.cpp
   ./solution
   ```
   *(You'll need to add a `main()` function with some test cases, since this file only contains the `Solution` class.)*

## 🏷️ Tags

`Array` `Hash Table` `Greedy` `Two Pointers` — Difficulty: **Easy**

## 📄 License

Feel free to use, copy, or adapt this solution for learning purposes.