# 🟢 LeetCode 1491 – Average Salary Excluding the Minimum and Maximum Salary

**Difficulty:** Easy  
**Topics:** Array, Sorting, Math  

---

## 📘 Problem Statement

You are given an array of **unique integers** `salary` where:

- `salary[i]` represents the salary of the *i-th* employee.
- All salary values are unique.

Your task is to:

> Return the **average salary excluding the minimum and maximum salary**.

The answer will be accepted if it is within **10⁻⁵** of the actual value.

---

## 💡 Key Insight

To calculate the required average:

1. Find the **minimum salary**
2. Find the **maximum salary**
3. Calculate the **sum of all salaries**
4. Subtract minimum and maximum
5. Divide by remaining number of employees

Formula:

Average = (Total Sum − Min − Max) / (n − 2)

---

## 🧠 Approach

1. Initialize:
   - `sum = 0`
   - `minimum = salary[0]`
   - `maximum = salary[0]`

2. Traverse the array:
   - Add each salary to sum
   - Update minimum
   - Update maximum

3. Subtract minimum and maximum from sum.

4. Divide by `(n − 2)`.

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|-----------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(1) |

---

## 💻 C++ Implementation

```cpp
class Solution{
public:
    double averageSalary(vector<int>& salary){
        
        double sum = 0;
        int minimum = salary[0];
        int maximum = salary[0];
        
        for(int i = 0; i < salary.size(); i++){
            
            sum += salary[i];
            
            if(salary[i] > maximum){
                maximum = salary[i];
            }
            
            if(salary[i] < minimum){
                minimum = salary[i];
            }
        }
        
        sum = sum - minimum;
        sum = sum - maximum;
        
        sum = sum / (salary.size() - 2);
        
        return sum;
    }
};
```

---

## 🔎 Example

### Example 1

**Input**
```
salary = [4000,3000,1000,2000]
```

**Output**
```
2500.00000
```

**Explanation**

Minimum salary = 1000  
Maximum salary = 4000  

Remaining salaries:

```
2000 + 3000 = 5000
```

Average:

```
5000 / 2 = 2500
```

---

## 🚀 Why This Solution Works

✔ Single pass through the array  
✔ Constant extra space  
✔ Efficient calculation  
✔ Handles all valid inputs  

---

## 📌 Important Notes

- Salaries are **unique**
- Minimum and maximum must be excluded
- At least **3 employees** exist

---

⭐ A simple problem that strengthens understanding of array traversal and basic mathematical operations.


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast