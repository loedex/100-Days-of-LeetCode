# 🔢 LeetCode 69 — Sqrt(x)

## 📌 Problem Description

**Difficulty:** Easy  
**Topics:** Math, Binary Search

Given a **non-negative integer** `x`, return the **square root of x rounded down** to the nearest integer.

The returned integer must be **non-negative**.

### Important Rule

You **must not use** any built-in exponent function or operator.

Examples of disallowed operations:

```
pow(x, 0.5)
x ** 0.5
sqrt(x)
```

---

## 🧠 Example

### Input

```
x = 4
```

### Output

```
2
```

### Explanation

```
√4 = 2
```

So we return:

```
2
```

---

### Example 2

### Input

```
x = 8
```

### Output

```
2
```

### Explanation

```
√8 ≈ 2.828...
```

Rounded down:

```
2
```

---

## 🚀 Approach — Binary Search

We use **Binary Search** to efficiently find the square root.

Instead of checking every number, we search in the range:

```
0 → x
```

---

### Steps

1. Handle edge cases:

```
x = 0 or x = 1
```

Return `x`.

---

2. Apply Binary Search:

- Start = 0
- End = x

---

3. Calculate middle value:

```
mid = (start + end) / 2
```

---

4. Compare:

```
mid * mid vs x
```

Instead of multiplication (overflow risk), we use:

```
mid == x / mid
```

---

5. Adjust search range:

If:

```
mid < x/mid
```

Move right.

If:

```
mid > x/mid
```

Move left.

---

6. Store best answer:

```
k = mid
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:

    int mySqrt(int x) {

        if(x == 0 || x == 1){
            return x;
        }

        int k;

        int Min = 0;
        int Max = x;

        while(Min <= Max){

            int mid = (Min + Max)/2;

            if(mid == (x/mid)){
                return mid;
            }

            else if(mid < (x/mid)){
                k = mid;
                Min = mid+1;
            }

            else if(mid > (x/mid)){
                Max = mid-1;
            }
        }

        return k;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(log n)
```

Binary search reduces the range by half each time.

---

### Space Complexity

```
O(1)
```

Constant extra space.

---

## 🎯 Key Concepts

- Binary Search
- Math
- Integer Division
- Overflow Prevention

---

## 📚 LeetCode Problem

https://leetcode.com/problems/sqrtx/

---

## 👨‍💻 Author

Husnain Ahmad

---
