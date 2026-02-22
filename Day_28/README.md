# 🟢 LeetCode 2089 – Find Target Indices After Sorting Array

**Difficulty:** Easy  
**Topics:** Array, Sorting, Counting  

---

## 📘 Problem Statement

Given an integer array `nums` and an integer `target`, return a list of the indices of `target` after sorting `nums` in non-decreasing order.

- The returned list must be sorted in increasing order.
- If `target` does not exist in the array, return an empty list.

---

## 💡 Key Insight

Instead of actually sorting the array (which would take **O(n log n)** time), we can solve this in **O(n)** using counting.

After sorting:

- All elements **less than `target`** will appear first.
- Then all elements **equal to `target`** will appear consecutively.

So:

- First index of `target` = number of elements `< target`
- Total indices = number of elements `== target`

---

## 🧠 Approach

1. Traverse the array once.
2. Count:
   - `lessCount` → elements smaller than `target`
   - `equalCount` → elements equal to `target`
3. If `equalCount == 0`, return empty vector.
4. Generate indices from:
   
   ```
   lessCount → lessCount + equalCount - 1
   ```
5. Return the result.

---

## ⏱️ Time & Space Complexity

| Complexity | Value |
|------------|--------|
| Time       | O(n)   |
| Space      | O(k) (k = frequency of target) |

---

## 💻 C++ Implementation

```cpp
class Solution{
public:
    vector<int> targetIndices(vector<int>& nums, int target){
        
        int lessCount = 0;
        int equalCount = 0;
        
        for(int i : nums){
            if(i < target){
                lessCount++;
            }
            if(i == target){
                equalCount++;
            }
        }
        
        if(equalCount == 0){
            return {};
        }
        
        vector<int> result;
        for(int i = 0; i < equalCount; i++){
            result.push_back(lessCount + i);
        }
        
        return result;
    }
};
```

---

## 🔎 Example

### Input
```
nums = [1,2,5,2,3]
target = 2
```

### Sorted Array
```
[1,2,2,3,5]
```

### Output
```
[1,2]
```

### Explanation

- There is **1 element smaller than 2**
- `2` appears **2 times**
- So indices → `1` and `2`

---

## 🚀 Why This Solution is Efficient

✔ No sorting required  
✔ Linear time complexity  
✔ Clean counting logic  
✔ Interview-friendly optimization  

---

⭐ A great example of solving a “sorting-based” problem without actually sorting.


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast