# ⛰️ Find Peak Element – LeetCode 162 (C++)

This repository contains a C++ solution for **LeetCode Problem 162 – Find Peak Element**.  
The objective is to locate a **peak element** in an array using an efficient **Binary Search** approach.

---

## 📌 Problem Statement

A **peak element** is an element that is **greater than its neighbors**.

Given an integer array `nums`, return the **index** of any peak element.

### Conditions
- `nums[i] ≠ nums[i + 1]`
- You may imagine `nums[-1] = -∞` and `nums[n] = -∞`
- The array can have **multiple peaks** — returning **any one** is valid.
- Required Time Complexity: **O(log n)**

---

## ⚙️ Approach

Instead of scanning the entire array, we use **Binary Search** to efficiently find a peak.

### Key Idea
- If the **middle element** is greater than both neighbors → it is a peak.
- If the **right neighbor is larger**, move to the right half.
- Otherwise, move to the left half.
- Peaks always exist due to boundary conditions.

---

## 🧠 Algorithm Steps

1. **Check Edge Cases**
   - If first element is greater than second → return index `0`
   - If last element is greater than second last → return last index

2. **Binary Search**
   - Set `left = 1`, `right = n - 2`
   - While `left <= right`:
     - Find `mid`
     - If `nums[mid]` is greater than both neighbors → return `mid`
     - If right neighbor is larger → move `left = mid + 1`
     - Else → move `right = mid - 1`

3. Return index.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`  
- **Space Complexity:** `O(1)`

Binary Search ensures optimal performance even for large arrays.

---

## 💻 Source Code

```cpp
class Solution{
public:
    int findPeakElement(vector<int>& nums){
        if(nums[0] > nums[1]){
            return 0;
        }
        else if(nums[nums.size()-1] > nums[nums.size()-2]){
            return nums.size()-1;
        }
        else{
            int left = 1;
            int right = nums.size() - 2;

            while(left <= right){
                int mid = (left + right) / 2;

                if((nums[mid] > nums[mid-1]) && (nums[mid] > nums[mid+1])){
                    return mid;
                }

                if(nums[mid+1] > nums[mid]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return 0;
    }
};
```

# Example 

<b>Input : </b>

```nums = [1, 2, 3, 1]```

<b>Output : </b>

```2```

<b>Explanation : </b>

```Here 3 is greater than both neighbors.```

