<div align="center">

# Day 91: Self Dividing Numbers

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-728-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

A **self-dividing number** is a number that is divisible by every digit it contains.

- For example, `128` is a self-dividing number because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.

A self-dividing number is **not allowed to contain the digit zero**.

Given two integers `left` and `right`, return a list of all the self-dividing numbers in the range `[left, right]` (both **inclusive**).

### Examples

| Example | Input | Output |
|:-------:|-------|--------|
| 1 | `left = 1`, `right = 22` | `[1,2,3,4,5,6,7,8,9,11,12,15,22]` |
| 2 | `left = 47`, `right = 85` | `[48,55,66,77]` |

### Constraints

- `1 <= left <= right <= 10^4`

---

## Intuition

The problem asks us to test every number in a range against a simple rule. The range is small (at most 10,000 numbers), so the most direct plan works well:

> For each number in the range, check whether it is self-dividing. If it is, add it to the answer.

The real question becomes: **how do we check one number?**

To look at each digit of a number, we can **peel digits off one at a time**:

- `n % 10` gives the **last digit**.
- `n / 10` **removes** the last digit.

Repeating these two steps visits every digit from right to left. For each digit, we ask two questions:

1. Is the digit `0`? If yes, the number is **not** self-dividing (also, dividing by zero is not allowed).
2. Does the digit divide the original number evenly? If not, the number is **not** self-dividing.

If every digit passes both tests, the number is self-dividing.

---

## Approach

**Check each number in the range using a helper function.**

**Main function (`selfDividingNumbers`):**

1. Create an empty result vector.
2. Loop `num` from `left` to `right` (inclusive).
3. If `isSelfDividing(num)` is true, add `num` to the result.
4. Return the result.

**Helper function (`isSelfDividing`):**

1. Save the original number in `n`, and work with a copy `temp`, because we need the **original** value for the divisibility test while we shrink the copy.
2. While `temp > 0`:
   - Extract the last digit: `digit = temp % 10`.
   - If `digit == 0` or `n % digit != 0`, return `false` immediately.
   - Remove the last digit: `temp /= 10`.
3. If the loop finishes without returning, every digit passed, so return `true`.

### Why check `digit == 0` first?

The condition `digit == 0 || n % digit != 0` relies on **short-circuit evaluation**. If the digit is `0`, the `||` stops right away, so `n % digit` is never evaluated. This prevents a **division by zero** error.

### Why keep both `n` and `temp`?

We shrink `temp` to walk through the digits, but each divisibility test must use the **full original number** `n`. Keeping both avoids losing the original value.

### Dry Run

**Example: `num = 128`**

| Step | `temp` | `digit = temp % 10` | Check | Result | `temp / 10` |
|:----:|:------:|:-------------------:|-------|:------:|:-----------:|
| 1 | 128 | 8 | `128 % 8 == 0` | passes | 12 |
| 2 | 12 | 2 | `128 % 2 == 0` | passes | 1 |
| 3 | 1 | 1 | `128 % 1 == 0` | passes | 0 |

The loop ends with `temp = 0`, so `128` is **self-dividing**.

**Numbers that fail:**

| Number | Reason | Result |
|:------:|--------|:------:|
| `10` | Last digit is `0` | Not self-dividing |
| `13` | `13 % 3 = 1` (not divisible by 3) | Not self-dividing |
| `47` | `47 % 7 = 5` (not divisible by 7) | Not self-dividing |
| `48` | `48 % 8 = 0` and `48 % 4 = 0` | Self-dividing |

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result;
        
        for (int num = left; num <= right; ++num) {
            if (isSelfDividing(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }

private:
    bool isSelfDividing(int n) {
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            // A self-dividing number cannot contain zero, 
            // and the number must be divisible by each of its digits.
            if (digit == 0 || n % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
};
```

---

## Complexity Analysis

Let `N = right - left + 1` be the number of values in the range, and `d` the number of digits in the largest number.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(N * d)` | Each number is checked by looping over its digits. Since `right <= 10^4`, `d <= 5`, so this is effectively `O(N)`. |
| **Space** | `O(1)` | Only a few integer variables are used, not counting the output list. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Single-digit numbers (`1` to `9`) | Always self-dividing, since any digit divides itself. |
| Numbers containing `0` (e.g. `10`, `101`, `1000`) | Rejected immediately by the `digit == 0` check. |
| Division by zero | Prevented by short-circuit evaluation (`digit == 0` is tested first). |
| Repeated digits (e.g. `11`, `22`, `77`) | Always self-dividing, since `n` is a multiple of its repeated digit. |
| `left == right` | The loop runs once and returns either one number or an empty list. |
| Upper bound `10^4` | Contains zeros, so it is correctly rejected. |

---

## Key Takeaways

- **`% 10` and `/ 10`** are the standard pair for extracting digits one by one. This pattern appears in many problems such as Palindrome Number, Happy Number and Add Digits.
- Splitting the logic into a **helper function** (`isSelfDividing`) makes the code cleaner, easier to read and easier to test.
- Short-circuit evaluation protects against **division by zero** without needing a separate `if` statement.
- Working on a copy (`temp`) keeps the original value (`n`) available for the divisibility checks.

### Alternative Approach

The digit check can also be done by converting the number to a string and testing each character (`s[i] - '0'`). It is easy to read, but the arithmetic approach used here is faster and uses no extra memory for strings.

---

## Related Problems

- Palindrome Number (LeetCode 9)
- Happy Number (LeetCode 202)
- Add Digits (LeetCode 258)
- Armstrong Number (LeetCode 1134)
- Count Numbers with Unique Digits (LeetCode 357)