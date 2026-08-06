# 1025. Divisor Game

**Difficulty:** Easy
**Topics:** Math, Dynamic Programming, Brainteaser
**LeetCode Link:** https://leetcode.com/problems/divisor-game/

## Problem Statement

Alice and Bob take turns playing a game, with **Alice starting first**.

On each turn, a player chooses an integer `x` such that:

- `0 < x < n`
- `n % x == 0` (x is a divisor of n)

The chosen player then **replaces `n` with `n - x`**.

If a player cannot make a move, they lose.

Return `true` if **Alice wins** the game (assuming both players play optimally), otherwise return `false`.

### Example 1
```
Input:  n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
```

### Example 2
```
Input:  n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
```

### Constraints
- `1 <= n <= 1000`

---

## Solution

```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
```

### The Core Insight

At first glance this looks like a game theory / DP problem (and you *can* solve it that way — more on that below). But there's a neat pattern hiding underneath: **Alice wins if and only if `n` is even.**

Here's the intuition, step by step:

1. **Base cases first.** If `n == 1`, Alice has no valid divisor to pick (since `x` must be strictly less than `n`), so she loses immediately. `1` is odd → matches "odd loses."
2. **If `n` is even**, Alice can always pick `x = 1`. That leaves Bob with `n - 1`, which is **odd**.
3. **If `n` is odd**, *every* divisor of an odd number is also odd. Subtracting an odd divisor from an odd number always leaves an **even** number for the opponent.
4. So the parity of `n` **flips every single turn**, and it always flips from whoever received an odd number back to even — meaning:
   - An **even** `n` can always be pushed toward eventually leaving the opponent stuck with `n = 1` (odd, losing position).
   - An **odd** `n` always hands the opponent an even number, putting the odd-holder at a disadvantage.
5. By induction, this pattern holds all the way down: **even `n` → winning position, odd `n` → losing position.**

So the entire game — despite looking like it needs recursion or memoization — collapses into a single parity check.

### Why This Beats the DP Approach

A more "obvious" first attempt looks like this:

```cpp
class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 2; i <= n; i++) {
            for (int x = 1; x < i; x++) {
                if (i % x == 0 && !dp[i - x]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```

This works, but it's `O(n^2)` time and `O(n)` space. Once you run it and notice the output is just `true, false, true, false, ...`, you can prove the parity pattern (as above) and drop straight to the one-liner.

**Lesson:** it's totally fine — encouraged, even — to start with the brute-force/DP solution to *see* the pattern, then prove it and simplify. That's exactly how this elegant solution was likely discovered.

---

## Complexity Analysis

| Approach          | Time Complexity | Space Complexity |
|--------------------|:----------------:|:------------------:|
| Parity trick (this)| `O(1)`            | `O(1)`              |
| DP / brute force   | `O(n^2)`          | `O(n)`              |

---

## Key Takeaways

- Not every problem tagged "DP" needs DP as the *final* solution — sometimes DP is just a tool to help you **discover** a mathematical pattern.
- When you see small/toy output like `n = 1..10` in a game-theory problem, print out the DP table and look for a pattern before assuming recursion is required.
- Parity (even/odd) arguments are a common trick in these "optimal play" style problems — worth keeping in your back pocket.