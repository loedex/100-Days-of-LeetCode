# 20. Valid Parentheses

![LeetCode](https://img.shields.io/badge/LeetCode-20-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=for-the-badge)

---

## 📝 Problem Statement

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is **valid**.

An input string is valid if:

1. Open brackets must be closed by the **same type** of brackets.
2. Open brackets must be closed in the **correct order**.
3. Every close bracket has a **corresponding open bracket** of the same type.

---

## 📌 Examples

### Example 1

```
Input:  s = "()"
Output: true
```

### Example 2

```
Input:  s = "()[]{}"
Output: true
```

### Example 3

```
Input:  s = "(]"
Output: false
```

---

## 💡 Approach — Stack + Hash Map

The key insight here is:

> Brackets must be matched in a **Last In, First Out (LIFO)** order — which is exactly what a **Stack** is perfect for!

Here's the plan:
- Use a `stack<char>` to keep track of unmatched **opening** brackets.
- Use an `unordered_map<char, char>` that maps each **closing** bracket to its corresponding **opening** bracket.
- As we loop through the string:
  - If the current character is a **closing bracket** → check if the stack's top matches the expected opening bracket. If not (or stack is empty), return `false`.
  - If the current character is an **opening bracket** → just push it onto the stack.
- At the end, the stack must be **empty** (no unmatched open brackets left).

---

## 🧠 Complexity Analysis

| | Complexity |
|---|---|
| **Time**  | O(n) — single pass through the string |
| **Space** | O(n) — stack can hold at most `n/2` opening brackets |

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (map.count(c)) {
                if (st.empty() || st.top() != map[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
```

---

## 🔍 Step-by-Step Walkthrough

Let's trace through `s = "({[]})"`:

| Step | `c`  | Is Closing? | Stack before  | Action                              | Stack after  |
|------|------|-------------|---------------|-------------------------------------|--------------|
| 1    | `(`  | No          | `[]`          | Push `(`                            | `[(]`        |
| 2    | `{`  | No          | `[(]`         | Push `{`                            | `[(, {]`     |
| 3    | `[`  | No          | `[(, {]`      | Push `[`                            | `[(, {, []`  |
| 4    | `]`  | Yes         | `[(, {, []`   | Top=`[` matches map`]`=`[` → Pop   | `[(, {]`     |
| 5    | `}`  | Yes         | `[(, {]`      | Top=`{` matches map`}`=`{` → Pop   | `[(]`        |
| 6    | `)`  | Yes         | `[(]`         | Top=`(` matches map`)`=`(` → Pop   | `[]`         |

Stack is empty → return `true` ✅

---

## ⚠️ Edge Cases to Watch Out For

| Input    | Expected | Reason                                       |
|----------|----------|----------------------------------------------|
| `""`     | `true`   | Empty string → stack is empty → valid        |
| `"("`    | `false`  | Unmatched open bracket left in stack         |
| `")"`    | `false`  | Stack is empty when closing bracket appears  |
| `"([)"]` | `false`  | Wrong closing order                          |

---

## ✅ Submission Results

| Metric            | Value     | Beats          |
|-------------------|-----------|----------------|
| Runtime           | 0 ms      | 🏆 **100.00%** |
| Memory            | 9.18 MB   | 15.08%         |
| Test Cases Passed | 102 / 102 | ✅ All Passed  |

---

## 🔗 Problem Link

[LeetCode 20 — Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

---

---

## 👨‍💻 Author

**Husnain Ahmad**

---

> 💬 *Feel free to open an issue or pull request if you have a more optimized approach!*