# 🧮 LeetCode 415 — Add Strings

[![LeetCode](https://img.shields.io/badge/LeetCode-415-orange?style=flat-square&logo=leetcode)](https://leetcode.com/problems/add-strings/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green?style=flat-square)]()
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)]()
[![Time](https://img.shields.io/badge/Time-O(max(m%2Cn))-blueviolet?style=flat-square)]()
[![Space](https://img.shields.io/badge/Space-O(max(m%2Cn))-blueviolet?style=flat-square)]()

A clean, well-commented C++ solution to **LeetCode 415: Add Strings**, along with a full breakdown of the approach, complexity, and edge cases — so anyone browsing this repo (including future-you) can understand it at a glance.

---

## 📋 Problem Statement

Given two non-negative integers, `num1` and `num2`, represented as strings, return the sum of `num1` and `num2` **as a string**.

You must solve the problem **without using any built-in big-integer library** and **without directly converting the inputs to integers**.

### Example 1
```
Input:  num1 = "11", num2 = "123"
Output: "134"
```

### Example 2
```
Input:  num1 = "456", num2 = "77"
Output: "533"
```

### Example 3
```
Input:  num1 = "0", num2 = "0"
Output: "0"
```

### Constraints
- `1 <= num1.length, num2.length <= 10^4`
- `num1` and `num2` consist of only digits `0-9`
- `num1` and `num2` don't have leading zeros, except the number `0` itself

---

## 💡 Intuition

Think about how you add two numbers **by hand** on paper — you don't add from the leftmost digit, you start from the **rightmost (units) digit** and work backwards, carrying over any overflow to the next column.

That's exactly what this solution simulates:

1. Start a pointer at the **last character** of each string.
2. Add the corresponding digits together, plus any `carry` from the previous step.
3. The last digit of that sum is appended to the result; the rest becomes the new `carry`.
4. Move both pointers one step to the left and repeat.
5. Stop only when **both strings are exhausted AND there's no carry left**.
6. Since digits were appended from least-significant to most-significant, **reverse the result** at the end.

This mirrors elementary school addition — no type conversion, no overflow risk, and it naturally handles numbers of *any* length.

---

## 🛠️ Approach (Step by Step)

| Step | What's happening |
|------|-------------------|
| 1 | Two pointers `i` and `j` start at the last index of `num1` and `num2`. |
| 2 | A `carry` variable tracks overflow between digit additions (starts at `0`). |
| 3 | Loop while `i >= 0` **or** `j >= 0` **or** `carry > 0` — this lets shorter strings and a final leftover carry (e.g. `"5" + "5" = "10"`) be handled automatically. |
| 4 | Inside the loop, pull a digit from each string *only if that pointer is still valid*, converting `char` → `int` via `num1[i] - '0'`. |
| 5 | `carry = sum / 10` keeps the tens digit for the next round; `sum % 10` is the digit we actually keep. |
| 6 | Append digits to `result` (they come out **reversed**), then flip the whole string once at the end with `std::reverse`. |

### Why this loop condition is the key trick
```cpp
while (i >= 0 || j >= 0 || carry > 0)
```
This single line elegantly handles **three tricky edge cases** at once:
- ✅ `num1` and `num2` have different lengths.
- ✅ One string is fully consumed before the other.
- ✅ A trailing carry needs one extra digit (e.g. `"99" + "1" = "100"`).

---

## 🧾 Code

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }

            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
```

> 💡 **Note:** Don't forget `#include <string>` and `#include <algorithm>` (for `std::reverse`) if you're compiling this outside of LeetCode's environment.

---

## ⏱️ Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|--------------|
| **Time** | `O(max(m, n))` | We walk through each string exactly once, where `m` and `n` are the lengths of `num1` and `num2`. |
| **Space** | `O(max(m, n))` | The `result` string grows to hold the final sum, whose length is at most `max(m, n) + 1`. |

No extra data structures, no recursion — just a single pass with constant extra variables (`i`, `j`, `carry`, `sum`).

---

## 🔍 Dry Run Example

Let's trace `num1 = "456"`, `num2 = "77"`:

| Iteration | `i` | `j` | digits added | `sum` | `carry` | digit appended | `result` so far |
|-----------|-----|-----|---------------|-------|---------|------------------|-------------------|
| 1 | 2 | 1 | `6 + 7` | 13 | 1 | `3` | `"3"` |
| 2 | 1 | 0 | `5 + 7 + 1` | 13 | 1 | `3` | `"33"` |
| 3 | 0 | -1 | `4 + carry(1)` | 5 | 0 | `5` | `"335"` |

Loop ends (`i < 0`, `j < 0`, `carry == 0`) → reverse `"335"` → **`"533"`** ✅

---

## ✅ Why Not Just Convert to `int` or `long long`?

Great question if you're new to this problem! The constraints allow strings up to **10,000 digits long** — that's a number far larger than what any built-in integer type (`int`, `long`, `long long`, even `__int128`) can hold. Converting would cause **overflow**, which is exactly why LeetCode asks us to simulate the addition manually. This solution works correctly no matter how large the numbers get, because it only ever operates on single digits (0–9) at a time.

---

## 🗂️ Related Problems

If you enjoyed this one, these follow a similar "simulate manual arithmetic" pattern:

- [43. Multiply Strings](https://leetcode.com/problems/multiply-strings/)
- [67. Add Binary](https://leetcode.com/problems/add-binary/)
- [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

---

## 📁 Repo Structure

```
.
├── README.md
└── add_strings.cpp
```

---

## 🙌 Author Notes

Solved as part of my ongoing DSA practice. Feedback, alternative approaches, and PRs are always welcome!

⭐ If this helped you, consider starring the repo!