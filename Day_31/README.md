# 🟢 LeetCode 48 – Rotate Image

**Difficulty:** Medium  
**Topics:** Array, Matrix, Simulation  

---

## 📘 Problem Statement

You are given an **n × n 2D matrix** representing an image.

Your task is to:

> Rotate the image by **90 degrees clockwise**.

### ⚠️ Important Rules

- Rotation must be done **in-place**
- Do **not use extra matrix**
- Modify the original matrix directly

---

## 💡 Key Insight

A **90° clockwise rotation** of a matrix can be achieved in **two steps**:

### Step 1 → Transpose the Matrix

Convert rows into columns.

Example:

```
1 2 3        1 4 7
4 5 6   →    2 5 8
7 8 9        3 6 9
```

---

### Step 2 → Reverse Each Row

```
1 4 7        7 4 1
2 5 8   →    8 5 2
3 6 9        9 6 3
```

This produces a **90° clockwise rotation**.

---

## 🧠 Approach

### Step 1: Transpose Matrix

Swap:

```
matrix[i][j] ↔ matrix[j][i]
```

Only swap where:

```
j > i
```

This avoids duplicate swaps.

---

### Step 2: Reverse Each Row

Reverse every row:

```
reverse(row.begin(), row.end())
```

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|----------|-------|
| Time Complexity | O(n²) |
| Space Complexity | O(1) |

### Explanation

- Every element visited once → O(n²)
- No extra memory used → O(1)

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();

        // Step 1: Transpose Matrix
        for(int i = 0; i < rows; i++){
            
            for(int j = i + 1; j < columns; j++){
                
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse Each Row
        for(auto& row : matrix){
            
            reverse(row.begin(), row.end());
        }
    }
};
```

---

## 🔎 Example

### Example 1

**Input**

```
matrix =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

---

**Output**

```
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]
```

---

## 🧾 Step-by-Step Visualization

### Original Matrix

```
1 2 3
4 5 6
7 8 9
```

---

### After Transpose

```
1 4 7
2 5 8
3 6 9
```

---

### After Row Reverse

```
7 4 1
8 5 2
9 6 3
```

---

## 🚀 Why This Solution Works

✔ No extra memory used  
✔ Efficient matrix manipulation  
✔ Clean logic  
✔ Interview-friendly approach  

---

## 📌 Important Notes

- Matrix is always **square (n × n)**
- Must rotate **in-place**
- No additional matrix allowed

---

⭐ A classic matrix problem that teaches **transpose and reverse techniques**.

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast