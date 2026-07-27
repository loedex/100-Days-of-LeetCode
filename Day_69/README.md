# 3536. Maximum Product of Two Digits

**Difficulty:** Easy
**Topics:** Math

## Problem

You are given a positive integer `n`. Return the maximum product of any two digits in `n`.

> **Note:** You may use the same digit twice if it appears more than once in `n`.

### Examples

**Example 1**
```
Input:  n = 31
Output: 3
Explanation: The digits of n are [3, 1]. The only possible product is 3 * 1 = 3.
```

**Example 2**
```
Input:  n = 22
Output: 4
Explanation: The digits of n are [2, 2]. The product is 2 * 2 = 4.
```

**Example 3**
```
Input:  n = 124
Output: 8
Explanation: The digits of n are [1, 2, 4]. The possible products are:
1*2=2, 1*4=4, 2*4=8. The maximum is 8.
```

### Constraints

- `10 <= n <= 9999`

## Intuition

To get the biggest possible product from a set of digits, you don't need to check every pair. Just grab the **two largest digits** you can find and multiply them together — that combo will always beat any other pairing.

So the whole problem boils down to: *scan the digits of `n`, and keep track of the largest and second-largest digit seen so far.*

## Approach

1. Initialize two trackers, `max1` and `max2`, both starting at `0`.
   - `max1` will hold the largest digit found so far.
   - `max2` will hold the second-largest digit found so far.
2. Repeatedly peel off the last digit of `n` using `n % 10`, then shrink `n` with `n /= 10`.
3. For each digit:
   - If it's bigger than `max1`, the old `max1` gets demoted to `max2`, and this digit becomes the new `max1`.
   - Otherwise, if it's bigger than `max2` (but not `max1`), it just replaces `max2`.
4. Once every digit has been processed, the answer is simply `max1 * max2`.

This is a single pass over the digits — no sorting, no extra arrays, just two variables doing all the work.

## Solution (C++)

```cpp
class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit > max1) {
                max2 = max1;
                max1 = digit;
            } else if (digit > max2) {
                max2 = digit;
            }
        }

        return max1 * max2;
    }
};
```

## Walkthrough Example

For `n = 124`:

| Step | digit | max1 | max2 |
|------|-------|------|------|
| start | -    | 0    | 0    |
| 1    | 4     | 4    | 0    |
| 2    | 2     | 4    | 2    |
| 3    | 1     | 4    | 2    |

Final answer: `max1 * max2 = 4 * 2 = 8` ✅

## Complexity

- **Time:** `O(log n)` — we process one digit per loop iteration, and `n` has `O(log n)` digits.
- **Space:** `O(1)` — only two integer variables are used, regardless of input size.

## Why This Works

Because `max1` and `max2` are updated together in the right order (checking `max1` first, then `max2`), by the time the loop finishes they're guaranteed to hold the true largest and second-largest digits — even if the biggest digit shows up more than once (like in `n = 22`, where both digits are `2`, so `max1` and `max2` both end up as `2`).