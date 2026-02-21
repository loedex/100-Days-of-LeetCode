# 📈 Increasing Triplet Subsequence – LeetCode 334 (C++)

This repository contains a C++ solution for **LeetCode Problem 334 – Increasing Triplet Subsequence**.  
The goal is to determine whether the array contains an **increasing subsequence of length 3**.

This solution uses a **Greedy + Tracking Minimums** approach for optimal efficiency.

---

## 📌 Problem Statement

Given an integer array `nums`, return:

- `true` → if there exists a triplet `(i, j, k)` such that  


i < j < k
nums[i] < nums[j] < nums[k]


- `false` → otherwise

### Constraint
- Time complexity should be **O(n)**
- Space complexity should be **O(1)**

---

## ⚙️ Approach – Greedy Tracking

Instead of checking all possible triplets (`O(n³)` or `O(n²)`), we track:

- `first` → smallest number seen so far
- `second` → smallest number greater than `first`

If we find a number greater than both `first` and `second`, we have found a valid increasing triplet.

---

## 🧠 Algorithm Steps

1. Initialize:


first = INT_MAX
second = INT_MAX

2. Traverse the array:
- If current number ≤ `first` → update `first`
- Else if current number ≤ `second` → update `second`
- Else → return `true` (triplet found)
3. If loop finishes → return `false`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

Single pass with constant extra memory.

---

## 💻 Source Code

```cpp
class Solution{
public:
 bool increasingTriplet(vector<int>& nums){
     int first = INT_MAX;
     int second = INT_MAX;

     for(int i = 0; i < nums.size(); i++){

         if(nums[i] <= first){
             first = nums[i];
         }
         else if(nums[i] <= second){
             second = nums[i];
         }
         else{
             return true;
         }
     }

     return false;
 }
};
```

# Example 

<b>Input : </b>

```nums = [1,2,3,4,5]```

<b>Output : </b>

```true```


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast

