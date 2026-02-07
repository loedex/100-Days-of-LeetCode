# 🥇 Largest Number At Least Twice of Others (LeetCode 747 – C++)

This project contains a C++ solution to **LeetCode Problem 747: Largest Number At Least Twice of Others**.  
The goal is to determine whether the largest element in the array is **at least twice as large as every other number**.  
If true, return its index; otherwise, return `-1`.

The solution efficiently finds the **largest and second largest elements** in a single traversal.

---

## 📌 Problem Description

You are given an integer array `nums`.

### Task:
Return the **index of the largest number** if it is **at least twice** as large as every other number in the array.  
Otherwise, return `-1`.

---

## ⚙️ Solution Approach

Instead of sorting the array, this solution:

- Traverses the array once
- Tracks:
  - The **largest element**
  - The **second largest element**
  - The **index of the largest element**
- After traversal, checks whether the largest number is at least twice the second largest

This approach ensures optimal performance without extra memory usage.

---

## 🧠 Algorithm Steps

1. Initialize:
   - `largest = nums[0]`
   - `secondLargest = INT_MIN`
   - `largestIndex = 0`
2. Traverse the array from index `1`:
   - If current element is greater than `largest`:
     - Update `secondLargest`
     - Update `largest`
     - Update `largestIndex`
   - Else if current element is between `largest` and `secondLargest`:
     - Update `secondLargest`
3. After traversal:
   - If `largest < 2 * secondLargest` → return `-1`
   - Otherwise → return `largestIndex`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Single pass through the array)
- **Space Complexity:** `O(1)`  
  (Constant extra variables only)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>

class Solution{
    public:
        int dominantIndex(vector<int>& nums){
            int largest = nums[0];
            int secondLargest = INT_MIN;
            int largestIndex = 0;

            for(int i = 1; i < nums.size(); i++){
                if(nums[i] > largest){
                    secondLargest = largest;
                    largest = nums[i];
                    largestIndex = i;
                }
                else if((nums[i] < largest) && (nums[i] > secondLargest)){
                    secondLargest = nums[i];
                }
            }

            if(largest < (2 * secondLargest)){
                return -1;
            }

            return largestIndex;
        }
};

int main(){
    vector<int> V = {1, 0};
    Solution obj;

    cout << obj.dominantIndex(V);

    return 0;
}
```

# Example : 

<b>Input :</b>

```nums = [3, 6, 1, 0]```

<b>Output :</b>

```1```

<b>Explanation : </b>

```Largest number = 6```
```Second largest = 3```
```6 >= 2 * 3 → Condition satisfied```
```Index of 6 = 1```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast


