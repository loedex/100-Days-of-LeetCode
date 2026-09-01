# 171. Excel Sheet Column Number

**Difficulty:** Easy
**Topics:** Math, String
**LeetCode:** [Problem 171](https://leetcode.com/problems/excel-sheet-column-number/)

## Problem

Given a string `columnTitle` that represents the column title as it appears in an Excel sheet, return its corresponding column number.

For example:

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

### Examples

**Example 1:**
```
Input: columnTitle = "A"
Output: 1
```

**Example 2:**
```
Input: columnTitle = "AB"
Output: 28
```

**Example 3:**
```
Input: columnTitle = "ZY"
Output: 701
```

### Constraints

- `1 <= columnTitle.length <= 7`
- `columnTitle` consists only of uppercase English letters.
- `columnTitle` is in the range `["A", "FXSHRXW"]`.

## Approach

This is essentially converting a **base-26 number** to base-10 — but with a twist: it's not zero-indexed like normal base-26 (there's no digit for 0; `A` = 1, not 0). Think of it the same way you'd convert a string like `"123"` to the integer `123`:

- You go through each character left to right.
- At each step, you multiply the running result by the base (26 here) and add the value of the current digit.

For letters, the "digit value" of a character `c` is `c - 'A' + 1`, since `A` should map to 1, `B` to 2, and so on up to `Z` → 26.

## Solution (C++)

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};
```

### Step-by-step (example: `"AB"`)

| Step | Char | Digit (`c - 'A' + 1`) | `result = result * 26 + d` |
|------|------|------------------------|------------------------------|
| 1    | `A`  | 1                      | `0 * 26 + 1 = 1`             |
| 2    | `B`  | 2                      | `1 * 26 + 2 = 28`            |

Final answer: **28** ✅

## Complexity

- **Time Complexity:** `O(n)` — where `n` is the length of `columnTitle`, since we make a single pass through the string.
- **Space Complexity:** `O(1)` — only a constant amount of extra space is used.

## Key Takeaway

This problem is the reverse of [168. Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/). If you understand how positional number systems work (like how `"123"` becomes `123` in base-10), this becomes a simple pattern:

```
result = result * base + digitValue
```