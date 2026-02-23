# 🟢 LeetCode 66 – Plus One

**Difficulty:** Easy  
**Topics:** Array, Math  

---

## 📘 Problem Statement

You are given a **large integer** represented as an integer array `digits`, where:

- Each element represents a single digit.
- The digits are stored in **most significant to least significant** order.
- The integer does not contain any leading zeros.

Your task is to **increment the integer by one** and return the resulting array of digits.

---

## 💡 Key Insight

When adding 1 to a number:

- If the last digit is **less than 9**, simply increment it.
- If the digit is **9**, it becomes `0` and generates a carry.
- If all digits are `9`, we need to add a new digit at the beginning.

Example:

- `129 + 1 = 130`
- `999 + 1 = 1000`

So we simulate the addition from **right to left**, just like manual addition.

---

## 🧠 Approach

1. Traverse the array from the **last index to the first**.
2. If `digits[i] < 9`:
   - Increment it.
   - Return immediately (no further carry needed).
3. If `digits[i] == 9`:
   - Set it to `0` (carry forward).
4. If all digits were `9`:
   - Insert `1` at the beginning.

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|------------|--------|
| Time       | O(n)   |
| Space      | O(1) (ignoring output) |

---

## 💻 C++ Implementation

```cpp
class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        for(int i = digits.size()-1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

---

## 🔎 Example

### Example 1

**Input**
```
digits = [1,2,3]
```

**Output**
```
[1,2,4]
```

**Explanation**  
123 + 1 = 124

---

### Example 2

**Input**
```
digits = [9,9,9]
```

**Output**
```
[1,0,0,0]
```

**Explanation**  
999 + 1 = 1000

---

## 🚀 Why This Solution Works

✔ Simulates real-life addition  
✔ Handles carry efficiently  
✔ Covers edge case (all 9s)  
✔ Linear time complexity  

---

⭐ A classic array manipulation problem that strengthens understanding of carry handling and edge cases.


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast