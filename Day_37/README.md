# 🔢 LeetCode 367 — Valid Perfect Square

## 📌 Problem Description

**Difficulty:** Easy  
**Topics:** Math, Binary Search

Given a **positive integer** `num`, return:

```
true  → if num is a perfect square
false → otherwise
```

A **perfect square** is an integer that is the square of another integer.

In other words:

```
n = k × k
```

for some integer `k`.

---

### 🚫 Constraint

You **must not use** any built-in library function such as:

```
sqrt()
pow()
```

---

## 🧠 Example

### Input

```
num = 16
```

### Output

```
true
```

### Explanation

```
4 × 4 = 16
```

Since 4 is an integer, 16 is a perfect square.

---

### Example 2

### Input

```
num = 14
```

### Output

```
false
```

### Explanation

There is no integer whose square equals 14.

---

## 🚀 Approach — Binary Search

Instead of checking every number from `1` to `num`, we apply **Binary Search**.

### Why Binary Search?

Because:

```
Square values increase monotonically.
```

This makes it ideal for binary search.

---

## 🔍 Steps

1. Handle edge case:

```
num = 1 → return true
```

---

2. Set search range:

```
Min = 1
Max = num / 2
```

---

3. Calculate middle:

```
mid = Min + (Max - Min) / 2
```

---

4. Compare:

```
square = mid * mid
```

- If `square == num` → return true
- If `square < num` → search right
- If `square > num` → search left

---

5. If loop ends → return false

---

## 💻 C++ Solution

```cpp
class Solution{
public:

    bool isPerfectSquare(int num){

        if(num == 1){
            return true;
        }

        long long Min = 1;
        long long Max = num / 2;

        while(Min <= Max){

            long long mid = Min + (Max - Min) / 2;
            long long square = mid * mid;

            if(square == num){
                return true;
            }

            else if(square < num){
                Min = mid + 1;
            }

            else if(square > num){
                Max = mid - 1;
            }
        }

        return false;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(log n)
```

Binary search halves the range each iteration.

---

### Space Complexity

```
O(1)
```

Constant extra space used.

---

## 🎯 Key Concepts

- Binary Search
- Mathematical Reasoning
- Overflow Handling using `long long`
- Efficient Searching

---

## 📚 LeetCode Problem

https://leetcode.com/problems/valid-perfect-square/

---

## 👨‍💻 Author

Husnain Ahmad

---
 

