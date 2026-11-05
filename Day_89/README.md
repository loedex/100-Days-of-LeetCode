<div align="center">

# Day XX: Perfect Number

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-507-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

A **perfect number** is a **positive integer** that is equal to the sum of its **positive divisors**, excluding the number itself. A **divisor** of an integer `x` is an integer that can divide `x` evenly.

Given an integer `n`, return `true` if `n` is a perfect number, otherwise return `false`.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `num = 28` | `true` | `28 = 1 + 2 + 4 + 7 + 14`. These are all the divisors of 28 (excluding 28 itself). |
| 2 | `num = 7` | `false` | The only divisor of 7 other than itself is `1`, and `1 != 7`. |

### Constraints

- `1 <= num <= 10^8`

---

## Intuition

The direct idea is to try every number from `1` to `num - 1`, add up the ones that divide `num`, and compare the sum with `num`. This works, but with `num` up to `10^8` it would take up to 100 million steps, which is too slow.

The key observation is that **divisors come in pairs**. If `i` divides `num`, then `num / i` also divides `num`:

```text
28 = 1 x 28
28 = 2 x 14
28 = 4 x 7
```

In every pair, one divisor is **at most `sqrt(num)`** and the other is **at least `sqrt(num)`**. So we only need to search up to `sqrt(num)`. Each time we find a small divisor `i`, we get its partner `num / i` for free.

---

## Approach

**Pair up divisors by looping only up to the square root.**

1. If `num <= 1`, return `false`. The number `1` has no divisors other than itself, so its sum is `0` and it cannot be perfect.
2. Start with `sum = 1`. Since `1` divides every number greater than 1, we add it up front and never need to test it in the loop.
3. Loop `i` from `2` while `i * i <= num`:
   - If `num % i == 0`, add `i` to the sum.
   - Also add its partner `num / i`, **unless** `i * i == num`, in which case both are the same number and must be counted only once.
4. Return `true` if `sum == num`, otherwise `false`.

### Why the `i * i != num` check?

For a perfect square such as `36`, the divisor `6` pairs with itself (`6 x 6 = 36`). Without the check, `6` would be added **twice**, giving a wrong sum.

### Why start the loop at 2 and not 1?

If the loop started at `1`, the partner of `1` would be `num` itself, which the problem says must be **excluded**. Starting at `2` with `sum = 1` handles this cleanly.

### Dry Run

**Example 1: `num = 28`** (starts with `sum = 1`)

| `i` | `i * i <= 28`? | `28 % i == 0`? | Added | `sum` |
|:---:|:--------------:|:--------------:|-------|:-----:|
| 2 | Yes (4) | Yes | `2` and `28 / 2 = 14` | 17 |
| 3 | Yes (9) | No | nothing | 17 |
| 4 | Yes (16) | Yes | `4` and `28 / 4 = 7` | 28 |
| 5 | Yes (25) | No | nothing | 28 |
| 6 | No (36) | stop | | 28 |

`sum == num` (28 == 28), so the answer is **`true`**.

**Example 2: `num = 7`** (starts with `sum = 1`)

| `i` | `i * i <= 7`? | `7 % i == 0`? | `sum` |
|:---:|:-------------:|:-------------:|:-----:|
| 2 | Yes (4) | No | 1 |
| 3 | No (9) | stop | 1 |

`sum != num` (1 != 7), so the answer is **`false`**.

---

## Solution (C++)

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        
        int sum = 1; // 1 is a divisor for all numbers > 1
        
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        
        return sum == num;
    }
};
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(sqrt(n))` | The loop runs at most `sqrt(num)` times. For `num = 10^8`, that is about 10,000 iterations instead of 100 million. |
| **Space** | `O(1)` | Only a few integer variables are used. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `num = 1` | Returns `false` immediately. It has no divisors other than itself. |
| Prime numbers (e.g. `7`) | No divisors found in the loop, so `sum` stays `1` and does not equal `num`. |
| Perfect squares (e.g. `36`) | The `i * i != num` check prevents counting the square root twice. |
| Smallest perfect number `6` | `sum = 1`, then `i = 2` adds `2` and `3`, giving `6`, so the answer is `true`. |
| Largest input `10^8` | Loop runs about 10,000 times, and `i * i` stays within `int` range. |

---

## Key Takeaways

- **Divisors come in pairs** `(i, num / i)`, so searching up to `sqrt(num)` is enough. This reduces `O(n)` to `O(sqrt(n))`.
- Always watch for the **perfect square case** so the middle divisor is not counted twice.
- Initializing `sum = 1` and starting from `2` avoids including the number itself.
- The same square-root trick appears in prime checking, counting divisors and factorization problems.

### Alternative Approach

For `num <= 10^8`, only **five** perfect numbers exist: `6`, `28`, `496`, `8128` and `33550336`. A constant-time solution can simply check whether `num` is one of these. It is the fastest option, but it relies on knowing the values in advance and does not teach the general technique, which is why the divisor-pairing approach above is the more valuable one to learn.

---

## Related Problems

- Count Primes (LeetCode 204)
- Happy Number (LeetCode 202)
- Valid Perfect Square (LeetCode 367)
- Sqrt(x) (LeetCode 69)
- Ugly Number (LeetCode 263)