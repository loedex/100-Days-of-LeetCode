# 🔢 LeetCode 136 — Single Number

## 📌 Problem Description

**Difficulty:** Easy  
**Topics:** Array, Bit Manipulation

Given a **non-empty array** of integers `nums`, every element appears **twice except for one**.

Your task is to find that **single number**.

---

### ⚠️ Constraints

- You must implement a solution with:

```
O(n) time complexity
O(1) extra space
```

---

## 🧠 Example

### Example 1

**Input**

```
nums = [2,2,1]
```

**Output**

```
1
```

---

### Example 2

**Input**

```
nums = [4,1,2,1,2]
```

**Output**

```
4
```

---

### Example 3

**Input**

```
nums = [1]
```

**Output**

```
1
```

---

## 🚀 Approach — Bit Manipulation (XOR)

We use the **XOR (^) operator** to solve this efficiently.

### 🔑 XOR Properties

```
a ^ a = 0
a ^ 0 = a
```

---

### 💡 Key Idea

- When we XOR all elements:
  - Duplicate numbers cancel each other out
  - Only the unique number remains

---

### 🧪 Example Walkthrough

```
nums = [4,1,2,1,2]

Step-by-step XOR:

result = 0
result = 0 ^ 4 = 4
result = 4 ^ 1 = 5
result = 5 ^ 2 = 7
result = 7 ^ 1 = 6
result = 6 ^ 2 = 4
```

Final result:

```
4
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:

    int singleNumber(vector<int>& nums) {

        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(n)
```

We traverse the array once.

---

### Space Complexity

```
O(1)
```

No extra space is used.

---

## 🎯 Key Concepts

- Bit Manipulation
- XOR Operation
- Efficient Array Processing
- Constant Space Optimization

---

## 📚 LeetCode Problem

https://leetcode.com/problems/single-number/

---

## 👨‍💻 Author

Husnain Ahmad

---

## ✅ Summary

✔ Uses powerful **XOR trick**  
✔ Eliminates duplicates automatically  
✔ Optimal **O(n) time & O(1) space**  
✔ Clean and elegant solution  
