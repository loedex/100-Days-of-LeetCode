# 🟢 LeetCode 74 – Search a 2D Matrix

**Difficulty:** Medium  
**Topics:** Array, Binary Search, Matrix

---

## 📘 Problem Statement

You are given an **m × n integer matrix** with the following properties:

1. Each row is sorted in **non-decreasing order**
2. The first integer of each row is **greater than the last integer of the previous row**

Given an integer **target**, return:

- `true` → if target exists in matrix  
- `false` → otherwise

Your solution must run in:

```
O(log(m × n))
```

---

## 🧾 Example

### Example 1

**Input**

```
matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 3
```

**Output**

```
true
```

---

### Example 2

**Input**

```
matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 13
```

**Output**

```
false
```

---

## 💡 Key Idea

The matrix behaves like a **sorted 1D array**.

Example:

```
Matrix:

1  3  5  7
10 11 16 20
23 30 34 60
```

Equivalent 1D array:

```
[1,3,5,7,10,11,16,20,23,30,34,60]
```

So we can apply:

```
Binary Search
```

---

## 🧠 Approach

### Step 1 — Treat Matrix as 1D Array

Total elements:

```
rows × columns
```

Binary search range:

```
left = 0
right = rows × columns − 1
```

---

### Step 2 — Find Middle Element

```
mid = (left + right) / 2
```

---

### Step 3 — Convert 1D Index to 2D Index

Row index:

```
i = mid / columns
```

Column index:

```
j = mid % columns
```

Access element:

```
matrix[i][j]
```

---

### Step 4 — Binary Search Decision

If:

```
target == matrix[i][j]
```

Return:

```
true
```

If:

```
target < matrix[i][j]
```

Move left:

```
right = mid - 1
```

If:

```
target > matrix[i][j]
```

Move right:

```
left = mid + 1
```

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|----------|-------|
| Time Complexity | O(log(m × n)) |
| Space Complexity | O(1) |

### Explanation

- Binary Search → O(log n)
- No extra memory → O(1)

---

## 💻 C++ Implementation

```cpp
class Solution{
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target){
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        int left = 0;
        int right = (rows * columns) - 1;
        
        while(left <= right){
            
            int mid = (left + right) / 2;
            
            // Convert 1D index to 2D index
            int i = mid / columns;
            int j = mid % columns;
            
            if(target == matrix[i][j]){
                
                return true;
            }
            else if(target < matrix[i][j]){
                
                right = mid - 1;
            }
            else{
                
                left = mid + 1;
            }
        }
        
        return false;
    }
};
```

---

## 🔎 Dry Run

### Matrix

```
1  3  5  7
10 11 16 20
23 30 34 60
```

Target:

```
3
```

---

### Step 1

```
left = 0
right = 11
```

---

### Step 2

```
mid = 5
```

Convert:

```
row = 5 / 4 = 1
col = 5 % 4 = 1
```

Element:

```
11
```

Target < 11

Move:

```
right = 4
```

---

### Step 3

```
mid = 2
```

Convert:

```
row = 2 / 4 = 0
col = 2 % 4 = 2
```

Element:

```
5
```

Target < 5

Move:

```
right = 1
```

---

### Step 4

```
mid = 0
```

Element:

```
1
```

Target > 1

Move:

```
left = 1
```

---

### Step 5

```
mid = 1
```

Element:

```
3
```

Found ✅

---

## 🚀 Why This Solution Works

✔ Uses Binary Search  
✔ Very fast  
✔ No extra memory  
✔ Clean implementation

---

## 📌 Important Notes

- Matrix must follow sorted rules
- Works for large matrices
- Uses index mapping technique

---

⭐ This problem is a classic example of applying **Binary Search on a Matrix**.


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast