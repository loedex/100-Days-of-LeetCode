# 🔤 LeetCode 125 — Valid Palindrome

## 📌 Problem Description

**Difficulty:** Easy  
**Topics:** Two Pointers, String

Given a string `s`, determine whether it is a **palindrome**.

A string is considered a **palindrome** if:

- All **non-alphanumeric characters are ignored**
- **Uppercase and lowercase letters are treated the same**

Return:

```
true  → if the string is a palindrome
false → otherwise
```

---

## 🧠 Example

### Example 1

**Input**

```
s = "A man, a plan, a canal: Panama"
```

**Output**

```
true
```

**Explanation**

After removing non-alphanumeric characters and converting to lowercase:

```
amanaplanacanalpanama
```

This reads the same forward and backward.

---

### Example 2

**Input**

```
s = "race a car"
```

**Output**

```
false
```

**Explanation**

Processed string:

```
raceacar
```

Not a palindrome.

---

### Example 3

**Input**

```
s = " "
```

**Output**

```
true
```

**Explanation**

An empty string is considered a valid palindrome.

---

## 🚀 Approach — Two Pointer Technique

We use **two pointers**:

```
left  → start of string
right → end of string
```

### Steps

1. Ignore non-alphanumeric characters using:

```
isalnum()
```

2. Compare characters in **lowercase** using:

```
tolower()
```

3. Move pointers toward the center.

4. If characters differ → return `false`.

5. If loop finishes → return `true`.

---

## 💻 C++ Solution

```cpp
class Solution{
public:

    bool validPalindrome(string s){

        int left = 0;
        int right = s.length() - 1;

        while(left < right){

            while((left < right) && (!isalnum(s[left]))){
                left++;
            }

            while((left < right) && (!isalnum(s[right]))){
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```
O(n)
```

Each character is processed at most once.

---

### Space Complexity

```
O(1)
```

No additional memory is used.

---

## 🎯 Key Concepts

- Two Pointer Technique
- String Traversal
- Character Filtering
- Case Normalization

---

## 📚 LeetCode Problem

https://leetcode.com/problems/valid-palindrome/

---

## 👨‍💻 Author

Husnain Ahmad

---

## ✅ Summary

✔ Efficient **two-pointer solution**  
✔ Ignores special characters  
✔ Case-insensitive comparison  
✔ Optimal time and space complexity
