# 🔍 Binary Search (LeetCode – C++)

This repository contains a C++ implementation of the **Binary Search** algorithm.  
Binary Search is an efficient searching technique used on **sorted arrays** to find the position of a target value.

---

## 📌 Problem Description

You are given a **sorted array of integers** `nums` and an integer `target`.

### Task
Return the **index** of the target if it exists in the array.  
If the target does **not** exist, return `-1`.

---

## ⚙️ Solution Approach

Binary Search works by repeatedly dividing the search space into halves.

### Core Idea
- Start with two pointers:
  - `low` → beginning of array
  - `high` → end of array
- Calculate the middle index:

mid = (low + high) / 2

- Compare `nums[mid]` with `target`:
- If equal → return index
- If target is greater → search right half
- If target is smaller → search left half

This process continues until the element is found or the search space becomes empty.

---

## 🧠 Algorithm Steps

1. Initialize `low = 0` and `high = nums.size() - 1`
2. While `low <= high`:
 - Calculate `mid`
 - If `nums[mid] == target` → return `mid`
 - If `target > nums[mid]` → move `low = mid + 1`
 - Else → move `high = mid - 1`
3. If loop ends → return `-1`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

Binary Search is significantly faster than Linear Search for large sorted datasets.

---

## 💻 Source Code

```cpp
class Solution{
public:
  int binarySearch(vector<int>& nums, int target){
      int low = 0;
      int high = nums.size() - 1;

      while(low <= high){
          int mid = (low + high) / 2;

          if(target > nums[mid]){
              low = mid + 1;
          }
          else if(target < nums[mid]){
              high = mid - 1;
          }
          else{
              return mid;
          }
      }
      return -1;
  }
};
```

# Example: 

<b>Input : </b>

```nums = [-1,0,3,5,9,12]```
```target = 2```

<b>Output : </b>

```-1```

<b>Explanation : </b>

```Target not found so we returned -1 as stated in problem statement```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast

