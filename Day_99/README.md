<div align="center">

# Day 99: Maximum Subarray With Equal Products

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-3411-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Number%20Theory-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

You are given an array of positive integers `nums`.

An array `arr` is called **product equivalent** if:

```text
prod(arr) == lcm(arr) * gcd(arr)
```

where:

- `prod(arr)` is the **product** of all elements of `arr`.
- `gcd(arr)` is the **greatest common divisor** of all elements of `arr`.
- `lcm(arr)` is the **least common multiple** of all elements of `arr`.

Return the length of the **longest product equivalent subarray** of `nums`.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `nums = [1,2,1,2,1,1,1]` | `5` | The longest product equivalent subarray is `[1,2,1,1,1]`, where `prod = 2`, `lcm = 2` and `gcd = 1`. |
| 2 | `nums = [2,3,4,5,6]` | `3` | The longest product equivalent subarray is `[3,4,5]`, where `prod = 60`, `lcm = 60` and `gcd = 1`. |
| 3 | `nums = [1,2,3,1,4,5,1]` | `5` | Taken from the original problem. |

### Constraints

- `2 <= nums.length <= 100`
- `1 <= nums[i] <= 10`

---

## Intuition

Checking the condition `prod == lcm * gcd` directly is awkward, because the numbers can become large. A cleaner way is to look at the **prime factors**.

Every number is built from primes. Because `nums[i] <= 10`, only four primes can ever appear: **2, 3, 5 and 7**.

Fix one prime `p`, and let `e_k` be the **exponent of `p`** in the `k`-th element of the subarray (it is `0` if `p` does not divide that element). Then:

| Quantity | Exponent of `p` in it |
|----------|-----------------------|
| `prod` | `e_1 + e_2 + ... + e_m` (the **sum** of exponents) |
| `lcm` | `max(e_1, ..., e_m)` (the **largest** exponent) |
| `gcd` | `min(e_1, ..., e_m)` (the **smallest** exponent) |

So `prod == lcm * gcd` holds exactly when, for **every** prime `p`:

```text
sum of exponents  ==  max exponent  +  min exponent
```

This turns a problem about huge products into a simple check on small exponent counts.

### A quick example

Take `[3, 4, 5]` and the prime `2`. The exponents of `2` are `[0, 2, 0]`:

```text
sum = 2,   max = 2,   min = 0     ->   2 == 2 + 0   OK
```

The same check passes for primes `3`, `5` and `7`, so `[3, 4, 5]` is product equivalent.

---

## Approach

**Brute force over all subarrays, checking the exponent rule for each prime.**

The constraint `n <= 100` is small, so we can afford to test every subarray `[i, j]`.

1. Keep `ans = 1` as the starting best length.
2. For every start index `i` and end index `j >= i`:
   - Assume the subarray is valid (`ok = true`).
   - For each prime `p` in `{2, 3, 5, 7}`:
     - Scan the elements `k` from `i` to `j`. For each element, count how many times `p` divides it (`expP`).
     - If `expP > 0`, update these values:
       - `cnt`: how many elements contain `p`.
       - `sum`: the total of all exponents.
       - `mn` and `mx`: the smallest and largest positive exponent.
     - Work out the **true minimum** exponent over the whole subarray: if **every** element contains `p` (`cnt == length`), the minimum is `mn`. Otherwise at least one element has exponent `0`, so the minimum is `0`.
     - If `mx + effectiveMin != sum`, the subarray fails for this prime, so set `ok = false` and stop checking primes.
   - If `ok` is still true, update `ans = max(ans, j - i + 1)`.
3. Return `ans`.

### Why the `effectiveMin` step?

The code only records exponents of elements that actually contain `p`, so `mn` ignores the zeros. But the real `gcd` exponent is the minimum over **all** elements, including those where the exponent is `0`. The line

```cpp
int effectiveMin = (cnt == (j - i + 1)) ? mn : 0;
```

fixes that. If at least one element does not contain `p`, the true minimum is `0`.

### Dry Run

**Example 2: `nums = [2,3,4,5,6]`**

**A subarray that passes: `[3, 4, 5]`**

| Prime | Exponents | `sum` | `mx` | `cnt` vs length | `effectiveMin` | `mx + effectiveMin` | Passes? |
|:-----:|:---------:|:-----:|:----:|:---------------:|:--------------:|:-------------------:|:-------:|
| 2 | `[0, 2, 0]` | 2 | 2 | 1 vs 3 | 0 | 2 | Yes |
| 3 | `[1, 0, 0]` | 1 | 1 | 1 vs 3 | 0 | 1 | Yes |
| 5 | `[0, 0, 1]` | 1 | 1 | 1 vs 3 | 0 | 1 | Yes |
| 7 | `[0, 0, 0]` | 0 | 0 | 0 vs 3 | 0 | 0 | Yes |

All primes pass, so the length `3` is a candidate.

**A subarray that fails: `[3, 4, 5, 6]`**

