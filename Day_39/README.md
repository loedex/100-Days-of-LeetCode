# 🪜 LeetCode 70 — Climbing Stairs

## 📌 Problem Description

**Difficulty:** Easy  
**Topics:** Dynamic Programming, Math

You are climbing a staircase. It takes **`n` steps** to reach the top.

Each time you can climb either:

```
1 step
or
2 steps
```

Your task is to calculate **how many distinct ways** you can reach the top.

---

## 🧠 Example

### Example 1

**Input**

```
n = 2
```

**Output**

```
2
```

**Explanation**

There are two ways to reach the top:

```
1. 1 step + 1 step
2. 2 steps
```

---

### Example 2

**Input**

```
n = 3
```

**Output**

```
3
```

**Explanation**

```
1. 1 + 1 + 1
2. 1 + 2
3. 2 + 1
```

---

## 🚀 Approach — Dynamic Programming

This problem follows the **Fibonacci pattern**.

To reach step `n`, you can:

```
1. Come from step (n - 1)
2. Come from step (n - 2)
```

Therefore:

```
ways(n) = ways(n-1) + ways(n-2)
```

Instead of using recursion, we store only the **last two values** to optimize space.

---

## 🔍 Steps

1. Handle base cases:

```
n <= 2 → return n
```

2. Track previous two values:

```
prev2 → ways to reach (n-2)
prev1 → ways to reach (n-1)
```

3. Compute current value:

```
curr = prev1 + prev2
```

4. Update values and continue.

---

## 💻 C++ Solution

```cpp
#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:

    int climbStairs(int n){

        if(n <= 2){
            return n;
        }

        int prev2 = 1;
        int prev1 = 2;

        for(int i = 3; i <= n; i++){

            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main(){

    Solution obj;

    cout << endl << obj.climbStairs(4);

    return 0;
}
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(n)
```

We iterate once from `3 → n`.

---

### Space Complexity

```
O(1)
```

Only two variables are used.

---

## 🎯 Key Concepts

- Dynamic Programming
- Fibonacci Pattern
- Space Optimization
- Iterative Solution

---

## 📚 LeetCode Problem

https://leetcode.com/problems/climbing-stairs/

---

## 👨‍💻 Author

Husnain Ahmad

---

## ✅ Summary

✔ Classic **Dynamic Programming** problem  
✔ Optimized **O(1) space solution**  
✔ Based on **Fibonacci sequence**  
✔ Efficient and beginner-friendly
