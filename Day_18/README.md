# 🔢 Power of Three – LeetCode 326 (C++)

This repository contains a C++ solution for **LeetCode Problem 326 – Power of Three**.  
The goal is to determine whether a given integer `n` is a power of **3** without using loops or recursion.

---

## 📌 Problem Statement

Given an integer `n`, return **true** if it is a power of **three**, otherwise return **false**.

A number is considered a power of three if:

n = 3^k where k >= 0


---

## ⚙️ Approach

Instead of repeatedly dividing by 3 or using recursion, this solution uses a **mathematical optimization trick**.

### Key Idea
- The largest power of 3 that fits in a **32-bit signed integer** is:

3^19 = 1162261467


- Any number `n` that is a power of 3 must **perfectly divide** this value.
- So if `1162261467 % n == 0`, then `n` is a power of three.

This avoids loops and keeps the solution extremely efficient.

---

## 🧠 Algorithm Steps

1. If `n <= 0` → return `false`
2. Store the maximum power of 3 in 32-bit integer:


x = 1162261467

3. Check:
- If `x % n == 0` → return `true`
- Else → return `false`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(1)`  
- **Space Complexity:** `O(1)`

This is a **constant-time** mathematical solution.

---

## 💻 Source Code

```cpp
class Solution{
public:
 bool Find(int n);
};

bool Solution::Find(int n){
 if(n <= 0){
     return false;
 }

 int x = 1162261467;   // 3^19 (largest power of 3 in 32-bit int)

 if(x % n == 0){
     return true;
 }
 return false;
}

```

# Example : 

<b>Input : </b>

```n = 27```

<b>Output : </b>

```true```


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast

