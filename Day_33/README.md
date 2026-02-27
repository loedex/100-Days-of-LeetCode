# 🟢 LeetCode 1572 – Matrix Diagonal Sum

**Difficulty:** Easy  
**Topics:** Array, Matrix  

---

## 📘 Problem Statement

Given a **square matrix `mat`**, return the **sum of the matrix diagonals**.

You must include:

- All elements in the **primary diagonal**
- All elements in the **secondary diagonal**
- But **do not count the middle element twice** (if matrix size is odd)

---

## 🧾 Definitions

### Primary Diagonal

Elements where:

```
row index == column index
```

Example:

```
mat[i][i]
```

---

### Secondary Diagonal

Elements where:

```
row + column = n - 1
```

Example:

```
mat[i][n-1-i]
```

---

## 💡 Key Idea

For every row `i`:

### Add Primary Diagonal Element

```
mat[i][i]
```

### Add Secondary Diagonal Element

```
mat[i][n-1-i]
```

### Avoid Double Counting

If matrix size is odd:

Middle element belongs to both diagonals.

So count it **only once**.

Condition:

```
i != n-1-i
```

---

## 🧠 Approach

### Step 1

Loop through rows:

```
i = 0 → n-1
```

---

### Step 2

Add:

```
Primary diagonal → mat[i][i]
```

---

### Step 3

Add:

```
Secondary diagonal → mat[i][n-1-i]
```

Only if:

```
i != n-1-i
```

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|----------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

### Explanation

- Single loop → O(n)
- No extra memory → O(1)

---

## 💻 C++ Implementation

```cpp
class Solution{
public:

    int diagonalSum(vector<vector<int>>& mat){
        
        int sum = 0;
        int columns = mat[0].size();
        
        for(int i = 0; i < mat.size(); i++){
            
            // Primary diagonal
            sum += mat[i][i];
            
            // Secondary diagonal
            if(i != (columns - 1 - i)){
                
                sum += mat[i][columns - 1 - i];
            }
        }
        
        return sum;
    }
};
```

---

## 🔎 Example

### Example 1

**Input**

```
mat =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

---

**Primary Diagonal**

```
1 + 5 + 9 = 15
```

---

**Secondary Diagonal**

```
3 + 5 + 7 = 15
```

---

**Middle Element Counted Once**

```
5 counted once
```

---

**Output**

```
25
```

---

## 🧾 Step-by-Step Calculation

Matrix:

```
1 2 3
4 5 6
7 8 9
```

Primary diagonal:

```
1 + 5 + 9
```

Secondary diagonal:

```
3 + 7
```

Total:

```
1 + 5 + 9 + 3 + 7 = 25
```

---

## 🚀 Why This Solution Works

✔ Simple logic  
✔ Single loop solution  
✔ No extra memory  
✔ Fast execution  

---

## 📌 Important Notes

- Matrix is always **square**
- Middle element counted once
- Works for both:

  - Odd size matrix
  - Even size matrix

---

⭐ A clean matrix problem that teaches **diagonal indexing techniques**.


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast