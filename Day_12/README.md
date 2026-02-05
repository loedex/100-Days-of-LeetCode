# 🔍 Two Sum II – Input Array Is Sorted (LeetCode 167 – C++)

This project contains a C++ solution to **LeetCode Problem 167: Two Sum II – Input Array Is Sorted**.  
The objective is to find two numbers in a **sorted array** such that their sum equals a given target and return their **1-based indices**.

The solution uses an efficient **two-pointer technique** to achieve optimal performance.

---

## 📌 Problem Description

You are given:

- A **1-indexed** sorted integer array `numbers`
- An integer `target`

### Task:
Find two numbers such that:

numbers[i] + numbers[j] = target


Return their indices **(i, j)** where `i < j`.

### Constraints:
- The array is already sorted
- Exactly **one solution** exists
- Indices must be **1-based**, not 0-based

---

## ⚙️ Solution Approach

Since the array is sorted, we can avoid hash maps and nested loops.

### Key Idea:
- Place one pointer at the **start** and one at the **end**
- Compare their sum with the target
- Move pointers accordingly until the correct pair is found

This approach guarantees linear time complexity.

---

## 🧠 Algorithm Steps

1. Initialize:
   - `left = 0`
   - `right = n - 1`
2. While `left < right`:
   - Compute `sum = numbers[left] + numbers[right]`
   - If `sum < target` → move `left++`
   - If `sum > target` → move `right--`
   - If equal → return `{left + 1, right + 1}`
3. Return empty vector if no pair found (edge case)

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Single traversal using two pointers)
- **Space Complexity:** `O(1)`  
  (No extra data structures used)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>

class Solution{
    public:
        vector<int> twoSumII(vector<int>& numbers, int target){
            int left = 0;
            int right = numbers.size() - 1;

            while(left < right){
                if((numbers[left] + numbers[right]) < target){
                    left++;
                }
                else if((numbers[left] + numbers[right]) > target){
                    right--;
                }
                else{
                    return {left + 1, right + 1};
                }
            }

            return {};
        }
};

int main(){
    vector<int> V = {-1, 0};
    int t = -1;

    Solution obj;
    vector<int> r = obj.twoSumII(V, t);

    for(auto i : r){
        cout << i << "\t";
    }

    return 0;
}
```

# Example : 
<b>Input : </b>

```numbers = [2, 7, 11, 15]```
```target = 9```

<b>Output : </b>

```[1, 2]```

<b>Explanation : </b>

```numbers[1] + numbers[2] = 2 + 7 = 9```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast