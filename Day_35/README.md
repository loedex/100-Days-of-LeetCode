# 🔄 LeetCode 832 — Flipping an Image

## 📌 Problem Description

**Difficulty:** Easy  
**Topics:** Array, Matrix

Given an **n × n binary matrix** `image`, flip the image **horizontally**, then **invert** it, and return the resulting image.

### Flip Horizontally
Flipping horizontally means reversing each row.

Example:

```
[1,1,0] → [0,1,1]
```

---

### Invert Image
Invert means:

```
0 → 1
1 → 0
```

Example:

```
[0,1,1] → [1,0,0]
```

---

## 🧠 Example

### Input

```
image = [
 [1,1,0],
 [1,0,1],
 [0,0,0]
]
```

### Output

```
[
 [1,0,0],
 [0,1,0],
 [1,1,1]
]
```

### Explanation

Step 1 — Flip Horizontally

```
[
 [0,1,1],
 [1,0,1],
 [0,0,0]
]
```

Step 2 — Invert Image

```
[
 [1,0,0],
 [0,1,0],
 [1,1,1]
]
```

---

## 🚀 Approach

Instead of flipping first and then inverting, we combine both operations into **one pass**.

### Steps

1. Traverse each row
2. Use two pointers:
   - `left`
   - `right`
3. Swap elements
4. Invert simultaneously

### Logic

```
left element  = 1 - right element
right element = 1 - left element
```

This makes the solution efficient.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int n = image.size() - 1;

        for(int i = 0; i <= n; i++) {

            int left = 0;
            int right = n;

            while(left <= right) {

                int temp = image[i][left];

                image[i][left] = 1 - image[i][right];
                image[i][right] = 1 - temp;

                left++;
                right--;
            }
        }

        return image;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(n²)
```

Every element is processed once.

---

### Space Complexity

```
O(1)
```

In-place modification.

---

## 🎯 Key Concepts

- Matrix Traversal
- Two Pointers
- In-place Algorithm
- Binary Inversion

---

## 📚 LeetCode Problem

https://leetcode.com/problems/flipping-an-image/

---


## ✅ Summary

✔ One-pass solution  
✔ In-place modification  
✔ Efficient approach  
✔ Beginner friendly problem


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast