# 🧹 Remove Duplicates from Sorted Array II – LeetCode 80 (C++)

This repository contains a C++ solution for **LeetCode Problem 80 – Remove Duplicates from Sorted Array II**.  
The objective is to remove duplicates **in-place** such that each element appears **at most twice**, and return the new length of the array.

---

## 📌 Problem Statement

Given a sorted integer array `nums`, remove the duplicates **in-place** so that each unique element appears **no more than two times**.

Return the number of valid elements `k`.  
The first `k` elements of the array should contain the updated result.

### Constraints
- Do not use extra space
- Maintain the original order
- Modify array directly

---

## ⚙️ Approach – Two Pointer Technique

Since the array is sorted, duplicates appear consecutively.  
We allow **at most two occurrences** of each number.

### Key Idea
- First two elements are always valid.
- Start checking from index `2`.
- Compare the current element with the element **two positions before**.
- If they are different → it means the current number has appeared less than twice, so keep it.

---

## 🧠 Algorithm Steps

1. If array size is `1` → return `1`
2. Initialize two pointers:
   - `i = 2` → position to place next valid element
   - `j = 2` → traversal pointer
3. While `j < nums.size()`:
   - If `nums[j] != nums[i - 2]`:
     - Place `nums[j]` at `nums[i]`
     - Increment `i`
   - Always increment `j`
4. Return `i` as the new length

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`

Only one pass and no extra memory used.

---

## 💻 Source Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 1){
            return 1;
        }

        int i = 2;
        int j = 2;

        while(j < nums.size()){
            if(nums[j] != nums[i - 2]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        return i;
    }
};
```

# Example : 

<b>Input : </b>

```nums = [1,1,1,2,2,3]```

<b>Output : </b>

```5```
```nums = [1,1,2,2,3,_]```


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast


