# 🎨 Sort Colors – LeetCode 75 (C++)

This repository contains a C++ solution for **LeetCode Problem 75 – Sort Colors**.  
The objective is to sort an array containing only `0`, `1`, and `2` in **linear time** without using built-in sorting functions.

This solution uses the famous **Dutch National Flag Algorithm**.

---

## 📌 Problem Statement

You are given an array `nums` with `n` objects colored:

- `0` → Red  
- `1` → White  
- `2` → Blue  

Sort them **in-place** so that objects of the same color are adjacent and ordered as:


0 → 1 → 2


### Constraints
- Do not use built-in sort
- Must run in **O(n)** time
- Must use **O(1)** extra space

---

## ⚙️ Approach – Dutch National Flag Algorithm

We maintain **three pointers**:

- `low` → position for next `0`
- `mid` → current element under inspection
- `high` → position for next `2`

### Logic
- If `nums[mid] == 0`  
  Swap with `low`, move both `low` and `mid`
- If `nums[mid] == 1`  
  Just move `mid`
- If `nums[mid] == 2`  
  Swap with `high`, decrease `high` only

This ensures all values are placed correctly in **one traversal**.

---

## 🧠 Algorithm Steps

1. Initialize:


low = 0
mid = 0
high = n - 1


2. While `mid <= high`:
- If value is `0` → swap with `low`, increment both
- If value is `1` → increment `mid`
- If value is `2` → swap with `high`, decrement `high`
3. Array becomes sorted automatically.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`

Only one pass and no extra memory used.

---

## 💻 Source Code

```cpp
class Solution{
public:
 vector<int> sortColors(vector<int>& nums){
     int low = 0;
     int mid = 0;
     int high = nums.size() - 1;

     while(mid <= high){
         if(nums[mid] == 2){
             swap(nums[mid], nums[high]);
             high--;
         }
         else if(nums[mid] == 0){
             swap(nums[mid], nums[low]);
             mid++;
             low++;
         }
         else{
             mid++;
         }
     }
     return nums;
 }
};
```

# Example : 

<b>Input : </b>

```nums = [2,0,2,1,1,0]```

<b>Output : </b>

```[0,0,1,1,2,2]```


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast


