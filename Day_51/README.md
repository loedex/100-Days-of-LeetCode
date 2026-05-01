# 981. Time Based Key-Value Store

![LeetCode](https://img.shields.io/badge/LeetCode-981-orange?style=for-the-badge&logo=leetcode)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=for-the-badge)

---

## 📝 Problem Statement

Design a **time-based key-value data structure** that can store multiple values for the same key at different timestamps and retrieve the key's value at a certain timestamp.

Implement the `TimeMap` class:

- `TimeMap()` — Initializes the object of the data structure.
- `void set(String key, String value, int timestamp)` — Stores the key `key` with the value `value` at the given time `timestamp`.
- `String get(String key, int timestamp)` — Returns a value such that `set` was previously called with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the value associated with the **largest** `timestamp_prev`. If no such value exists, returns `""`.

---

## 📌 Example

### Example 1

```
Input:
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]

Output:
[null, null, "bar", "bar", null, "bar2", "bar2"]
```

**Explanation:**

```cpp
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar",  1);  // store key="foo", value="bar" at timestamp=1
timeMap.get("foo", 1);          // returns "bar"
timeMap.get("foo", 3);          // returns "bar" — no value at t=2 or t=3, so use t=1
timeMap.set("foo", "bar2", 4);  // store key="foo", value="bar2" at timestamp=4
timeMap.get("foo", 4);          // returns "bar2"
timeMap.get("foo", 5);          // returns "bar2" — largest timestamp_prev <= 5 is t=4
```

---

## ⚙️ Constraints

- `1 <= key.length, value.length <= 100`
- `key` and `value` consist of lowercase English letters and digits.
- `1 <= timestamp <= 10^7`
- All timestamps passed to `set` are **strictly increasing**.
- At most `2 * 10^5` calls will be made to `set` and `get`.

---

## 💡 Approach — HashMap + Binary Search

### 🗃️ Data Structure Design

```
store: unordered_map<string, vector<pair<int, string>>>
         │                       │
         │                       └─ sorted list of (timestamp, value) pairs
         └─ the key
```

Each key maps to a **vector of `(timestamp, value)` pairs**. Since the problem guarantees timestamps are **strictly increasing**, every `set()` call simply appends to the back — keeping the vector **always sorted by timestamp automatically**. This is a crucial observation!

---

### 🔍 Why Binary Search for `get()`?

The `get()` call asks:
> *"Give me the value at the largest timestamp that is still ≤ the requested timestamp."*

This is a classic **"find last element ≤ target"** problem — a perfect fit for **Binary Search**!

We use C++ STL's `upper_bound` which finds the **first element strictly greater than** the target. Then we step back one position with `prev(it)` to get the largest timestamp that is `<=` the target.

---

### 🔢 Algorithm Breakdown

#### `set(key, value, timestamp)` — O(1) amortized
```
1. Access store[key]  →  gets the vector for this key
2. push_back({timestamp, value})  →  append to the end
   (Safe because timestamps are strictly increasing → always sorted!)
```

#### `get(key, timestamp)` — O(log n)
```
1. If key not in store → return ""
2. Get the vector of (timestamp, value) pairs for this key
3. Use upper_bound to find first pair where timestamp > target
4. If upper_bound points to beginning → all timestamps are too large → return ""
5. Otherwise → step back one position with prev(it) → that's our answer
```

---

## 🧠 Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| `set()`   | O(1) amortized  | O(1) per call    |
| `get()`   | O(log n)        | O(1)             |
| **Overall** | **O(n log n)** for all calls | **O(n)** total |

> `n` = total number of `set()` calls made.  
> The strictly increasing timestamp constraint is what allows O(1) `set()` — no sorting needed!

---

## 💻 Solution (C++)

```cpp
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class TimeMap {
private:
    // Maps a string key to a vector of pairs (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        // Initialization can be left empty
    }

    void set(string key, string value, int timestamp) {
        // Because timestamps are strictly increasing, we can just push to the back.
        // Time Complexity: O(1) amortized
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // If the key doesn't exist at all, return an empty string
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& values = store[key];

        // Use upper_bound to find the first element with timestamp strictly > target
        auto it = upper_bound(values.begin(), values.end(), timestamp,
            [](int val, const pair<int, string>& p) {
                return val < p.first;
            });

        // If 'it' points to the beginning, all timestamps are > target
        if (it == values.begin()) {
            return "";
        }

        // Step back one to get the largest timestamp that is <= target
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */
```

---

## 🔍 Step-by-Step Walkthrough

Using the example: `key = "foo"`, operations in order.

### After all `set()` calls:

```
store["foo"] = [ (1, "bar"),  (4, "bar2") ]
                    index 0       index 1
```

### `get("foo", 1)`:

```
target = 1
upper_bound finds first pair where timestamp > 1  →  points to (4, "bar2") at index 1
prev(it)  →  (1, "bar")  ✅  return "bar"
```

### `get("foo", 3)`:

```
target = 3
upper_bound finds first pair where timestamp > 3  →  points to (4, "bar2") at index 1
prev(it)  →  (1, "bar")  ✅  return "bar"
```

### `get("foo", 4)`:

```
target = 4
upper_bound finds first pair where timestamp > 4  →  points to end (past index 1)
prev(it)  →  (4, "bar2")  ✅  return "bar2"
```

### `get("foo", 5)`:

```
target = 5
upper_bound finds first pair where timestamp > 5  →  points to end
prev(it)  →  (4, "bar2")  ✅  return "bar2"
```

---

## ⚠️ Edge Cases

| Scenario                                  | Expected | Reason                                              |
|-------------------------------------------|----------|-----------------------------------------------------|
| `get()` on a key that was never `set()`   | `""`     | Key not in map → return `""`                       |
| `get()` with timestamp < smallest stored  | `""`     | `upper_bound` returns `begin()` → no valid entry   |
| `get()` with exact timestamp match        | value    | `upper_bound` steps past it, `prev(it)` lands on it |
| `get()` with timestamp between two stored | earlier  | Returns value at the largest `t <= target`         |
| Single `set()` then large `get()` timestamp | value  | Only one entry, `prev(end())` returns it safely    |

---

## ✅ Submission Results

| Metric            | Value      | Beats         |
|-------------------|------------|---------------|
| Runtime           | 35 ms      | 🚀 **92.08%** |
| Memory            | 136.50 MB  | 🚀 **93.40%** |
| Test Cases Passed | 54 / 54    | ✅ All Passed |

> Both runtime **and** memory in the top ~93% — an exceptionally balanced solution! 💪

---

## 🔗 Problem Link

[LeetCode 981 — Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)

---

> 💬 *Feel free to open an issue or pull request if you have a more optimized approach!*