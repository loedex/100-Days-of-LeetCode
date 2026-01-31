# ✖️ Maximum Product of Two Elements in an Array (LeetCode 1464 – C++)

This project presents a C++ solution to **LeetCode Problem 1464: Maximum Product of Two Elements in an Array**.  
The goal is to find two **distinct elements** in the array such that the value  
`(nums[i] - 1) * (nums[j] - 1)` is maximized.

This solution efficiently finds the **largest and second-largest elements** in a single traversal.

---

## 📌 Problem Description

You are given an integer array `nums`.

### Task:
Choose two different indices `i` and `j` such that:

```(nums[i] - 1) * (nums[j] - 1)```

is **maximum**, and return that value.

---

## ⚙️ Solution Approach

Instead of sorting the array, this solution:

- Traverses the array once
- Keeps track of:
  - The **largest** element
  - The **second-largest** element
- Computes the product using these two values

This approach is faster and more memory-efficient than sorting.

---

## 🧠 Algorithm Steps

1. Initialize:
   - `largest = 0`
   - `secondLargest = -1`
2. Traverse the array:
   - If current element is greater than `largest`:
     - Update `secondLargest`
     - Update `largest`
   - Else if current element is between `largest` and `secondLargest`:
     - Update `secondLargest`
3. Compute:

   ```(largest - 1) * (secondLargest - 1)```

   4. Return the result

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
(Single pass through the array)
- **Space Complexity:** `O(1)`  
(Only constant extra variables used)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>

class Solution{
 public:
     int maxProduct(vector<int>& nums){
         int largest = 0;
         int secondLargest = -1;

         for(int i = 0; i <= nums.size() - 1; i++){
             if(nums[i] > largest){
                 secondLargest = largest;
                 largest = nums[i];
             }
             else if((nums[i] <= largest) && (nums[i] > secondLargest)){
                 secondLargest = nums[i];
             }
         }

         cout << "Largest : " << largest << endl;
         cout << "secondLargest : " << secondLargest << endl;

         return ((largest - 1) * (secondLargest - 1));
     }
};

int main(){
 vector<int> V = {3, 4, 5, 2};
 Solution obj;

 int r = obj.maxProduct(V);

 cout << "Maximum Product : " << r;
 return 0;
}
```
# Example
<b>Input : </b>

```nums = [3, 4, 5, 2]```

<b>Output: </b>

```Maximum Product : 12```

<b>Explanation: </b>

```Largest elements: 5 and 4```
```(5 - 1) * (4 - 1) = 4 * 3 = 12```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast