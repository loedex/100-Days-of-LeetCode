# 219. Contains Duplicate II

![LeetCode](https://img.shields.io/badge/LeetCode-219-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus)
![Topic](https://img.shields.io/badge/Topic-Hash%20Map%20%7C%20Sliding%20Window-purple?style=for-the-badge)

---

## 📝 Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if there exist **two distinct indices** `i` and `j` in the array such that:

- `nums[i] == nums[j]`, **and**
- `abs(i - j) <= k`

Otherwise, return `false`.

---

## 🧪 Examples

### Example 1
```
Input:  nums = [1, 2, 3, 1],  k = 3
Output: true

Explanation: nums[0] == nums[3] == 1, and abs(0 - 3) = 3 <= k (3). ✅
```

### Example 2
```
Input:  nums = [1, 0, 1, 1],  k = 1
Output: true

Explanation: nums[2] == nums[3] == 1, and abs(2 - 3) = 1 <= k (1). ✅
```

### Example 3
```
Input:  nums = [1, 2, 3, 1, 2, 3],  k = 2
Output: false

Explanation: Duplicate pairs exist but none are within distance k = 2. ❌
```

---

## 💡 Intuition

The key challenge here is not just finding duplicates — it's finding duplicates that are **close enough** to each other (within a window of size `k`).

Think of it like a **sliding window** with memory:
- As we walk through the array, we want to remember **where we last saw** each number.
- If we encounter a number we've seen before, we check: *"How far back did I see it?"*
- If the gap is within `k`, we've found our pair!

A **Hash Map** is the perfect tool here — it lets us store each number alongside its most recent index, giving us O(1) lookups.

---

## 🚀 Approach — Hash Map (Single Pass)

### Step-by-Step Walkthrough

1. Create an `unordered_map<int, int>` called `numMap` to store `{ value → most recent index }`.
2. Loop through each index `i` in `nums`:
   - **Check** if `nums[i]` already exists in the map.
   - If it does, **check** whether the distance `i - numMap[nums[i]]` is `<= k`.
     - If yes → return `true` immediately.
   - **Update** the map with the current index (always keep the latest index for each value).
3. If the loop finishes without a match → return `false`.

### Why update with the latest index?

Because a closer occurrence always gives us the **best chance** to satisfy `abs(i - j) <= k`. An older index only makes the gap larger, so we discard it.

---

## 💻 Code

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Map to store the value and its most recent index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number exists in the map
            if (numMap.count(nums[i])) {
                // Check if the distance between indices is <= k
                if (i - numMap[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the map with the current index
            numMap[nums[i]] = i;
        }
        
        // If we finish the loop without finding any, return false
        return false;
    }
};
```

---

## 🔍 Dry Run

Let's trace through `nums = [1, 2, 3, 1]`, `k = 3`:

| Step | `i` | `nums[i]` | `numMap` before check         | Action                                | Result  |
|------|-----|-----------|-------------------------------|---------------------------------------|---------|
| 1    | 0   | 1         | `{}`                          | Not found → add `{1: 0}`             | —       |
| 2    | 1   | 2         | `{1:0}`                       | Not found → add `{1:0, 2:1}`         | —       |
| 3    | 2   | 3         | `{1:0, 2:1}`                  | Not found → add `{1:0, 2:1, 3:2}`    | —       |
| 4    | 3   | 1         | `{1:0, 2:1, 3:2}`             | Found! `3 - 0 = 3 <= k(3)` ✅        | `true`  |

---

## ⏱️ Complexity Analysis

| Metric           | Value   | Explanation                                          |
|------------------|---------|------------------------------------------------------|
| **Time**         | `O(n)`  | Single pass through the array; each map op is O(1)   |
| **Space**        | `O(min(n, k))` | Map holds at most `k+1` entries at any point   |

> **Note on Space:** In the worst case (all unique elements), the map grows up to size `n`. But practically, since we only care about elements within distance `k`, it's bounded by `min(n, k)`.

---

## 🔄 Alternative Approaches

### Approach 1: Brute Force — O(n²) Time, O(1) Space
```cpp
for (int i = 0; i < nums.size(); i++)
    for (int j = i + 1; j <= min((int)nums.size() - 1, i + k); j++)
        if (nums[i] == nums[j]) return true;
return false;
```
Simple but slow for large inputs. ❌ Not recommended.

### Approach 2: Sliding Window with a Set — O(n log k) Time, O(k) Space
Maintain a sliding window of size `k` using an ordered set. Insert elements and check for duplicates within the window. Slightly worse than the hash map approach but guarantees the window is always of size `k`.

### Approach 3: Hash Map *(this solution)* — O(n) Time ✅
Best overall. Simple, fast, and easy to reason about.

---

## 🧠 Key Takeaways

- **Hash Maps are powerful** when you need to track "have I seen this before, and where?"
- **Always update to the latest index** — a more recent occurrence is always more useful.
- This pattern (value → last seen index) is a classic technique that appears in many array/string problems.
- The trick of checking `i - map[val] <= k` avoids using `abs()` since we always iterate left to right (`i` is always >= the stored index).

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---------|------------|
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | Easy |
| 220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | Hard |
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | Easy |
| 560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | Medium |

---

## 📚 Tags

`Array` `Hash Table` `Sliding Window`