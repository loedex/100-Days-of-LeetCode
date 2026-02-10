# 🔎 Search Insert Position – LeetCode 35 (C++)

This repository contains a C++ implementation of **LeetCode Problem 35 – Search Insert Position**.  
The problem focuses on applying **Binary Search** to determine either the position of a target element or the index where it should be inserted in a sorted array.

---

## 📌 Problem Statement

You are given a **sorted array of distinct integers** `nums` and a `target` value.

### Task
- Return the **index** if the target is found.
- If not found, return the **index where it would be inserted** in order.

The algorithm must run in **O(log n)** time.

---

## ⚙️ Approach

The solution uses **Binary Search** because the array is already sorted.

### Core Logic
- Maintain two pointers:
  - `left` → start of array
  - `right` → end of array
- Repeatedly divide the search range in half.
- If the element is found → return its index.
- If not found → determine the correct insertion position based on comparisons.

---

## 🧠 Algorithm Steps

1. Initialize:
   - `left = 0`
   - `right = size - 1`
2. While `left <= right`:
   - Calculate `mid = (left + right) / 2`
   - If `target == V[mid]` → return `mid`
   - If only one element left:
     - If `target < V[left]` → return `left`
     - Else → return `right + 1`
   - If `target < V[mid]` → search left half
   - Else → search right half
3. Return `0` as default fallback.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`  
- **Space Complexity:** `O(1)`

Binary Search ensures efficiency even for large datasets.

---

## 💻 Source Code

```cpp
class Solution{
public:
    int Find(vector<int>&V,int target);
};

int Solution::Find(vector<int>&V,int target){
    int left,right,mid;
    left=0;
    right=V.size()-1;

    while(left<=right){
        mid=(left+right)/2;

        if(target==V[mid]){
            return mid;
        }
        else if(left==right){
            if(target<V[left]){
                return left;
            }
            else{
                return right+1;
            }
        }
        else if(target<V[mid]){
            right=mid-1;
        }
        else if(target>V[mid]){
            left=mid+1;
        }
    }
    return 0;
}
```

# Example 

<b>Input : </b>

```nums = [1,3,5,6]```
```target = 5```

<b>Output : </b>

```2```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast

