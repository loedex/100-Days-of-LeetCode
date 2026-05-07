# Reverse String

A simple and efficient C++ solution for reversing a string in-place using the two-pointer technique.

---

## Problem Statement

Given an array of characters `s`, reverse the order of the characters **in-place**.

You must do this by modifying the input array directly with **O(1)** extra memory.

---

## Example

### Input
```cpp
s = ['h','e','l','l','o']
```

### Output
```cpp
['o','l','l','e','h']
```

---

## Approach

This solution uses the **Two-Pointer Technique**.

### Steps:
1. Initialize two pointers:
   - `left` at the beginning of the array
   - `right` at the end of the array
2. Swap the characters at both pointers.
3. Move:
   - `left` forward
   - `right` backward
4. Continue until both pointers meet.

This approach reverses the string efficiently without using extra space.

---

## Algorithm

```text
1. Set left = 0
2. Set right = size of array - 1
3. While left < right:
      swap(s[left], s[right])
      left++
      right--
4. End
```

---

## C++ Solution

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Swap characters at the two pointers
            swap(s[left], s[right]);

            // Move pointers towards the middle
            left++;
            right--;
        }
    }
};
```

---

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Reversing String | O(n) |

- `n` = number of characters in the string

---

## Space Complexity

```text
O(1)
```

No extra space is used since the reversal is performed in-place.

---

## Concepts Used

- Two Pointer Technique
- In-Place Array Manipulation
- Swapping Elements
- C++ STL (`swap`)

---

## File Structure

```text
.
├── README.md
└── solution.cpp
```

---

## How to Run

### Using g++

```bash
g++ solution.cpp -o solution
./solution
```

---

## Learning Outcome

By solving this problem, you will understand:

- How the two-pointer approach works
- How to reverse arrays/strings efficiently
- How to optimize space complexity

---

## Author

Husnain Ahmad

---

## License

This project is licensed under the MIT License.
