# 🔢 Two Sum (LeetCode 1 – C++)

This project contains a C++ solution to **LeetCode Problem 1: Two Sum**.  
The goal is to find **two indices** in an array such that their values add up to a given target.

This solution uses an **optimized hash map approach** to achieve efficient performance.

---

## 📌 Problem Description

You are given:

- An integer array `nums`
- An integer `target`

### Task:
Return the **indices of the two numbers** such that:
```
nums[i] + nums[j] = target
```

### Constraints:
- Each input has **exactly one solution**
- You may **not** use the same element twice
- The order of indices does not matter

---

## ⚙️ Solution Approach

This solution uses an **unordered_map (hash map)** to store numbers and their indices while traversing the array.

### Key Idea:
- For each element, calculate the **complement** needed to reach the target
- Check if the complement already exists in the map
- If found, return both indices immediately

This avoids the brute-force nested loop and improves efficiency.

---

## 🧠 Algorithm Steps

1. Create an empty hash map to store numbers and indices
2. Traverse the array from left to right
3. For each element:
   - Compute `complement = target - nums[i]`
   - Check if `complement` exists in the map
   - If yes, return `{index_of_complement, current_index}`
4. Store the current element and its index in the map
5. Return an empty vector if no solution is found (edge case)

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Single pass through the array)
- **Space Complexity:** `O(n)`  
  (Hash map to store elements)

---

## 💻 Source Code

```cpp
class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> mp;

            for(int i = 0; i < nums.size(); i++){
                int complement = target - nums[i];

                if(mp.find(complement) != mp.end()){
                    return {mp[complement], i};
                }

                mp[nums[i]] = i;
            }

            return {};
        }
};
```
# Example:
<b>Input: </b>
```
nums = [2, 7, 11, 15]
target = 9
```
<b>Output: </b>
```
[0, 1]
```
<b>Explanation: </b>
```nums[0] + nums[1] = 2 + 7 = 9```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
