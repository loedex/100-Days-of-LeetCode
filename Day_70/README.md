# LeetCode 58 — Length of Last Word

## 📝 Problem

Given a string `s` consisting of words and spaces, return the length of the **last word** in the string.

A *word* is defined as a maximal substring consisting of non-space characters only.

**Example 1**
```
Input:  s = "Hello World"
Output: 5
Explanation: The last word is "World", which has length 5.
```

**Example 2**
```
Input:  s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon", which has length 4.
```

**Example 3**
```
Input:  s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy", which has length 6.
```

---

## 💡 Approach

The key trick here is: **don't scan from the front — scan from the back.**

If we start from the beginning, we'd have to walk through every word until we hit the last one. But since we only care about the *last* word, it's much simpler to start at the end of the string and work backwards. Two clean steps:

1. **Skip trailing spaces.**
   Strings like `"moon  "` have spaces *after* the last word. Move the pointer `i` left until it lands on an actual character.

2. **Count backwards through the last word.**
   Keep moving `i` left, incrementing a `length` counter, until you either hit another space or run off the start of the string.

Once you hit a space (or `i < 0`), you've counted the entire last word — return `length`.

---

## 🔧 Code (C++)

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Step 1: Skip trailing spaces from the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
```

---

## 🔍 Walkthrough Example

For `s = "   fly me   to   the moon  "`:

| Step | What happens | `i` after |
|------|---------------------------------------|-----------|
| 1 | Skip trailing spaces (`"  "` at the end) | lands on `'n'` |
| 2 | Count backwards through `"moon"` → `length` becomes 4 | stops at the space before `'m'` |
| ✅ | Return `4` | — |

---

## ⏱️ Complexity

- **Time Complexity:** `O(n)` — in the worst case, we scan the string once from the back.
- **Space Complexity:** `O(1)` — only a couple of integer variables are used, no extra data structures.

---

## ✅ Why This Approach Works Well

- No need to `split()` the string into an array of words (which would cost extra space).
- No need to scan the whole string if the last word is near the end — we stop as soon as we've counted it.
- Handles tricky edge cases naturally:
  - Trailing spaces (`"moon  "`)
  - Leading spaces (`"   fly me"`)
  - Single word with no spaces (`"a"`)