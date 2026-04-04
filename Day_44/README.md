# 🪨 771. Jewels and Stones

![LeetCode](https://img.shields.io/badge/LeetCode-771-brightgreen?style=flat-square&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-success?style=flat-square)
![Language](https://img.shields.io/badge/Language-C++-blue?style=flat-square&logo=cplusplus)
![Topic](https://img.shields.io/badge/Topic-Hash%20Set-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Solved%20✓-brightgreen?style=flat-square)

---

## 📌 Problem Statement

> You're given strings `jewels` representing the types of stones that are jewels,
> and `stones` representing the stones you have.
> Each character in `stones` is a type of stone you have.
> You want to know **how many of the stones you have are also jewels**.
>
> Letters are **case-sensitive**, so `"a"` is considered a different type of stone from `"A"`.

🔗 [View Problem on LeetCode](https://leetcode.com/problems/jewels-and-stones/)

---

## 📥 Examples

### Example 1

```
Input:  jewels = "aA", stones = "aAAbbbb"
Output: 3
```

### Example 2

```
Input:  jewels = "z", stones = "ZZ"
Output: 0
```

---

## 🔒 Constraints

- `1 <= jewels.length, stones.length <= 50`
- `jewels` and `stones` consist of only English letters
- All the characters of `jewels` are **unique**

---

## 💡 Intuition

At first glance, you might think:

> *"Let me just loop through every stone and for each stone, loop through all the jewels to check if it matches."*

That works — but it's **O(n × m)** in time complexity.
For every stone, you're doing a full scan of `jewels`. That's wasteful.

The smarter approach is to use an **unordered_set (Hash Set)**:

1. Insert all jewel characters into a Hash Set → **O(1) lookup time**
2. Loop through stones once → check if each stone exists in the set
3. If yes → increment the counter

This brings us down to **O(n + m)** — significantly better!

---

## 🧠 Approach — Hash Set Lookup

| Step | Action |
|------|--------|
| 1️⃣ | Create an `unordered_set<char>` and insert all characters from `jewels` |
| 2️⃣ | Initialize a `count` variable to `0` |
| 3️⃣ | Iterate through each character in `stones` |
| 4️⃣ | If the character exists in the set → increment `count` |
| 5️⃣ | Return `count` |

---

## ✅ Solution (C++)

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // Step 1: Store all jewel types in a Hash Set for O(1) lookup
        unordered_set<char> jewelSet;
        for (int i : jewels) {
            jewelSet.insert(i);
        }

        // Step 2: Count stones that are also jewels
        int count = 0;
        for (int i : stones) {
            if (jewelSet.count(i)) {
                count++;
            }
        }

        return count;
    }
};
```

---

## ❌ Brute Force vs ✅ Optimized — Side by Side

```cpp
// ❌ Brute Force — O(n × m) — Nested loops, slow
int count = 0;
for (char s : stones) {
    for (char j : jewels) {
        if (s == j) count++;
    }
}

// ✅ Optimized — O(n + m) — Hash Set, fast
unordered_set<char> jewelSet(jewels.begin(), jewels.end());
int count = 0;
for (char s : stones) {
    if (jewelSet.count(s)) count++;
}
```

---

## 📊 Complexity Analysis

| | Complexity | Reason |
|--|------------|--------|
| ⏱️ **Time** | `O(n + m)` | One pass to build the set + one pass through stones |
| 🧠 **Space** | `O(n)` | Hash Set stores all unique characters from `jewels` |

> Where `n` = length of `jewels` and `m` = length of `stones`

---

## 🔑 Key Takeaway

> **Hash Sets are your best friend when you need fast lookups.**
>
> Any time you find yourself writing a loop-inside-a-loop just to *search* for a value,
> pause and ask: *"Can I pre-load this into a Hash Set?"*
> Most of the time — yes. And it will cut your time complexity from O(n × m) to O(n + m).
>
> This is a reflex you build — one problem at a time.

---

## 🗂️ Topics

`Hash Table` &nbsp; `String` &nbsp; `Data Structures` &nbsp; `C++`

---

## 👨‍💻 Author

**Husnain Ahmad**
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue?style=flat-square&logo=linkedin)](https://www.linkedin.com/in/husnain-ahmad-911b883a6)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black?style=flat-square&logo=github)](https://github.com/loedex)

---

## 📁 My DSA Journey

This problem is part of my **Learn in Public** DSA series where I solve, document,
and share LeetCode problems with clear explanations — not just code dumps.

---

## 👨‍💻 Author

**Husnain Ahmad**
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue?style=flat-square&logo=linkedin)](https://www.linkedin.com/in/husnain-ahmad-911b883a6)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black?style=flat-square&logo=github)](https://github.com/loedex)

---

> ⭐ Star this repo if you find it helpful — it keeps me motivated to keep going!
