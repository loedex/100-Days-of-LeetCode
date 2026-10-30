<div align="center">

# Day 84: Longest Common Prefix

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-14-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Write a function to find the **longest common prefix** string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

### Examples

| Input | Output | Explanation |
|-------|--------|-------------|
| `strs = ["flower","flow","flight"]` | `"fl"` | All three strings start with `fl`. |
| `strs = ["dog","racecar","car"]` | `""` | There is no common prefix among the strings. |

### Constraints

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters if it is non-empty.

---

## Intuition

The straightforward idea is to compare every string with every other string, which is slow and repetitive. A smarter observation makes the problem much smaller.

After **sorting** the strings lexicographically (dictionary order), strings that share a prefix end up grouped together, and the two strings that are **most different** sit at opposite ends of the array: the first and the last.

This leads to a key insight:

> If the first and last strings share a prefix, then every string in between must share it too.

Why? Any string in the middle is "sandwiched" between the first and last in dictionary order. If it started with different characters inside that shared prefix, it could not fit between them. So we only need to compare **two strings** instead of all of them.

---

## Approach

**Sort, then compare the first and last strings.**

1. If the array is empty, return `""` (a safe guard).
2. Sort the array lexicographically.
3. Take `first = strs.front()` and `last = strs.back()`.
4. Find `minLength`, the length of the shorter of the two, since a common prefix cannot be longer than either string.
5. Walk through both strings with an index `i` while the characters match and `i < minLength`.
6. Return the substring `first.substr(0, i)`, which is the longest common prefix.

### Dry Run

Using `strs = ["flower","flow","flight"]`:

**Step 1: Sort the array**

```text
["flower", "flow", "flight"]  →  ["flight", "flow", "flower"]
```

**Step 2: Pick the first and last strings**

```text
first = "flight"
last  = "flower"
minLength = min(6, 6) = 6
```

**Step 3: Compare character by character**

| `i` | `first[i]` | `last[i]` | Match? | Action |
|:---:|:----------:|:---------:|:------:|--------|
| 0 | `f` | `f` | Yes | `i` becomes 1 |
| 1 | `l` | `l` | Yes | `i` becomes 2 |
| 2 | `i` | `o` | No | Stop |

**Result:** `first.substr(0, 2)` = `"fl"`

---

## Solution (C++)

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Sort the strings lexicographically
        std::sort(strs.begin(), strs.end());

        // The common prefix of the whole array must be common to 
        // the first and the last string after sorting.
        std::string first = strs.front();
        std::string last = strs.back();
        
        int minLength = std::min(first.length(), last.length());
        int i = 0;
        
        while (i < minLength && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};
```

---

## Complexity Analysis

Let `n` be the number of strings and `m` be the length of the longest string.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n * m * log n)` | Sorting performs `O(n log n)` comparisons, and each string comparison can take up to `O(m)`. The final prefix scan costs only `O(m)`. |
| **Space** | `O(m + log n)` | Two string copies (`first` and `last`) take `O(m)`, and the sort uses `O(log n)` auxiliary stack space. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Empty array | Returns `""` immediately. |
| Single string | `first` and `last` are the same string, so the whole string is returned. |
| No common prefix | The first characters differ, `i` stays `0`, and `""` is returned. |
| Contains an empty string | After sorting, it becomes the first element, `minLength` is `0`, and `""` is returned. |
| All strings identical | The entire string is returned. |
| One string is a prefix of another | The loop stops at `minLength`, so there is no out-of-bounds access. |

---

## Key Takeaways

- **Sorting reduces the problem:** comparing only the first and last strings is enough to determine the common prefix of the whole array.
- Bounding the loop by `minLength` prevents out-of-range access.
- Note that `std::sort` **modifies the input array in place**. This is acceptable for this problem, but worth remembering in real-world code.

### Alternative Approach

**Vertical scanning** compares the same character position across all strings, column by column, and stops at the first mismatch. It runs in `O(n * m)` time and `O(1)` extra space, which is more efficient than the sorting approach and does not modify the input.

---

## Related Problems

- Longest Common Prefix in a Trie (a common follow-up using the Trie data structure)
- Implement Trie (Prefix Tree) (LeetCode 208)
- Group Anagrams (LeetCode 49)