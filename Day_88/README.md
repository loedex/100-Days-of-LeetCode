<div align="center">

# Day 88: Base 7

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-504-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given an integer `num`, return a string of its **base 7** representation.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `num = 100` | `"202"` | `100 = 2 * 49 + 0 * 7 + 2 * 1` |
| 2 | `num = -7` | `"-10"` | `7 = 1 * 7 + 0 * 1`, with a minus sign added for the negative value. |

### Constraints

- `-10^7 <= num <= 10^7`

---

## Intuition

In base 10, the number `345` means `3 * 100 + 4 * 10 + 5 * 1`. Base 7 works the same way, but each position is a power of **7** instead of 10:

```text
..., 7^3 = 343, 7^2 = 49, 7^1 = 7, 7^0 = 1
```

To convert a number to base 7, we repeatedly ask:

> "How many 1s are left over after grouping by 7?"

- `num % 7` gives the **last digit** in base 7 (the remainder).
- `num / 7` removes that digit and moves to the next position.

Repeating this until the number becomes `0` produces all the digits, but from the **last digit to the first**. So at the end, the string must be **reversed**.

---

## Approach

**Repeated division by 7, collecting remainders.**

1. If `num` is `0`, return `"0"` immediately. The loop below would otherwise produce an empty string.
2. Remember whether the number is **negative**, then work with its **absolute value** so the division and modulo operations behave predictably.
3. While `num > 0`:
   - Append `num % 7` (as a character) to the result.
   - Update `num = num / 7`.
4. If the original number was negative, append a `'-'` sign.
5. **Reverse** the string and return it.

The minus sign is appended **before** the reverse step. After reversing, it correctly ends up at the **front** of the string.

### Why handle the sign separately?

In C++, the modulo of a negative number can produce a negative remainder (for example, `-7 % 7` is `0`, but `-8 % 7` is `-1`). Taking the absolute value first avoids this confusion, so every remainder is a clean digit from `0` to `6`.

### Dry Run

**Example 1: `num = 100`**

| Iteration | `num` | `num % 7` | `result` so far | `num / 7` |
|:---------:|:-----:|:---------:|:---------------:|:---------:|
| 1 | 100 | 2 | `"2"` | 14 |
| 2 | 14 | 0 | `"20"` | 2 |
| 3 | 2 | 2 | `"202"` | 0 |

The loop stops because `num` is `0`. Reversing `"202"` gives **`"202"`** (a palindrome in this case).

**Example 2: `num = -7`**

| Step | Action | `result` |
|:----:|--------|:--------:|
| 1 | `isNegative = true`, `num = 7` | `""` |
| 2 | `7 % 7 = 0`, then `num = 1` | `"0"` |
| 3 | `1 % 7 = 1`, then `num = 0` | `"01"` |
| 4 | Append the minus sign | `"01-"` |
| 5 | Reverse the string | **`"-10"`** |

---

## Solution (C++)

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        bool isNegative = num < 0;
        num = std::abs(num);
        
        std::string result = "";
        while (num > 0) {
            result += std::to_string(num % 7);
            num /= 7;
        }
        
        if (isNegative) {
            result += "-";
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
```

---

## Complexity Analysis

Let `n` be the absolute value of `num`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(log n)` | Each division by 7 shrinks the number, so the loop runs about `log base 7 of n` times. |
| **Space** | `O(log n)` | The result string stores one character per base 7 digit. |

Because `|num| <= 10^7`, the result has at most 9 digits, so in practice this runs in constant time.

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `num = 0` | Returned early as `"0"`. |
| Negative numbers | The sign is stored, the absolute value is converted, and `'-'` is placed at the front. |
| Exact powers of 7 (e.g. `7`, `49`) | Produce `"10"` and `"100"` correctly. |
| Single-digit results (`1` to `6`) | The loop runs once and returns the digit itself. |
| Largest values (`+/- 10^7`) | Fit safely in `int`, so `std::abs` causes no overflow. |

---

## Key Takeaways

- Converting to any base `b` follows the same pattern: **repeatedly take `% b` and divide by `b`**, then reverse the digits.
- Handling the sign separately keeps the digit logic simple and avoids negative remainders.
- The same code works for other bases (2 through 10) by changing the `7`. For bases above 10, a lookup string such as `"0123456789abcdef"` is needed for letters.
- `std::to_string` is used here to convert each single digit to a character. Writing `char('0' + num % 7)` would do the same job without creating a temporary string.

### Alternative Approach

A **recursive** version builds the string by converting `num / 7` first and then appending the last digit `num % 7`. This produces the digits in the correct order and removes the need to reverse. It uses `O(log n)` call stack space.

---

## Related Problems

- Convert a Number to Hexadecimal (LeetCode 405)
- Add Binary (LeetCode 67)
- Excel Sheet Column Title (LeetCode 168)
- Convert a Number to Base -2 (LeetCode 1017)