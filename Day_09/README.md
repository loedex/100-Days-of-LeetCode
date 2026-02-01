# 🔁 Palindrome Number (LeetCode 9 – C++)

This project contains a C++ solution to **LeetCode Problem 9: Palindrome Number**.  
The objective is to determine whether a given integer reads the same **forward and backward**.

The solution reverses the digits of the number and compares it with the original value.

---

## 📌 Problem Description

A **palindrome number** is a number that remains the same when its digits are reversed.

### Examples:

```121 → Palindrome```
```1331 → Palindrome```
```10 → Not Palindrome```
```-121 → Not Palindrome```

### Task:
Return **true** if the integer is a palindrome, otherwise return **false**.

---

## ⚙️ Solution Approach

The approach is based on **digit reversal**:

- Negative numbers are immediately rejected
- Reverse the digits of the number using modulo and division
- Compare the reversed number with the original number

This avoids converting the number into a string and keeps the logic purely numeric.

---

## 🧠 Algorithm Steps

1. If the number is negative → return `false`
2. Store the original number
3. Initialize `reverseNum = 0`
4. While the number is greater than 0:
   - Extract the last digit using `% 10`
   - Remove the last digit using `/ 10`
   - Append digit to `reverseNum`
5. Compare `reverseNum` with original number
6. Return `true` if equal, otherwise `false`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log₁₀ n)`  
  (Depends on number of digits)
- **Space Complexity:** `O(1)`  
  (Only constant extra variables used)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;

class Solution{
    public:
        bool isPalindrome(int x){
            if(x < 0){
                cout << "Number is Negative";
                exit(0);
                return false;
            }

            int num = x;
            int reverseNum = 0;

            while(num > 0){
                int last = num % 10;
                num = num / 10;
                reverseNum = reverseNum * 10 + last;
            }

            if(reverseNum == x){
                return true;
            } else {
                return false;
            }
        }
};

int main(){
    Solution obj;
    bool result = obj.isPalindrome(10);

    if(result){
        cout << "The Number is Palindrome";
    }
    else{
        cout << "The Number is Not Palindrome";
    }

    return 0;
}
```
# Example : 
<b>Input : </b>

```x = 121```

<b>Output: </b>

```true```

<b>Explanation: </b>

```Reverse of 121 = 121 → Same → Palindrome```

# Author:
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast