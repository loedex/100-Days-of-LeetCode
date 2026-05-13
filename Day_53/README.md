# 🔄 LeetCode #7 — Reverse Integer

![LeetCode](https://img.shields.io/badge/LeetCode-007EC6?style=for-the-badge&logo=leetcode&logoColor=white)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Topic](https://img.shields.io/badge/Topic-Math-green?style=for-the-badge)

---

## 📋 Problem Statement

Given a signed 32-bit integer `x`, return `x` with its digits **reversed**.

If reversing `x` causes the value to go **outside the signed 32-bit integer range** `[-2³¹, 2³¹ - 1]`, return `0`.

> ⚠️ **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

---

## 📥 Examples

### Example 1
```
Input:  x = 123
Output: 321
```

### Example 2
```
Input:  x = -123
Output: -321
```

### Example 3
```
Input:  x = 120
Output: 21
```

---

## 🚧 Constraints

- `-2³¹ <= x <= 2³¹ - 1`
- No 64-bit integer storage allowed

---

## 💡 Intuition

The core idea is simple — **pop digits one by one from the end of `x` and push them onto `rev`**.

Think of it like reversing a stack of digits:
- **Pop**: Extract the last digit using `x % 10`
- **Shift x**: Remove that digit with `x /= 10`
- **Push**: Append the digit to the reversed number using `rev = rev * 10 + pop`

The real challenge? **Overflow detection** — the reversed number might not fit in a 32-bit integer. We handle this *before* it happens, so we never need a 64-bit type.

---

## 🧠 Approach — Math (No 64-bit integers)

### Step-by-step Walkthrough

```
x = 123

Iteration 1:
  pop = 123 % 10 = 3
  x   = 123 / 10 = 12
  rev = 0 * 10 + 3 = 3

Iteration 2:
  pop = 12 % 10  = 2
  x   = 12 / 10  = 1
  rev = 3 * 10 + 2 = 32

Iteration 3:
  pop = 1 % 10   = 1
  x   = 1 / 10   = 0
  rev = 32 * 10 + 1 = 321

x == 0 → Exit loop
Return 321 ✅
```

---

## 🔐 Overflow Guard — The Key Insight

Since we can't use `long long`, we must check for overflow **before** it happens.

### 32-bit Integer Range
| Boundary | Value |
|---|---|
| `INT_MAX` | `2,147,483,647` |
| `INT_MIN` | `-2,147,483,648` |

### Overflow Check Logic

Before computing `rev = rev * 10 + pop`, we check:

#### ✅ Positive Overflow
```cpp
if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
    return 0;
```
- `INT_MAX / 10 = 214748364`
- If `rev > 214748364`, multiplying by 10 would already overflow.
- If `rev == 214748364`, then the last digit of `INT_MAX` is `7`, so `pop > 7` would overflow.

#### ✅ Negative Overflow
```cpp
if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
    return 0;
```
- `INT_MIN / 10 = -214748364`
- If `rev < -214748364`, multiplying by 10 would already overflow.
- If `rev == -214748364`, then the last digit of `INT_MIN` is `-8`, so `pop < -8` would overflow.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check for positive overflow
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            
            // Check for negative overflow
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value | Reason |
|---|---|---|
| **Time** | `O(log₁₀ n)` | We process each digit of `x` once |
| **Space** | `O(1)` | Only a fixed number of variables used |

---

## 🧪 Edge Cases

| Input | Output | Reason |
|---|---|---|
| `0` | `0` | Zero reversed is zero |
| `120` | `21` | Leading zeros are dropped |
| `-123` | `-321` | Negative sign is preserved |
| `1534236469` | `0` | Reversed value overflows `INT_MAX` |
| `-2147483648` | `0` | Already at `INT_MIN`, any reversal overflows |

---

## 🗂️ Topics & Tags

`Math` · `Overflow Handling` · `Two's Complement` · `Digit Manipulation`

---

## 🔗 Related Problems

| # | Problem | Difficulty |
|---|---|---|
| 8 | String to Integer (atoi) | Medium |
| 190 | Reverse Bits | Easy |
| 9 | Palindrome Number | Easy |

---

## 📚 References

- [LeetCode Problem #7](https://leetcode.com/problems/reverse-integer/)
- [INT_MAX / INT_MIN in C++ — cppreference](https://en.cppreference.com/w/cpp/types/climits)