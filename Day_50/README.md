# 🍌 875. Koko Eating Bananas

![LeetCode](https://img.shields.io/badge/LeetCode-875-orange?style=flat-square&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=flat-square)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Algorithm](https://img.shields.io/badge/Algorithm-Binary%20Search-green?style=flat-square)

---

## 📖 Problem Description

Koko loves to eat bananas. There are `n` piles of bananas, the `i`-th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she:
- Chooses **one pile** of bananas
- Eats **k bananas** from that pile
- If the pile has **less than k bananas**, she eats **all of them** and will **not eat any more** during that hour

Koko likes to eat **slowly** but still wants to finish all the bananas before the guards return.

> **Goal:** Return the **minimum integer** `k` such that Koko can eat all bananas within `h` hours.

---

## 💡 Examples

### Example 1
```
Input:  piles = [3, 6, 7, 11], h = 8
Output: 4
```

### Example 2
```
Input:  piles = [30, 11, 23, 4, 20], h = 5
Output: 30
```

### Example 3
```
Input:  piles = [30, 11, 23, 4, 20], h = 6
Output: 23
```

---

## 🧠 Intuition & Approach

### Why Binary Search?

The key insight here is recognizing a **monotonic relationship**:

- If Koko can finish eating at speed `k` in time, she can **definitely** finish at speed `k+1` too.
- If she **cannot** finish at speed `k`, she **definitely cannot** at speed `k-1` either.

This monotonic property is exactly what makes **Binary Search** the perfect tool here! 🎯

### Search Space

| Boundary | Value | Reason |
|----------|-------|--------|
| **Minimum speed** (`low`) | `1` | Koko must eat at least 1 banana/hour |
| **Maximum speed** (`high`) | `max(piles)` | No point eating faster than the largest pile — she'd just sit idle |

### How to Calculate Hours for a Given Speed `k`

For each pile `p`, the hours needed = `⌈p / k⌉` (ceiling division).

We use the **ceiling division trick** to avoid floating-point math:

```
⌈p / k⌉  =  (p + k - 1) / k   ← using integer arithmetic
```

### Binary Search Logic

```
while (low < high):
    mid = (low + high) / 2

    if totalHours(mid) <= h:
        high = mid        ← mid might be valid, search left (smaller speeds)
    else:
        low = mid + 1     ← mid is too slow, search right (bigger speeds)

return low                ← converges to the minimum valid speed
```

---

## 🔍 Step-by-Step Walkthrough

Let's trace through **Example 1**: `piles = [3, 6, 7, 11]`, `h = 8`

```
low = 1,  high = 11

--- Iteration 1 ---
mid = 6
Hours: ⌈3/6⌉ + ⌈6/6⌉ + ⌈7/6⌉ + ⌈11/6⌉ = 1 + 1 + 2 + 2 = 6 ≤ 8 ✅
→ high = 6

--- Iteration 2 ---
low = 1, high = 6 → mid = 3
Hours: ⌈3/3⌉ + ⌈6/3⌉ + ⌈7/3⌉ + ⌈11/3⌉ = 1 + 2 + 3 + 4 = 10 > 8 ❌
→ low = 4

--- Iteration 3 ---
low = 4, high = 6 → mid = 5
Hours: ⌈3/5⌉ + ⌈6/5⌉ + ⌈7/5⌉ + ⌈11/5⌉ = 1 + 2 + 2 + 3 = 8 ≤ 8 ✅
→ high = 5

--- Iteration 4 ---
low = 4, high = 5 → mid = 4
Hours: ⌈3/4⌉ + ⌈6/4⌉ + ⌈7/4⌉ + ⌈11/4⌉ = 1 + 2 + 2 + 3 = 8 ≤ 8 ✅
→ high = 4

--- Loop ends (low == high == 4) ---
Answer: 4 ✅
```

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;

            for (int p : piles) {
                // Ceiling division: hours needed for this pile at speed mid
                totalHours += (p + mid - 1LL) / mid;
            }

            if (totalHours <= h) {
                // Koko can finish in time — try a smaller (slower) speed
                high = mid;
            } else {
                // Too slow — need a larger (faster) speed
                low = mid + 1;
            }
        }

        return low;
    }
};
```

### Key Implementation Details

**`1LL` in the ceiling formula:**
```cpp
totalHours += (p + mid - 1LL) / mid;
```
Using `1LL` ensures the addition is done in `long long` to prevent integer overflow when `p` and `mid` are large integers.

**`low + (high - low) / 2` instead of `(low + high) / 2`:**  
This is a classic overflow-prevention trick. If `low` and `high` are both large, their sum could overflow a 32-bit integer.

**Why `high = mid` (not `mid - 1`) when condition is true?**  
Because `mid` itself could be the answer! We keep it in range and let the loop converge.

---

## ⏱️ Complexity Analysis

| | Complexity | Explanation |
|--|-----------|-------------|
| **Time** | `O(n · log(max(piles)))` | Binary search over `[1, max]`, with `O(n)` work per iteration |
| **Space** | `O(1)` | No extra data structures — just a few variables |

---

## 🔗 Related Problems

| Problem | Difficulty | Pattern |
|---------|-----------|---------|
| [704. Binary Search](https://leetcode.com/problems/binary-search/) | Easy | Binary Search Basics |
| [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | Medium | Binary Search on Answer |
| [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | Hard | Binary Search on Answer |
| [1482. Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | Medium | Binary Search on Answer |

---

## 🏷️ Tags

`Binary Search` · `Array` · `Greedy`

---
