# Palindrome Number
# 📌 Problem Description

Given an integer x, determine whether it is a palindrome number.

A number is considered a palindrome if it reads the same forward and backward.

💡 <b>Intuition</b>

<i>A palindrome number remains unchanged when its digits are reversed.
If the reversed version of the number is equal to the original number, then the number is a palindrome.

Negative numbers are not palindromes because the negative sign (-) appears only on one side of the number.</i>

🧠 <b>Approach</b>

1) If the number is negative, it cannot be a palindrome, so return false.
2) Store the original number in a temporary variable.
3) Reverse the digits of the number by:
4) Extracting the last digit using modulus (% 10)
5) Removing the last digit using division (/ 10)
6) Building the reversed number step by step
7) Compare the reversed number with the original number.
8) If both are equal, the number is a palindrome; otherwise, it is not.

# ⏱️ Complexity Analysis

<b>- Time Complexity:</b>
O(d), where d is the number of digits in the number.

<b>- Space Complexity:</b>
O(1), since only a few integer variables are used.

# 🧪 Example
<b>Input:</b>
10

<b>Output:</b>
The Number is Not Palindrome

# 📝 Notes

- This solution uses an iterative digit reversal approach.
- No extra data structures are used.
- The logic is simple, efficient, and easy to understand for beginners.
