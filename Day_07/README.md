# ➕ Add to Array-Form of Integer (LeetCode 989 – C++)

This project contains a C++ solution to **LeetCode Problem 989: Add to Array-Form of Integer**.  
The task is to add an integer `k` to a number represented in **array form** and return the resulting number, also in array form.

This solution simulates **manual digit-by-digit addition** from right to left, similar to how we add numbers on paper.

---

## 📌 Problem Description

The **array-form of an integer** is an array representing its digits from left to right.

### Example:

```num = [1, 3, 2, 1]``` → represents the number 1321


You are given:
- An integer array `num` (array-form of a number)
- An integer `k`

### Task:
Return the **array-form** of the integer `num + k`.

---

## ⚙️ Solution Approach

Instead of converting the array into a large integer (which may overflow), this solution:

- Starts adding digits from the **end of the array**
- Adds digits of `k` one by one
- Maintains a `carry` just like normal addition
- Stores the result in reverse order and then reverses it

This approach is **safe, efficient, and scalable**.

---

## 🧠 Algorithm Steps

1. Initialize:
   - An empty result vector
   - `carry = 0`
   - Index `i` pointing to the last digit of `num`
2. While there are digits left in `num` or `k`:
   - Extract digit from `num` (if available)
   - Extract last digit of `k`
   - Add both digits with `carry`
   - Store `sum % 10` in result
   - Update `carry`
3. If `carry` remains, append it
4. Reverse the result vector
5. Return the final array-form number

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Where `n` is the number of digits in `num` or `k`)
- **Space Complexity:** `O(n)`  
  (To store the result digits)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution{
    public:
        vector<int> addToArrayForm(vector<int>& num, int k){
            vector<int> result;
            int carry = 0;
            int i = num.size() - 1;

            while(i >= 0 || k > 0){
                int digitFromNum = (i >= 0) ? num[i] : 0;
                int digitFromK = k % 10;

                int sum = digitFromNum + digitFromK + carry;

                result.push_back(sum % 10);
                carry = sum / 10;

                k = k / 10;
                i--;
            }

            if(carry > 0){
                result.push_back(carry);
            }

            reverse(result.begin(), result.end());
            return result;
        }
};

int main(){
    vector<int> V = {2, 1, 5};
    Solution obj;

    vector<int> r = obj.addToArrayForm(V, 806);

    for(auto i : r){
        cout << i << "\t";
    }

    return 0;
}
```
# Example: 
<b>Input: </b>

```num = [1,2,0,0]```
```k = 34```

<b>Output: </b>

```[1,2,3,4]```

<b>Explanation: </b>

```1200 + 34 = 1234```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast

