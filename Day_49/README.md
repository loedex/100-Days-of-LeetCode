# 347. Top K Frequent Elements

![LeetCode](https://img.shields.io/badge/LeetCode-347-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-JavaScript-yellow?style=for-the-badge&logo=javascript)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=for-the-badge)

---

## 📝 Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

You may return the answer in **any order**.

---

## 📌 Examples

### Example 1

```
Input:  nums = [1, 1, 1, 2, 2, 3],  k = 2
Output: [1, 2]
```

**Explanation:** `1` appears 3 times, `2` appears 2 times. The top 2 frequent elements are `[1, 2]`.

### Example 2

```
Input:  nums = [1],  k = 1
Output: [1]
```

**Explanation:** Only one element exists, so it is trivially the top 1 most frequent.

---

## 💡 Approach — Bucket Sort

There are multiple ways to solve this problem, but the **Bucket Sort** approach is the most elegant and efficient — achieving **O(n)** time, which actually beats the sorting-based O(n log n) approach.

### 🤔 The Core Idea

> Instead of sorting by frequency, we use the **array index itself as the frequency**!
>
> We create a `buckets` array where `buckets[i]` holds all numbers that appear exactly `i` times. Since a number can appear **at most `n` times** (where `n = nums.length`), we only need `n + 1` buckets.

---

### 🪣 Why Bucket Sort Over a Heap / Sorting?

| Approach         | Time Complexity | Space Complexity | Notes                          |
|------------------|-----------------|------------------|--------------------------------|
| Sorting by freq  | O(n log n)      | O(n)             | Simple but slower              |
| Max Heap         | O(n log k)      | O(n + k)         | Good when k << n               |
| **Bucket Sort**  | **O(n)**        | **O(n)**         | ✅ Optimal — used here         |

The problem guarantees a **unique answer** exists, which makes Bucket Sort perfectly safe to use.

---

### 🔢 Algorithm — 3 Clean Steps

```
Step 1 → Build a frequency map  (num → count)
Step 2 → Place each number into its matching frequency bucket
Step 3 → Scan buckets from highest → lowest, collect until we have k elements
```

---

## 🧠 Complexity Analysis

| | Complexity |
|---|---|
| **Time**  | O(n) — building the map is O(n), filling buckets is O(n), scanning is O(n) |
| **Space** | O(n) — frequency map + buckets array both scale with input size |

---

## 💻 Solution (JavaScript)

```javascript
var topKFrequent = function(nums, k) {
    const map = new Map();
    // Initialize buckets: index represents frequency
    // We use nums.length + 1 because an element could appear up to n times
    const buckets = Array.from({ length: nums.length + 1 }, () => []);
    const result = [];

    // 1. Build the frequency map
    for (let num of nums) {
        map.set(num, (map.get(num) || 0) + 1);
    }

    // 2. Populate the buckets
    // map.entries() gives us [number, frequency]
    for (let [num, freq] of map.entries()) {
        buckets[freq].push(num);
    }

    // 3. Iterate backwards from the highest frequency bucket
    for (let i = buckets.length - 1; i >= 0 && result.length < k; i--) {
        if (buckets[i].length > 0) {
            // Add elements from this bucket until we hit k
            for (let num of buckets[i]) {
                result.push(num);
                if (result.length === k) return result;
            }
        }
    }

    return result;
};
```

---

## 🔍 Step-by-Step Walkthrough

Let's trace through `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`:

### Step 1 — Build Frequency Map

| Number | Frequency |
|--------|-----------|
| 1      | 3         |
| 2      | 2         |
| 3      | 1         |

`map = { 1→3, 2→2, 3→1 }`

---

### Step 2 — Fill the Buckets

`buckets` array has 7 slots (index `0` to `6`, since `nums.length = 6`):

| Index (Frequency) | 0    | 1     | 2     | 3     | 4    | 5    | 6    |
|-------------------|------|-------|-------|-------|------|------|------|
| Contents          | `[]` | `[3]` | `[2]` | `[1]` | `[]` | `[]` | `[]` |

---

### Step 3 — Scan Backwards & Collect

| `i` | `buckets[i]` | Action                        | `result`   |
|-----|--------------|-------------------------------|------------|
| 6   | `[]`         | Empty, skip                   | `[]`       |
| 5   | `[]`         | Empty, skip                   | `[]`       |
| 4   | `[]`         | Empty, skip                   | `[]`       |
| 3   | `[1]`        | Push `1` → result.length = 1  | `[1]`      |
| 2   | `[2]`        | Push `2` → result.length = 2 = k → **return!** | `[1, 2]` ✅ |

---

## ⚠️ Edge Cases

| Input                        | `k` | Expected  | Reason                                  |
|------------------------------|-----|-----------|-----------------------------------------|
| `[1]`                        | 1   | `[1]`     | Single element, trivially the top 1     |
| `[1, 1, 2, 2]`               | 2   | `[1, 2]`  | Tie in frequency — both valid           |
| `[1, 2, 3, 4, 5]`            | 3   | any 3     | All have freq 1, any 3 are valid        |
| `[1, 1, 1, 1]`               | 1   | `[1]`     | Only one unique element                 |

---

## 🔗 Problem Link

[LeetCode 347 — Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

---

> 💬 *Feel free to open an issue or pull request if you have a more optimized approach!*