# 283. Move Zeroes 🚀

![LeetCode](https://img.shields.io/badge/LeetCode-283-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-JavaScript-yellow?style=for-the-badge&logo=javascript)
![Topic](https://img.shields.io/badge/Topic-Two%20Pointers-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Array-blueviolet?style=for-the-badge)

---

## 📋 Problem Statement

Given an integer array `nums`, move all `0`s to the end of it while **maintaining the relative order** of the non-zero elements.

> **Note:** You must do this **in-place** without making a copy of the array.

🔗 **LeetCode Problem Link:** [Move Zeroes - LeetCode #283](https://leetcode.com/problems/move-zeroes/)

---

## 📌 Examples

### Example 1
```
Input:  nums = [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

### Example 2
```
Input:  nums = [0]
Output: [0]
```

---

## 📐 Constraints

- `1 <= nums.length <= 10⁴`
- `-2³¹ <= nums[i] <= 2³¹ - 1`

---

## 💡 Intuition

The key idea behind this solution is the **Two Pointer** technique.

We maintain a pointer called `lastNonZeroIndex` that always tracks the **next available position** to place a non-zero element. As we scan through the array with another pointer `i`, every time we find a non-zero number, we **swap** it to the `lastNonZeroIndex` position and advance that pointer.

This way:
- All non-zero elements naturally bubble to the **front**, preserving their original relative order.
- All zeros get pushed to the **end** automatically via the swaps.

Think of `lastNonZeroIndex` as a "slot keeper" — it holds open a spot for the next non-zero value it finds.

---

## ✅ Solution

```javascript
var moveZeroes = function(nums) {
    let lastNonZeroIndex = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            [nums[lastNonZeroIndex], nums[i]] = [nums[i], nums[lastNonZeroIndex]];
            lastNonZeroIndex++;
        }
    }
};
```

---

## 🔍 Step-by-Step Walkthrough

Let's trace through `nums = [0, 1, 0, 3, 12]`:

| Step | `i` | `nums[i]` | Action                        | Array State          | `lastNonZeroIndex` |
|------|-----|-----------|-------------------------------|----------------------|--------------------|
| 1    | 0   | `0`       | Skip (it's zero)              | `[0, 1, 0, 3, 12]`  | 0                  |
| 2    | 1   | `1`       | Swap index 0 ↔ 1             | `[1, 0, 0, 3, 12]`  | 1                  |
| 3    | 2   | `0`       | Skip (it's zero)              | `[1, 0, 0, 3, 12]`  | 1                  |
| 4    | 3   | `3`       | Swap index 1 ↔ 3             | `[1, 3, 0, 0, 12]`  | 2                  |
| 5    | 4   | `12`      | Swap index 2 ↔ 4             | `[1, 3, 12, 0, 0]`  | 3                  |

**Final Output:** `[1, 3, 12, 0, 0]` ✅

---

## ⏱️ Complexity Analysis

| Complexity | Value  | Explanation                                              |
|------------|--------|----------------------------------------------------------|
| **Time**   | `O(n)` | We iterate through the array exactly once with one loop. |
| **Space**  | `O(1)` | No extra space used — everything is done in-place.       |

---

## 🧠 Key Concepts Used

- **Two Pointers** — `i` scans forward, `lastNonZeroIndex` tracks the placement position.
- **In-place Swap** — Uses JavaScript's ES6 destructuring swap: `[a, b] = [b, a]`.
- **Array Mutation** — Modifies the original array directly without creating a new one.

---

## 🔄 Alternative Approaches

### Approach 1: Fill After Collecting (Two-Pass)
Collect all non-zero elements first, then fill the rest with zeros. Simpler to understand, but uses **O(n) extra space**.

```javascript
var moveZeroes = function(nums) {
    const nonZeros = nums.filter(n => n !== 0);
    for (let i = 0; i < nums.length; i++) {
        nums[i] = i < nonZeros.length ? nonZeros[i] : 0;
    }
};
```
> ⚠️ Not in-place — uses extra memory.

### Approach 2: Write Non-Zeros, Then Fill Zeros (Optimized Two-Pass)
Write non-zeros to the front in one pass, then fill the remaining positions with `0` in a second pass. **O(1) space**, but two loops.

```javascript
var moveZeroes = function(nums) {
    let pos = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) nums[pos++] = nums[i];
    }
    while (pos < nums.length) nums[pos++] = 0;
};
```

### Approach 3: Two Pointer Swap ✅ *(Current Solution)*
Single pass, in-place swapping. **Optimal** — O(n) time, O(1) space.

---

## 📊 Approach Comparison

| Approach               | Time   | Space  | In-Place | Passes |
|------------------------|--------|--------|----------|--------|
| Filter & Fill          | `O(n)` | `O(n)` | ❌        | 2      |
| Write & Fill Zeros     | `O(n)` | `O(1)` | ✅        | 2      |
| **Two Pointer Swap** ✅ | `O(n)` | `O(1)` | ✅        | 1      |

---

## 🏷️ Tags

`Array` `Two Pointers` `In-Place` `Easy` `LeetCode`

---

## 📁 Related Problems

| Problem | Difficulty | Topic |
|---------|------------|-------|
| [27. Remove Element](https://leetcode.com/problems/remove-element/) | Easy | Two Pointers |
| [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Easy | Two Pointers |
| [75. Sort Colors](https://leetcode.com/problems/sort-colors/) | Medium | Two Pointers |

---

<div align="center">

⭐ If this solution helped you, consider giving the repository a **star**! ⭐

</div>