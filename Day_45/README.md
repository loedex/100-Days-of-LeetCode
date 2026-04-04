# 217. Contains Duplicate

![LeetCode](https://img.shields.io/badge/LeetCode-217-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=for-the-badge)

---

## 📝 Problem Statement

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

---

## 📌 Examples

### Example 1

```
Input:  nums = [1, 2, 3, 1]
Output: true
```

**Explanation:** The element `1` occurs at indices `0` and `3`.

---

### Example 2

```
Input:  nums = [1, 2, 3, 4]
Output: false
```

**Explanation:** All elements are distinct.

---

## 💡 Approach — Hash Set (unordered_set)

The key idea is simple:

> As we iterate through the array, we keep track of numbers we've already seen using a **Hash Set**.  
> If we encounter a number that's **already in the set**, we immediately return `true`.  
> If we finish the loop without any match, every element is unique — return `false`.

### Why `unordered_set`?

| Operation | `unordered_set` (avg) | `set` (sorted) |
|-----------|----------------------|----------------|
| Insert    | O(1)                 | O(log n)       |
| Lookup    | O(1)                 | O(log n)       |

Using `unordered_set` gives us **O(1) average** lookup and insert — making it the optimal choice here.

---

## 🧠 Complexity Analysis

| | Complexity |
|---|---|
| **Time**  | O(n) — one pass through the array |
| **Space** | O(n) — at most `n` elements stored in the set |

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.contains(num)) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};
```

---

## 🔍 Step-by-Step Walkthrough

Let's trace through `nums = [1, 2, 3, 1]`:

| Step | `num` | Set `s` before check | `s.contains(num)`? | Action |
|------|-------|----------------------|--------------------|--------|
| 1    | 1     | `{}`                 | ❌ No              | Insert → `{1}` |
| 2    | 2     | `{1}`                | ❌ No              | Insert → `{1, 2}` |
| 3    | 3     | `{1, 2}`             | ❌ No              | Insert → `{1, 2, 3}` |
| 4    | 1     | `{1, 2, 3}`          | ✅ Yes             | Return `true` 🎉 |

---

## ✅ Submission Results

| Metric   | Value       | Beats       |
|----------|-------------|-------------|
| Runtime  | 40 ms       | 73.89% 🚀   |
| Memory   | 90.93 MB    | 28.44%      |
| Test Cases Passed | 77 / 77 | ✅ All Passed |

---

## 🔗 Problem Link

[LeetCode 217 — Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

---

> 💬 *Feel free to open an issue or pull request if you have a more optimized approach!*