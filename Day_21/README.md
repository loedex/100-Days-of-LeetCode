# 🔎 Find First and Last Position of Element in a Sorted Array – LeetCode 34 (C++)

This repository contains a C++ solution for **LeetCode Problem 34 – Find First and Last Position of Element in a Sorted Array**.  
The goal is to efficiently locate the **starting and ending index** of a given target value in a sorted array using **Binary Search**.

---

## 📌 Problem Statement

Given an array of integers `nums` sorted in **non-decreasing order**, find the **first** and **last** position of a given `target`.

If the target is not found, return:


[-1, -1]


### Constraint
- Required Time Complexity: **O(log n)**

---

## ⚙️ Approach

Instead of using a linear scan, we apply **Binary Search twice**:

1. **First Binary Search → Find First Occurrence**
2. **Second Binary Search → Find Last Occurrence**

This keeps the solution efficient and within logarithmic time complexity.

---

## 🧠 Algorithm Steps

### Step 1 – Initialize
- `left = 0`
- `right = n - 1`
- Result vector initialized as `[-1, -1]`

---

### Step 2 – Find First Position
- Standard Binary Search
- When target is found:
  - Store index in `res[0]`
  - Move `right = mid - 1` to continue searching on the **left side**

---

### Step 3 – Early Exit
- If first position remains `-1`, target does not exist → return result

---

### Step 4 – Find Last Position
- Reset `left` and `right`
- When target is found:
  - Store index in `res[1]`
  - Move `left = mid + 1` to continue searching on the **right side**

---

### Step 5 – Return Result

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`  
- **Space Complexity:** `O(1)`

Two binary searches still remain logarithmic overall.

---

## 💻 Source Code

```cpp
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(2, -1);

        // First Occurrence
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                res[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        if(res[0] == -1){
            return res;
        }

        // Last Occurrence
        left = 0;
        right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                res[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return res;
    }
};
```

# Example : 

<b>Input : </b>

```nums = [5,7,7,8,8,10]```
```target = 8```

<b>Output : </b>

```[3, 4]```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast

