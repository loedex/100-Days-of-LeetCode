<div align="center">

# Day 92: Prime Number of Set Bits in Binary Representation

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-762-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit%20Manipulation-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given two integers `left` and `right`, return the **count** of numbers in the **inclusive** range `[left, right]` having a **prime number of set bits** in their binary representation.

Recall that the **number of set bits** an integer has is the number of `1`s present when written in binary.

- For example, `21` written in binary is `10101`, which has `3` set bits.

### Examples

| Example | Input | Output |
|:-------:|-------|:------:|
| 1 | `left = 6`, `right = 10` | `4` |
| 2 | `left = 10`, `right = 15` | `5` |

**Example 1 explanation:**

| Number | Binary | Set Bits | Prime? |
|:------:|:------:|:--------:|:------:|
| 6 | `110` | 2 | Yes |
| 7 | `111` | 3 | Yes |
| 8 | `1000` | 1 | No (1 is not prime) |
| 9 | `1001` | 2 | Yes |
| 10 | `1010` | 2 | Yes |

Four numbers have a prime number of set bits.

### Constraints

- `1 <= left <= right <= 10^6`
- `0 <= right - left <= 10^4`

---

## Intuition

This problem combines two small ideas:

1. **Count the set bits** of each number in the range.
2. **Check whether that count is prime.**

The first idea is straightforward: for each number, count how many `1`s appear in its binary form.

The second idea has a helpful shortcut. Because `right <= 10^6` and `2^20 = 1,048,576 > 10^6`, every number in the range fits within **20 bits**. So the number of set bits can never exceed **20**. Instead of writing a general prime-checking function, we can simply **list every prime up to 20**:

```text
2, 3, 5, 7, 11, 13, 17, 19
```

Checking whether a count is prime then becomes a quick lookup in this small set.

---

## Approach

**Count set bits with a built-in function and look the count up in a set of primes.**

1. Store the primes up to 20 in an `unordered_set`: `{2, 3, 5, 7, 11, 13, 17, 19}`.
2. Loop `num` from `left` to `right` (inclusive).
3. For each number, compute `setBits = __builtin_popcount(num)`. This returns the number of `1` bits.
4. If `setBits` is found in the prime set, increase the counter.
5. Return the counter.

### What is `__builtin_popcount`?

It is a compiler built-in (available in GCC and Clang) that counts the set bits of an unsigned integer, typically using a single fast CPU instruction. In C++20, the standard equivalent is `std::popcount` from the `<bit>` header.

### Dry Run

**Example 1: `left = 6`, `right = 10`**

| `num` | Binary | `setBits` | In prime set? | `count` |
|:-----:|:------:|:---------:|:-------------:|:-------:|
| 6 | `110` | 2 | Yes | 1 |
| 7 | `111` | 3 | Yes | 2 |
| 8 | `1000` | 1 | No | 2 |
| 9 | `1001` | 2 | Yes | 3 |
| 10 | `1010` | 2 | Yes | 4 |

**Result: `4`**

**Example 2: `left = 10`, `right = 15`**

| `num` | Binary | `setBits` | In prime set? | `count` |
|:-----:|:------:|:---------:|:-------------:|:-------:|
| 10 | `1010` | 2 | Yes | 1 |
| 11 | `1011` | 3 | Yes | 2 |
| 12 | `1100` | 2 | Yes | 3 |
| 13 | `1101` | 3 | Yes | 4 |
| 14 | `1110` | 3 | Yes | 5 |
| 15 | `1111` | 4 | No | 5 |

**Result: `5`**

---

## Solution (C++)

```cpp
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
       // Since right <= 10^6, the maximum number of set bits for any integer
        // in this range is 20 (since 2^20 > 10^6).
        // Primes up to 20 are: 2, 3, 5, 7, 11, 13, 17, 19.
        std::unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        
        int count = 0;
        for (int num = left; num <= right; ++num) {
            // std::popcount is available in C++20 (or we can use __builtin_popcount)
            int setBits = __builtin_popcount(num);
            if (primes.count(setBits)) {
                count++;
            }
        }
        
        return count; 
    }
};
```

---

## Complexity Analysis

Let `N = right - left + 1` be the number of values in the range.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(N)` | Each number is processed once. Counting bits is effectively constant time (at most 20 bits), and a set lookup is `O(1)` on average. Since `N <= 10^4 + 1`, this is very fast. |
| **Space** | `O(1)` | The prime set always holds exactly 8 values, regardless of the input. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| `left == right` | The loop runs once and returns `0` or `1`. |
| Powers of two (e.g. `8`, `16`) | They have exactly 1 set bit. Since 1 is **not** prime, they are not counted. |
| Numbers with 2 set bits (e.g. `3`, `5`, `6`, `9`) | Counted, since 2 is prime. |
| Largest values near `10^6` | Their set bit counts never exceed 20, so the prime set covers every possibility. |
| Lower bound `left = 1` | `1` has 1 set bit, which is not prime, so it is correctly excluded. |

---

## Key Takeaways

- Reading the **constraints** carefully unlocks simplifications. Knowing that numbers fit in 20 bits means we only need primes up to 20.
- A **small hard-coded set** of primes is cleaner and faster than writing a general prime-checking function.
- `__builtin_popcount` (or `std::popcount` in C++20) counts set bits in constant time. The manual alternative is the classic loop `n &= (n - 1)`, which removes one set bit per step.
- Remember that **1 is not a prime number**, which is why numbers with a single set bit never count.

### Alternative Approach

Instead of an `unordered_set`, the primes can be packed into a single **bitmask**. Bit `p` of the mask is set when `p` is prime, so the primality check becomes one shift and one AND:

```cpp
const int PRIME_MASK = 665772; // binary 10100010100010101100 -> primes 2,3,5,7,11,13,17,19

if ((PRIME_MASK >> setBits) & 1) {
    count++;
}
```

This avoids the hashing cost of `unordered_set` and is a popular trick in competitive programming. The set-based version used in the solution above is easier to read, which is why it is a good first choice.

---

## Related Problems

- Number of 1 Bits (LeetCode 191)
- Counting Bits (LeetCode 338)
- Count Primes (LeetCode 204)
- Hamming Distance (LeetCode 461)
- Power of Two (LeetCode 231)