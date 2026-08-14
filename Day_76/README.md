# 292. Nim Game

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/nim-game/

## Problem

You are playing Nim with a friend:

- There is a heap of `n` stones.
- You and your friend alternate turns, **you go first**.
- On each turn, the current player removes **1 to 3** stones.
- Whoever removes the **last stone wins**.

Given `n`, return `true` if you can win the game (assuming both players play optimally), otherwise return `false`.

### Examples

```
Input: n = 4
Output: false

Input: n = 1
Output: true

Input: n = 2
Output: true
```

## Approach

This looks like it needs recursion or DP at first glance, but there's a neat pattern hiding underneath — that's the fun part of this problem.

- If `n` is **not a multiple of 4**, you can always remove enough stones (1, 2, or 3) to leave your friend with a multiple of 4.
- Once your friend is stuck facing a multiple of 4, **no matter what they remove (1–3)**, you can always remove the complement (3, 2, or 1) to hand them another multiple of 4 right back.
- Eventually they're forced to face `n = 4`, and whatever they take, you take the rest and win.
- If `n` **is** a multiple of 4 from the start, that losing position gets handed to *you* instead — so you lose.

So the whole problem boils down to one check:

```
n % 4 != 0
```

## Solution

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

## Complexity

| Metric | Complexity |
|--------|------------|
| Time   | O(1)       |
| Space  | O(1)       |

## Key Takeaway

When a problem mentions "optimal play," it's often hinting at game theory. Before diving into recursion/DP, try computing results for small `n` by hand — patterns like this one tend to reveal themselves quickly (here, every multiple of 4 is a losing position).