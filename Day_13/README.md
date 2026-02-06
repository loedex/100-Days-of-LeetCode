# ✖️ Product of Array Except Self (LeetCode 238 – C++)

This project contains a C++ solution to **LeetCode Problem 238: Product of Array Except Self**.  
The objective is to return an array such that each element at index `i` is equal to the **product of all elements of the array except `nums[i]`**.

The solution avoids division and uses **prefix and suffix products** for optimal efficiency.

---

## 📌 Problem Description

You are given an integer array `nums`.

### Task:
Return an array `answer` where:

answer[i] = product of all elements of nums except nums[i]


### Constraints:
- Division operator is **not allowed**
- The solution must run in **O(n)** time
- Extra space usage should be minimized

---

## ⚙️ Solution Approach

The optimal approach is to calculate:

- **Prefix Product** → Product of all elements to the left of index `i`
- **Suffix Product** → Product of all elements to the right of index `i`

By multiplying prefix and suffix values for each index, we get the desired result without division.

---

## 🧠 Algorithm Steps

1. Create an `answer` vector initialized with `1`s
2. Traverse from left to right:
   - Store prefix product at each index
   - Update prefix product
3. Traverse from right to left:
   - Multiply suffix product with existing value in `answer`
   - Update suffix product
4. Return the final `answer` array

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Two linear traversals)
- **Space Complexity:** `O(1)` extra space  
  (Ignoring output array)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>

class Solution{
    public:
        vector<int> productExceptSelf(vector<int>& nums){
            int n = nums.size();
            vector<int> answer(n, 1);

            // Calculate Prefix Product
            int prefixProduct = 1;
            for(int i = 0; i < n; i++){
                answer[i] = prefixProduct;
                prefixProduct *= nums[i];
            }

            // Calculate Suffix Product
            int suffixProduct = 1;
            for(int i = n - 1; i >= 0; i--){
                answer[i] *= suffixProduct;
                suffixProduct *= nums[i];
            }

            return answer;
        }
};

int main(){
    vector<int> V = {-1, 1, 0, -3, 3};
    Solution obj;

    vector<int> r = obj.productExceptSelf(V);

    for(auto i : r){
        cout << i << "\t";
    }

    return 0;
}
```

# Example : 

<b>Input :</b>

```nums = [1, 2, 3, 4]```

<b>Output :</b>

```[24, 12, 8, 6]```

<b>Explanation : </b>


```Index 0 → 2*3*4 = 24```
```Index 1 → 1*3*4 = 12```
```Index 2 → 1*2*4 = 8```
```Index 3 → 1*2*3 = 6```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
