<div align="center">

# Day 87: Convert a Number to Hexadecimal

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-405-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit%20Manipulation-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given a 32-bit integer `num`, return a string representing its **hexadecimal** representation. For negative integers, the **two's complement** method is used.

All the letters in the answer string should be **lowercase** characters, and there should not be any leading zeros in the answer except for the zero itself.

**Note:** You are not allowed to use any built-in library method to directly solve this problem.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `num = 26` | `"1a"` | `26 = 1 * 16 + 10`, and `10` is written as `a`. |
| 2 | `num = -1` | `"ffffffff"` | In 32-bit two's complement, `-1` has all 32 bits set to `1`. |

### Constraints

- `-2^31 <= num <= 2^31 - 1`

---

## Intuition

Hexadecimal is base 16, and `16 = 2^4`. This means **one hex digit represents exactly 4 bits**. So instead of repeatedly dividing by 16, we can read the number **4 bits at a time**:

```text
Binary:  0001 1010
          |    |
Hex:      1    a
```

To convert a number:

1. Look at the **last 4 bits** and map them to a hex character (`0` to `f`).
2. **Shift** the number right by 4 bits to discard those bits.
3. Repeat until nothing is left.

Digits are produced from **least significant to most significant**, so the final string must be **reversed**.

### What about negative numbers?

In 32-bit two's complement, a negative number is stored as a specific 32-bit pattern. For example, `-1` is `1111 1111 ... 1111` (32 ones). If we treat those same 32 bits as an **unsigned** number, the conversion works with no special handling, and the 32 bits produce exactly 8 hex digits.

---

## Approach

**Extract 4 bits at a time using bit masking and shifting.**

1. If `num` is `0`, return `"0"` immediately. The loop below would otherwise produce an empty string.
2. Store the 16 hex characters in a lookup string: `"0123456789abcdef"`.
3. Copy `num` into an `unsigned int n`. This reinterprets the same 32 bits as non-negative, which handles two's complement for negatives automatically.
4. While `n > 0`:
   - `n & 15` extracts the last 4 bits (`15` is `1111` in binary), giving a value from `0` to `15`.
   - Append `hexChars[remainder]` to the result.
   - `n >>= 4` shifts right by 4 bits to move to the next hex digit.
5. Reverse the string and return it.

### Why `unsigned int`?

| Type | Problem |
|------|---------|
| `int` (signed) | For a negative number, `n > 0` is false immediately, so the loop would never run. Also, right-shifting a negative signed value typically fills with sign bits (`1`s), so the value would never reach zero. |
| `unsigned int` | The bits are treated as a plain positive value. Right shifts fill with `0`s, so `n` always reaches `0` after at most 8 iterations. |

### Why `& 15`?

`15` in binary is `1111`. A bitwise AND with `1111` keeps only the last 4 bits and clears everything else:

```text
  0001 1010   (26)
& 0000 1111   (15)
-----------
  0000 1010   (10, which maps to 'a')
```

### Dry Run

**Example 1: `num = 26`** (binary `0001 1010`)

| Iteration | `n` (binary) | `n & 15` | Hex char | `result` | After `n >>= 4` |
|:---------:|:------------:|:--------:|:--------:|:--------:|:---------------:|
| 1 | `0001 1010` | `1010` = 10 | `a` | `"a"` | `0001` = 1 |
| 2 | `0001` | `0001` = 1 | `1` | `"a1"` | `0` |

The loop ends because `n` is now `0`. Reversing `"a1"` gives **`"1a"`**.

**Example 2: `num = -1`**

`-1` is cast to `unsigned int`, giving the 32-bit pattern `1111 1111 1111 1111 1111 1111 1111 1111` (`4294967295`).

Each iteration extracts `1111` (15), which maps to `f`. After 8 shifts of 4 bits, all 32 bits are consumed:

```text
result = "ffffffff"  →  reversed  →  "ffffffff"
```

---

## Solution (C++)

```cpp
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        const char* hexChars = "0123456789abcdef";
        std::string result = "";
        
        // Cast to unsigned int to correctly handle negative numbers via two's complement
        unsigned int n = num;
        
        while (n > 0) {
            int remainder = n & 15; // Extract the last 4 bits
            result += hexChars[remainder];
            n >>= 4;                // Right shift by 4 bits
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(1)` | A 32-bit number has at most 8 hex digits, so the loop runs at most 8 times. |
| **Space** | `O(1)` | The result string holds at most 8 characters. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `num = 0` | Returned early as `"0"`, avoiding an empty result. |
| `num = -1` | Cast to `0xFFFFFFFF`, giving `"ffffffff"`. |
| `num = 2^31 - 1` (maximum) | Produces `"7fffffff"`. |
| `num = -2^31` (minimum) | Cast to `0x80000000`, giving `"80000000"`. No overflow issues, since no negation is used. |
| Leading zeros | Never produced, because the loop stops as soon as `n` reaches `0`. |
| Lowercase letters | Guaranteed by the lowercase lookup string. |

---

## Key Takeaways

- One hex digit equals **4 bits**, so conversion is just reading a number in groups of 4 bits.
- `n & 15` extracts the lowest 4 bits, and `n >>= 4` moves to the next group.
- Casting to `unsigned int` is a clean way to apply **two's complement** without writing separate logic for negative numbers.
- A lookup table (`"0123456789abcdef"`) maps values to characters without `if` statements.
- The same pattern generalizes: base 2 uses 1 bit per digit, base 8 uses 3 bits, and base 16 uses 4 bits.

### Alternative Approach

Instead of reversing at the end, you can **prepend** characters (`result = hexChars[remainder] + result`), or **fill a fixed array of 8 characters from the back** and skip leading zeros. The reverse approach used here is simple and easy to read.

---

## Related Problems

- Number of 1 Bits (LeetCode 191)
- Reverse Bits (LeetCode 190)
- Convert a Number to Base -2 (LeetCode 1017)
- Add Binary (LeetCode 67)
- Counting Bits (LeetCode 338)