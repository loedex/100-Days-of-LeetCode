# 🔍 Single Element in a Sorted Array – LeetCode 540 (C++)

This repository contains a C++ solution for **LeetCode Problem 540 – Single Element in a Sorted Array**.  
The problem focuses on using **Binary Search with index parity logic** to efficiently find the single non-duplicate number.

---

## 📌 Problem Statement

You are given a **sorted array** of integers where:

- Every element appears **exactly twice**
- **Only one element appears once**

### Task
Return the **single element** that appears only once.

The solution must run in **O(log n)** time and **O(1)** space.

---

## ⚙️ Approach

Since the array is sorted and all numbers except one appear twice, we can use **Binary Search** instead of linear scanning.

### Key Insight
- Pairs normally follow a pattern:
  - First occurrence at **even index**
  - Second occurrence at **odd index**
- When the single element appears, this pattern **breaks**.
- By checking index parity and neighbors, we can eliminate half of the array each step.

---

## 🧠 Algorithm Steps

1. **Edge Cases**
   - If array size is `1` → return that element.
   - If first element is unique → return it.
   - If last element is unique → return it.

2. **Binary Search**
   - Initialize `left = 0`, `right = n - 1`
   - While `left <= right`:
     - Calculate `mid`
     - If `nums[mid]` is not equal to neighbors → return it.
     - If `mid` is **odd**:
       - If equals left neighbor → move right side
       - Else → move left side
     - If `mid` is **even**:
       - If equals right neighbor → move right side
       - Else → move left side

3. Return result.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`  
- **Space Complexity:** `O(1)`

Binary Search ensures high efficiency even for very large arrays.

---

## 💻 Source Code

```cpp
class Solution{
public:
    int singleNonDuplicate(vector<int>& nums){
        if(nums.size() == 1){
            return nums[0];
        }

        if(nums[0] != nums[1]){
            return nums[0];
        }
        else if(nums[nums.size()-1] != nums[nums.size()-2]){
            return nums[nums.size()-1];
        }

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1])){
                return nums[mid];
            }
            else if(mid % 2 == 1){
                if(nums[mid] == nums[mid-1]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            else {
                if(nums[mid] == nums[mid+1]){
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

# Example : 

<b>Input : </b>

```nums = [1,1,2,3,3,4,4,8,8]```

<b>Output : </b>

```2```


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
