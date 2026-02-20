# 🫙 Container With Most Water – LeetCode 11 (C++)

This repository contains a C++ solution for **LeetCode Problem 11 – Container With Most Water**.  
The objective is to find two lines that together with the x-axis form a container that holds the **maximum amount of water**.

This solution uses the **Two Pointer Technique** to achieve optimal performance.

---

## 📌 Problem Statement

You are given an integer array `height` of length `n`.

- Each element represents a vertical line drawn at index `i`
- The height of the line is `height[i]`

### Task
Find two lines such that together with the x-axis they form a container that holds the **maximum water**.

### Formula

Water stored between two lines:


Area = width × min(height[left], height[right])



Where:

- `width = right - left`
- Height is limited by the shorter line

---

## ⚙️ Approach – Two Pointer Strategy

Instead of checking all possible pairs (`O(n²)`), we use an optimized approach.

### Key Idea

- Start with two pointers:
  - `left = 0`
  - `right = n - 1`
- Calculate area
- Move the pointer with the **smaller height**
  - Because the container height is limited by the shorter line
  - Moving the taller line will not increase area

This ensures we explore maximum possible combinations efficiently.

---

## 🧠 Algorithm Steps

1. Initialize:


left = 0
right = n - 1
maxWater = 0


2. While `left < right`:
- Compute width
- Compute current height = min(height[left], height[right])
- Compute water = width × current height
- Update `maxWater`
- Move pointer of smaller height
3. Return `maxWater`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

Only one traversal of the array.

---

## 💻 Source Code

```cpp
class Solution{
public:
 int waterContainer(vector<int>& height){
     int left = 0;
     int right = height.size() - 1;
     int maxWater = 0;

     while(left < right){
         int width = right - left;
         int currentHeight = min(height[left], height[right]);
         int water = width * currentHeight;

         maxWater = max(maxWater, water);

         if(height[left] < height[right]){
             left++;
         }
         else{
             right--;
         }
     }

     return maxWater;
 }
};
```

# Example 

<b>Input : </b>

```height = [1,8,6,2,5,4,8,3,7]```

<b>Output : </b>

```49```

<b>Explanation : </b>

- Best container formed between index 1 and 8
- Width = 7
- Height = min(8,7) = 7
- Area = 7 × 7 = 49


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast


