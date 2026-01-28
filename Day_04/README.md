# 🧮 Tribonacci Number Calculator (C++)

This project implements a C++ program to compute the **n-th Tribonacci number** using an efficient iterative approach.  
It is designed as part of a learning and practice journey for mastering problem-solving and algorithmic thinking in C++.

---

## 📌 Problem Description

The **Tribonacci sequence** is a generalization of the Fibonacci sequence where:

- `T(0) = 0`  
- `T(1) = 1`  
- `T(2) = 1`  
- For `n ≥ 3`:

T(n) = T(n-1) + T(n-2) + T(n-3)

---

## ⚙️ Solution Approach

This program uses an **iterative dynamic programming approach** with constant space:

- Handles base cases directly (`n = 0, 1, 2`)
- Uses three variables to track the previous three values
- Iteratively computes up to the required term

This ensures:

- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)` (no extra arrays used)

---

## 🧠 Algorithm Steps

1. If `n == 0`, return `0`  
2. If `n == 1` or `n == 2`, return `1`  
3. Initialize:
   - `first = 0`  
   - `second = 1`  
   - `third = 1`  
4. Loop from `1` to `n-2`:
   - `sum = first + second + third`
   - Shift values forward  
5. Return the final computed value  

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;

class Solution{
    public:
        int tribonacci(int n){
            if(n == 0){
                return 0;
            }
            else if(n == 1 || n == 2){
                return 1;
            }
            else{
                int first = 0;
                int second = 1;
                int third = 1;
                int sum;

                for(int i = 1; i < n - 1; i++){
                    sum = first + second + third;
                    first = second;
                    second = third;
                    third = sum;
                }

                return sum;
            }
        }
};

int main(){
    Solution obj;
    int N;

    cout << "Enter Number : ";
    cin >> N;

    cout << endl << "Result: " << obj.tribonacci(N);

    return 0;
}
```
# 📝 Example

<b>Input:</b>
``` Enter Number : 4```
<b>Output:</b>
```Result: 4```

<b>Explanation:</b>
```
T(0) = 0  
T(1) = 1  
T(2) = 1  
T(3) = 2  
T(4) = 4  
```

<b>🎯 Learning Objectives:</b> 
- Understand the Tribonacci sequence
- Practice iterative dynamic programming
- Improve space optimization techniques in C++
- Strengthen loop-based problem solving

<b>📌 Author</b>
Husnain Ahmad
Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
