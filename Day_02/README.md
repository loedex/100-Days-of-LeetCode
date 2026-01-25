# <b>Power of Two</b>
<hr>

# Description: 
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two if there exists an integer x such that $n = 2^x.

# Intuition
<i>A power of two is a number that can be divided by 2 repeatedly until it reaches 1.If at any point during the division the number becomes odd (and is not 1), it cannot be a power of two.

Numbers less than or equal to 0 are not considered powers of two in this context.</i>

# Approach:
1) If the number is less than 1, return false immediately.

2) If the number is 1, return true (since $2^0 = 1$).

3) Use a while loop to repeatedly check if the number is divisible by 2.

4) Inside the loop, divide the number by 2 (n = n / 2) as long as the remainder is 0.

5) After the loop finishes, check the final value of the number.

6) If the remaining value is 1, the number is a power of two; otherwise, it is not.

# ⏱️ Complexity Analysis:
- <b>Time Complexity:</b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; O(log n)
  
because we are dividing the number by 2 in each iteration.

- <b>Space Complexity:</b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O(1)

since we are only using a single integer variable for calculations.

# Example:

<b>Input:</b>
20

<b>Output:</b>
Number is not Power of Two

# 📝 Notes: 
- This solution follows a straightforward iterative division logic.
- It handles edge cases like negative numbers and zero by checking if n < 1.
- The code is written in C++ using a class-based structure for better organization.
