# 🧹 Remove Duplicates from Sorted Array – LeetCode 26 (C++)

This repository contains a C++ solution for **LeetCode Problem 26 – Remove Duplicates from Sorted Array**.  
The objective is to remove duplicate elements from a **sorted array in-place** and return the count of unique elements.

This implementation demonstrates the **Two Pointer Technique** using a fixed-size array.

---

## 📌 Problem Statement

Given a sorted integer array `arr`, remove the duplicates **in-place** such that each unique element appears only once.

Return the **number of unique elements** after removal.

### Key Requirements
- Do not use extra space for another array
- Maintain the original order
- Modify the array directly

---

## ⚙️ Approach – Two Pointer Technique

Since the array is already sorted, duplicate elements are adjacent.  
We use two indices:

- **Pointer `i`** → Tracks the position of the last unique element
- **Pointer `j`** → Traverses the array

Whenever `arr[j]` is different from `arr[i]`, it means we found a new unique value.  
We increment `i` and place the new value at `arr[i]`.

---

## 🧠 Algorithm Steps

1. Initialize `i = 0`
2. Loop `j` from `1` to array size − 1
3. If `arr[j] != arr[i]`:
   - Increment `i`
   - Assign `arr[i] = arr[j]`
4. Print updated array
5. Return `i + 1` as the number of unique elements

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`

Only one traversal of the array and no extra memory used.

---

## 💻 Source Code

```cpp
class Solution{
public:
    int find(int[]);
};

int Solution::find(int arr[]){
    int i = 0;

    for(int j = 1; j < 6; j++){
        if(arr[j] != arr[i]){
            arr[++i] = arr[j];
        }
    }

    cout << endl << "Updated Array: \n";
    for(int j = 0; j < 6; j++){
        cout << arr[j] << "\t";
    }

    return (i + 1);
}
```

# Example : 

<b>Input : </b>

```arr = [1,1,2,2,3,3]```

<b>Output : </b>

```Updated Array: 1 2 3 2 3 3```
```Returned Value: 3```
```(Only the first 3 elements are considered valid unique values.)```


# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast


