# 💡 Bulb Switcher – LeetCode 319 (C++)

This repository contains a C++ solution for **LeetCode Problem 319 – Bulb Switcher**.  
The objective is to determine how many bulbs remain ON after performing a series of toggle operations.

This solution uses a **mathematical observation** instead of simulation.

---

## 📌 Problem Statement

There are `n` bulbs initially turned **off**.

You perform `n` rounds:

- Round 1 → Toggle every bulb
- Round 2 → Toggle every 2nd bulb
- Round 3 → Toggle every 3rd bulb
- ...
- Round `n` → Toggle the nth bulb

Return the number of bulbs that remain **ON** after `n` rounds.

---

## ⚙️ Key Insight

A bulb changes state every time it is toggled.

A bulb at position `k` is toggled once for every **divisor** of `k`.

Most numbers have an **even number of divisors**, so their bulbs end up OFF.

Only **perfect squares** have an **odd number of divisors**, so they remain ON.

Therefore:

> The number of bulbs that remain ON =  
> **Number of perfect squares ≤ n**

Which equals:


⌊ sqrt(n) ⌋



---

## 🧠 Algorithm

Simply return:


sqrt(n)


No simulation required.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

This is an optimal constant-time mathematical solution.

---

## 💻 Source Code

```cpp
class Solution{
public:
    int bulbSwitch(int n){
        return sqrt(n);
    }
};
```

# Example 

<b>Input : </b>

```n = 3```

<b>Explanation : </b>

After 3 rounds:
- Bulb 1 → ON
- Bulb 2 → OFF
- Bulb 3 → OFF

<b>Output : </b>

```1```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
