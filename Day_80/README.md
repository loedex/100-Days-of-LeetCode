# 412. FizzBuzz

[![LeetCode](https://img.shields.io/badge/LeetCode-412-orange)](https://leetcode.com/problems/fizz-buzz/)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

A clean C++ solution to the classic **FizzBuzz** problem from LeetCode.

---

## 📋 Problem Statement

Given an integer `n`, return a string array `answer` (**1-indexed**) where:

- `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
- `answer[i] == "Fizz"` if `i` is divisible by `3`.
- `answer[i] == "Buzz"` if `i` is divisible by `5`.
- `answer[i] == i` (as a string) if none of the above conditions are true.

**LeetCode link:** [https://leetcode.com/problems/fizz-buzz/](https://leetcode.com/problems/fizz-buzz/)

### Example 1

```
Input: n = 3
Output: ["1","2","Fizz"]
```

### Example 2

```
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
```

### Example 3

```
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

### Constraints

- `1 <= n <= 10^4`

---

## 💡 Approach

The solution iterates through every integer from `1` to `n` and checks the divisibility rules **in the right order**:

1. Check divisibility by both `3` and `5` first (i.e., by `15`) → `"FizzBuzz"`
2. Then check divisibility by `3` alone → `"Fizz"`
3. Then check divisibility by `5` alone → `"Buzz"`
4. Otherwise, convert the number itself to a string using `std::to_string`

Checking the combined condition (`3 && 5`) **before** the individual conditions is what makes the logic correct — if we checked `% 3` first on its own, every multiple of 15 would incorrectly get labeled `"Fizz"` instead of `"FizzBuzz"`.

A call to `answer.reserve(n)` is made upfront to pre-allocate the vector's capacity, avoiding repeated reallocations as elements are pushed in — a small but nice efficiency touch.

---

## 🔧 Code

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> answer;
        answer.reserve(n); // Reserve memory upfront for efficiency
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");
            } else if (i % 5 == 0) {
                answer.push_back("Buzz");
            } else {
                answer.push_back(std::to_string(i));
            }
        }
        return answer;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Complexity | Explanation |
|---|---|---|
| **Time**  | `O(n)` | We iterate through the numbers `1` to `n` exactly once, doing O(1) work per iteration. |
| **Space** | `O(n)` | The output vector stores `n` strings (required for the output itself; no extra auxiliary space is used). |

---


## 📚 Tags

`Array` `Math` `String` `Simulation`

---

## 📝 License

This solution is shared for educational purposes as part of a personal LeetCode practice repository.