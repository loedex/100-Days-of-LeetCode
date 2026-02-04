# 🔢 Squares of a Sorted Array (LeetCode 977 – C++)

This project contains a C++ solution to **LeetCode Problem 977: Squares of a Sorted Array**.  
The objective is to return a new array containing the squares of each number from the input array, **sorted in non-decreasing order**.

The solution uses a **two-pointer technique** to achieve optimal time complexity without sorting again.

---

## 📌 Problem Description

You are given an integer array `nums` sorted in **non-decreasing order**.  
The array may contain **negative numbers**.

### Task:
Return an array of the squares of each number, also sorted in **non-decreasing order**.

---

## ⚙️ Solution Approach

Simply squaring each element is not enough because negative numbers can become larger when squared.

### Key Idea:
- Use **two pointers**:
  - `left` at the beginning
  - `right` at the end
- Compare the absolute values (squares) of both ends
- Insert the **larger square first**
- Reverse the result at the end to maintain sorted order

This avoids using built-in sorting and improves performance.

---

## 🧠 Algorithm Steps

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. Create an empty result vector
3. While `left <= right`:
   - Compare squares of `nums[left]` and `nums[right]`
   - Push the larger square into the result
   - Move the corresponding pointer
4. Reverse the result array
5. Return the result

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Single pass through the array)
- **Space Complexity:** `O(n)`  
  (Result array storage)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution{
    public:
        vector<int> sortedSquares(vector<int>& nums){
            int left = 0;
            int right = nums.size() - 1;
            vector<int> result;

            while(left <= right){
                if((nums[left] * nums[left]) > (nums[right] * nums[right])){
                    result.push_back(nums[left] * nums[left]);
                    left++;
                }
                else{
                    result.push_back(nums[right] * nums[right]);
                    right--;
                }
            }

            reverse(result.begin(), result.end());
            return result;
        }
};

int main(){
    vector<int> V = {-7, -3, 2, 3, 11};
    Solution obj;

    vector<int> r = obj.sortedSquares(V);

    for(auto i : r){
        cout << i << "\t";
    }

    return 0;
}
```

# Example: 
<b>Input : </b>

```nums = [-7, -3, 2, 3, 11]```

<b>Output :</b>

```[4, 9, 9, 49, 121]```

<b>Explanation :</b>

```Squares → [49, 9, 4, 9, 121]```
```Sorted  → [4, 9, 9, 49, 121]```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast