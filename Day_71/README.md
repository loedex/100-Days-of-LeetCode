# 67. Add Binary

**Difficulty:** Easy
**Topics:** Math, String, Bit Manipulation
**LeetCode Link:** https://leetcode.com/problems/add-binary/

## Problem Statement

Given two binary strings `a` and `b`, return their sum as a binary string.

### Example 1

```
Input:  a = "11", b = "1"
Output: "100"
```

### Example 2

```
Input:  a = "1010", b = "1011"
Output: "10101"
```

### Constraints

- `1 <= a.length, b.length <= 10^4`
- `a` and `b` consist only of `'0'` or `'1'` characters.
- Each string does not contain leading zeros except for the zero itself.

## Approach

This solution mimics how you'd add two binary numbers by hand — starting from the **rightmost (least significant) bit** and moving left, just like elementary school addition, but in base 2 instead of base 10.

### Steps

1. **Set up two pointers** (`i` and `j`) at the last index of `a` and `b` respectively, and a `carry` variable initialized to `0`.
2. **Loop** as long as there are digits left in either string, *or* there's a leftover carry to account for.
3. On each iteration:
   - Start `sum` with the current `carry`.
   - Add the digit from `a` (if any digits remain), then move the pointer left.
   - Add the digit from `b` (if any digits remain), then move the pointer left.
   - The **current binary digit** is `sum % 2`.
   - The **new carry** is `sum / 2` (integer division).
4. Append each computed digit to `result`. Since we're building the answer from **least significant to most significant bit**, the string comes out backwards.
5. **Reverse** `result` at the end to get the correct binary string.

### Why this works

Binary addition follows the same carry rules as decimal addition:

| a | b | carry in | sum | digit | carry out |
|---|---|----------|-----|-------|-----------|
| 0 | 0 | 0        | 0   | 0     | 0         |
| 1 | 0 | 0        | 1   | 1     | 0         |
| 1 | 1 | 0        | 2   | 0     | 1         |
| 1 | 1 | 1        | 3   | 1     | 1         |

Since binary only has digits `0` and `1`, any sum of up to three 1's (a + b + carry) maxes out at `3`, so `sum % 2` and `sum / 2` are all we need to compute the digit and the next carry.

## Code

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop until both strings are exhausted and no carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // The current bit is the sum modulo 2
            result += std::to_string(sum % 2);

            // The new carry is the sum divided by 2
            carry = sum / 2;
        }

        // Since we appended from least to most significant bit, reverse the result
        std::reverse(result.begin(), result.end());

        return result;
    }
};
```

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|-----------|--------------|
| **Time** | `O(max(m, n))` | We iterate once through the longer of the two strings, where `m = a.length()` and `n = b.length()`. |
| **Space** | `O(max(m, n))` | The result string can be at most one digit longer than the longer input (due to a final carry). |

## Key Takeaways

- No need to convert the entire binary string to an integer — that would overflow for large inputs (up to 10<sup>4</sup> digits!). Working digit-by-digit avoids this entirely.
- The `carry > 0` condition in the loop is what correctly handles a leading `1` that overflows past both strings (e.g. `"1" + "1" = "10"`).
- Building the result backwards and reversing at the end is a common and efficient pattern for these "process from the right" string/number problems.

## Testing Locally

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// paste the Solution class here

int main() {
    Solution sol;
    cout << sol.addBinary("11", "1") << endl;     // 100
    cout << sol.addBinary("1010", "1011") << endl; // 10101
    cout << sol.addBinary("0", "0") << endl;       // 0
    return 0;
}
```