| Prime | Exponents | `sum` | `mx` | `cnt` vs length | `effectiveMin` | `mx + effectiveMin` | Passes? |
|:-----:|:---------:|:-----:|:----:|:---------------:|:--------------:|:-------------------:|:-------:|
| 2 | `[0, 2, 0, 1]` | 3 | 2 | 2 vs 4 | 0 | 2 | **No** (`2 != 3`) |

The prime `2` appears in both `4` and `6`, which breaks the rule, so this subarray is rejected.

**Result: `3`**

### Checking a tricky input: `nums = [2, 6]`

| Prime | Exponents | `sum` | `mx` | `cnt` vs length | `effectiveMin` | `mx + effectiveMin` | Passes? |
|:-----:|:---------:|:-----:|:----:|:---------------:|:--------------:|:-------------------:|:-------:|
| 2 | `[1, 1]` | 2 | 1 | 2 vs 2 | 1 | 2 | Yes |
| 3 | `[0, 1]` | 1 | 1 | 1 vs 2 | 0 | 1 | Yes |
| 5 | `[0, 0]` | 0 | 0 | 0 vs 2 | 0 | 0 | Yes |
| 7 | `[0, 0]` | 0 | 0 | 0 vs 2 | 0 | 0 | Yes |

The whole array is valid (indeed `2 * 6 = 12 = lcm(2, 6) * gcd(2, 6) = 6 * 2`), so the answer is `2`.

---

## Solution (C++)

```cpp
class Solution {
public:
    int maxLength(vector<int>& nums) {
       int n = static_cast<int>(nums.size());
        int primes[4] = {2, 3, 5, 7};
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool ok = true;
                for (int p : primes) {
                    int mn = INT_MAX, mx = 0, sum = 0, cnt = 0;
                    for (int k = i; k <= j; ++k) {
                        int x = nums[k];
                        int expP = 0;
                        while (x % p == 0) {
                            ++expP;
                            x /= p;
                        }
                        if (expP > 0) {
                            ++cnt;
                            sum += expP;
                            mn = min(mn, expP);
                            mx = max(mx, expP);
                        }
                    }
                    int effectiveMin = (cnt == (j - i + 1)) ? mn : 0;
                    if (mx + effectiveMin != sum) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
```

---

## Complexity Analysis

Let `n` be the length of `nums`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n^3)` | There are `O(n^2)` subarrays, and checking each one scans up to `n` elements for each of the 4 primes. The inner `while` loop runs at most 3 times, since `nums[i] <= 10`. |
| **Space** | `O(1)` | Only a few integer variables are used. |

With `n <= 100`, this is roughly a few hundred thousand basic steps, which is very fast.

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| All elements equal to `1` | Every exponent is `0`, so `0 == 0 + 0` holds and the whole array is valid. |
| Any subarray of length 2 | Always valid, since `a * b = lcm(a, b) * gcd(a, b)` for two numbers. The answer is therefore at least `2` for valid inputs. |
| Primes that never appear | `cnt = 0`, `mx = 0` and `sum = 0`, so the check passes trivially (and `mn` stays at `INT_MAX` but is never used). |
| Repeated equal elements such as `[2, 2, 2]` | The prime `2` has exponents `[1, 1, 1]`, so `sum = 3` but `max + min = 2`, which fails. |
| Elements `1` mixed in | A `1` has no prime factors, so it never breaks the rule. |

---

## Key Takeaways

- **Prime factorization turns hard problems into easy ones.** Comparing exponents is simpler and safer than multiplying large products.
- `prod`, `lcm` and `gcd` correspond to the **sum**, **max** and **min** of exponents of each prime.
- Always ask what the **minimum** really means. Ignoring the zero exponents of elements that lack the prime would give the wrong `gcd`, and that is exactly the kind of detail this problem tests.
- Reading the constraint `nums[i] <= 10` limits the relevant primes to `{2, 3, 5, 7}`.

### Alternative Approach

For a subarray of length 3 or more, the equation `sum == max + min` can only hold if **at most one element contains each prime**, because all the "middle" exponents must add up to zero. In other words, for longer subarrays the condition simply means the elements are **pairwise coprime**.

This allows an `O(n^2)` solution: for each start index, extend the subarray while keeping a bitmask of the primes already used, and stop when a new element shares a prime with the mask. Length-2 subarrays are always valid and can be handled separately.

| Approach | Time | Idea |
|----------|:----:|------|
| **Exponent check (this solution)** | `O(n^3)` | Test the sum, max and min rule on every subarray. |
| **Pairwise coprime with a bitmask** | `O(n^2)` | Extend each subarray while the primes stay disjoint. |

---

## Related Problems

- Greatest Common Divisor of Strings (LeetCode 1071)
- Find Greatest Common Divisor of Array (LeetCode 1979)
- Count Primes (LeetCode 204)
- Subarray Product Less Than K (LeetCode 713)
- Ugly Number (LeetCode 263)