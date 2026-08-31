# 168. Excel Sheet Column Title

**Difficulty:** Easy
**Topics:** Math, String
**Source:** [LeetCode](https://leetcode.com/problems/excel-sheet-column-title/)

## Problem

Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
```

### Example 1

```
Input:  columnNumber = 1
Output: "A"
```

### Example 2

```
Input:  columnNumber = 28
Output: "AB"
```

### Example 3

```
Input:  columnNumber = 701
Output: "ZY"
```

### Constraints

- `1 <= columnNumber <= 2^31 - 1`

## Approach

This is essentially converting a number to **base 26**, but with a twist: Excel's column system has **no symbol for zero** — it goes `A, B, ..., Z, AA, AB, ...` instead of `A0, A1, ...`. This makes it a **bijective base-26** numeral system rather than standard base-26.

To handle that, before taking each digit we do `columnNumber--`. This shifts the range from `1–26` down to `0–25`, letting us map cleanly onto `'A'–'Z'` using `columnNumber % 26`. We then divide by 26 and repeat until `columnNumber` reaches 0, building the string from least significant "digit" to most significant — which is why we reverse it at the end.

### Steps

1. While `columnNumber > 0`:
   - Decrement `columnNumber` by 1 (convert 1-indexed to 0-indexed).
   - Compute the current character: `'A' + (columnNumber % 26)`.
   - Append it to the result.
   - Divide `columnNumber` by 26 (integer division).
2. Reverse the result string, since digits were generated from least to most significant.
3. Return the result.

## Solution (C++)

```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string result = "";

        while (columnNumber > 0) {
            columnNumber--; // Shift from 1-indexed to 0-indexed
            char currentChar = 'A' + (columnNumber % 26);
            result.push_back(currentChar);
            columnNumber /= 26;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
```

## Complexity

| Metric | Complexity | Notes |
|---|---|---|
| Time  | `O(log₂₆ n)` | One iteration per base-26 digit of `columnNumber` |
| Space | `O(log₂₆ n)` | For the output string (excluding the output itself, `O(1)` extra space) |

## Key Takeaway

Whenever you see a labeling scheme that skips "zero" (like Excel columns, or spreadsheet-style IDs), think **bijective numeral system** — and remember the trick of decrementing before the modulo to shift the digit range down by one.