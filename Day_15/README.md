# 📊 Median of Two Sorted Arrays (LeetCode 4 – C++)

This repository contains a C++ solution to **LeetCode Problem 4: Median of Two Sorted Arrays**.  
The goal is to find the **median value** from two individually sorted arrays without merging them.

The solution uses an **Optimal Binary Search Partition Technique** to achieve logarithmic time complexity.

---

## 📌 Problem Description

You are given **two sorted arrays** `nums1` and `nums2` of sizes `m` and `n`.

### Task:
Return the **median** of the two sorted arrays.

### Constraints:
- **Time Complexity Requirement:** `O(log (m + n))`
- **Space Complexity:** `O(1)`

You are **not allowed** to merge the arrays in a brute-force way.

---

## ⚙️ Solution Approach

Instead of merging arrays (which costs `O(m+n)`), this solution applies **Binary Search on Partitions**.

### Core Idea

- Always perform binary search on the **smaller array**
- Divide both arrays into **left** and **right halves**
- Ensure:

 max(left side) <= min(right side)

- When condition satisfies → correct partition found → compute median.

---

## 🧠 Algorithm Steps

1. **Ensure First Array is Smaller**
 - If `nums1.size() > nums2.size()` → swap arrays

2. **Binary Search Setup**
 - `low = 0`
 - `high = m` (size of smaller array)

3. **Partition Logic**
 - Choose midpoint for nums1
 - Compute remaining elements for nums2
 - Determine:
   - Left max values
   - Right min values

4. **Check Valid Partition**
 - If valid:
   - If total length is **even** → average of middle two
   - If **odd** → max of left side
 - Else adjust search range

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log(min(m, n)))`
- **Space Complexity:** `O(1)`

This is the **most optimal approach** for this problem.

---

## 💻 Source Code

```cpp
class Solution{
public:
  int medianOfSortedArrays(vector<int>& nums1, vector<int>& nums2){

      if(nums1.size() > nums2.size()){
          return medianOfSortedArrays(nums2, nums1);
      }

      int m = nums1.size();
      int n = nums2.size();

      int low = 0;
      int high = m;

      while(low <= high){
          int noOfLeftNums1 = (low + high) / 2;
          int noOfLeftNums2 = (m + n + 1) / 2 - noOfLeftNums1;

          int leftNums1  = (noOfLeftNums1 == 0) ? INT_MIN : nums1[noOfLeftNums1 - 1];
          int leftNums2  = (noOfLeftNums2 == 0) ? INT_MIN : nums2[noOfLeftNums2 - 1];

          int rightNums1 = (noOfLeftNums1 == m) ? INT_MAX : nums1[noOfLeftNums1];
          int rightNums2 = (noOfLeftNums2 == n) ? INT_MAX : nums2[noOfLeftNums2];

          if((leftNums1 <= rightNums2) && (leftNums2 <= rightNums1)){

              if(((m + n) % 2) == 0){
                  return ( max(leftNums1, leftNums2) + min(rightNums1, rightNums2) ) / 2.0;
              }
              else{
                  return max(leftNums1, leftNums2);
              }
          }
          else if(leftNums1 > rightNums2){
              high = noOfLeftNums1 - 1;
          }
          else{
              low = noOfLeftNums1 + 1;
          }
      }

      return 0;
  }
};
```

# Example :

<b>Input : </b>

```nums1 = [1,3,4,7,10,12]```
```nums2 = [2,3,6,15]```

<b>Output : </b>

```5```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
