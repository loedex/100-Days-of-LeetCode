# 🗑️ Remove Element (LeetCode 27 – C++)

This project provides a C++ solution to **LeetCode Problem 27: Remove Element**.  
The objective is to remove all occurrences of a given value from an array **in-place** and return the new length of the modified array.

The solution uses a **two-pointer technique** to efficiently overwrite unwanted elements without using extra space.

---

## 📌 Problem Description

You are given:

- An integer array `nums`
- An integer `val`

### Task:
Remove all occurrences of `val` from the array **in-place** and return the number of remaining elements.

### Important Notes:
- The order of elements **may change**
- You **cannot** use extra space for another array
- Only the first `k` elements of the array after removal are valid

---

## ⚙️ Solution Approach

This solution uses a **pointer (index) approach**:

- Traverse the array once
- Copy only the elements that are **not equal** to `val`
- Maintain a pointer that tracks the valid position
- Return the pointer value as the new length

This avoids additional memory allocation and ensures optimal performance.

---

## 🧠 Algorithm Steps

1. Initialize `ptr = 0`
2. Traverse the array from left to right
3. If `nums[i]` is **not equal** to `val`:
   - Assign `nums[ptr] = nums[i]`
   - Increment `ptr`
4. After traversal, return `ptr` as the new array length

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Single pass through the array)
- **Space Complexity:** `O(1)`  
  (In-place modification, no extra memory)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>

class Solution{
    public:
        int removeElement(vector<int>& nums, int val){
            int ptr = 0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != val){
                    nums[ptr] = nums[i];
                    ptr++;
                }
            }

            return ptr;
        }
};

int main(){
    vector<int> V = {0,1,2,2,3,0,4,2};
    int v = 2;

    Solution obj;
    cout << obj.removeElement(V, v);

    return 0;
}
```
# Example : 
<b>Input : </b>

```nums = [0,1,2,2,3,0,4,2]```
```val = 2```

<b>Output : </b>

```5```

<b>Explanation: </b>

```After removing all 2s, the first 5 elements of the array may look like:```
```[0,1,3,0,4]```
<i>Order is not important</i>

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast