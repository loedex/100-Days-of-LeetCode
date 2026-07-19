# 🏛️ Roman to Integer — LeetCode 13

A clean C++ solution to the classic **Roman to Integer** problem, with an explanation written for anyone learning the trick behind it.

---

## 📋 Problem

Roman numerals are represented by seven symbols:

| Symbol | Value |
|:------:|:-----:|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Given a Roman numeral as a string `s`, convert it to its integer value.

**Example 1:**
```
Input:  s = "III"
Output: 3
```

**Example 2:**
```
Input:  s = "LVIII"
Output: 58
// L = 50, V = 5, III = 3
```

**Example 3:**
```
Input:  s = "MCMXCIV"
Output: 1994
// M = 1000, CM = 900, XC = 90, IV = 4
```

---

## 🧠 The Key Idea

Normally, Roman numerals are just **added up** left to right (`VI` = `V + I` = 6).

But there's one tricky rule: if a **smaller** numeral appears **before** a **larger** one, you **subtract** the smaller one instead of adding it. This is how we get numbers like:

- `IV` = 4 (instead of writing `IIII`)
- `IX` = 9
- `XL` = 40
- `XC` = 90
- `CD` = 400
- `CM` = 900

So the whole problem boils down to one question, asked at every character:

> "Is the current numeral smaller than the one right after it?
> If yes → subtract it.
> If no → add it."

That's it. That's the entire trick. 🎉

---

## 🔍 How the Code Works

```cpp
class Solution {
public:
    int romanToInt(string s) {
        // Map to store the values of Roman numerals
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // If the current numeral is smaller than the next one, subtract it (e.g., IV, IX)
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } 
            // Otherwise, add it (e.g., VI, CX)
            else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};
```

Let's break it down piece by piece — no step skipped:

### Step 1: Build a lookup table
```cpp
unordered_map<char, int> roman = { ... };
```
This is just a dictionary that lets us instantly answer "what number does this letter represent?" — no `if/else` chains needed. `roman['X']` gives you `10` in constant time.

### Step 2: Walk through the string, one character at a time
```cpp
for (int i = 0; i < n; i++) {
```
We're going to look at each character and decide: **add it, or subtract it?**

### Step 3: Peek at the next character
```cpp
if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
```
Here's the heart of the logic. For every character, we peek one step ahead:

- `i < n - 1` — make sure we're not at the last character (so there *is* a "next" one to peek at).
- `roman[s[i]] < roman[s[i + 1]]` — compare the current value to the next value.

If the current numeral is **smaller** than the next one (like `I` before `V` in `IV`), we know we're in a subtractive pair.

### Step 4: Subtract or add
```cpp
total -= roman[s[i]];   // subtractive case, e.g. the "I" in "IV"
...
total += roman[s[i]];   // normal case
```
- If it's a subtractive pair → subtract the **current** (smaller) value.
- Otherwise → just add the current value like normal.

### 🚶 Walking through an example: `"IX"`

| i | `s[i]` | Next char | Compare              | Action        | `total` |
|---|--------|-----------|-----------------------|---------------|---------|
| 0 | `I`    | `X`       | 1 < 10 → true          | `total -= 1`  | -1      |
| 1 | `X`    | (none)    | last char, skip check  | `total += 10` | 9       |

Final answer: **9** ✅ — exactly right, since `IX` means "one before ten."

Notice the clever bit: we never explicitly detect "this is a two-letter pair like IX." We just subtract the small one and add the big one, and the math works itself out. That's the elegance of this solution!

---

## ⏱️ Complexity

| | Complexity | Why |
|---|---|---|
| **Time**  | `O(n)` | We walk through the string exactly once. |
| **Space** | `O(1)` | The lookup map always has exactly 7 entries, no matter how long `s` is. |

---

## ✅ Why This Approach Works Well

- **No hardcoded strings** like `"IV"`, `"IX"`, etc. — the subtraction logic handles all six subtractive pairs automatically.
- **Single pass** — nice and efficient, no need to scan the string twice.
- **Easy to reason about** — once you understand the "peek at the next character" trick, the code reads almost like plain English.

---

## 🚀 How to Run

```bash
g++ -std=c++17 -o roman_to_int main.cpp
./roman_to_int
```

(Make sure to add a small `main()` function with test cases if you want to run it standalone — the class above assumes it's being plugged into LeetCode's judge, which calls `romanToInt()` directly.)