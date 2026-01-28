# 🧴 Water Bottles Exchange (LeetCode 1518 – C++)

This project provides a C++ solution to **LeetCode Problem 1518: Water Bottles**.  
The program calculates the **maximum number of water bottles that can be drunk** given an initial number of bottles and an exchange rate for empty bottles.

This solution uses a **greedy simulation approach** and is part of my daily problem-solving practice.

---

## 📌 Problem Description

You are given:

- `numBottles`: The number of full water bottles you initially have  
- `numExchange`: The number of empty bottles required to exchange for one full bottle  

After drinking a bottle, you gain an empty bottle.  
You can continue exchanging empty bottles for full ones **as long as you have enough empty bottles**.

### Goal:
Return the **maximum number of bottles you can drink**.

---

## ⚙️ Solution Approach

The idea is to **simulate the exchange process**:

- Drink all available full bottles
- Track empty bottles
- Exchange empty bottles for new full bottles whenever possible
- Repeat until exchanges are no longer possible

This greedy approach ensures we always drink the maximum number of bottles.

---

## 🧠 Algorithm Steps

1. Initialize:
   - `totalDrink = numBottles`
   - `emptyBottles = numBottles`
2. While `emptyBottles >= numExchange`:
   - Exchange bottles: `emptyBottles / numExchange`
   - Add exchanged bottles to `totalDrink`
   - Update remaining empty bottles
3. Return `totalDrink`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`  
  (Each exchange reduces empty bottles until the loop ends)
- **Space Complexity:** `O(1)`  
  (Only constant extra variables used)

---

## 💻 Source Code

```cpp
#include<iostream>
using namespace std;

class Solution{
    public:
        int numWaterBottles(int numBottles, int numExchange){
            int totalDrink = numBottles;
            int emptyBottles = numBottles;

            while(emptyBottles >= numExchange){
                totalDrink += emptyBottles / numExchange;
                emptyBottles = (emptyBottles / numExchange) + (emptyBottles % numExchange);
            }

            return totalDrink;
        }
};
int main(){
    Solution obj;
    cout << endl << "Total Drinked Bottles : "
         << obj.numWaterBottles(9, 3);
    return 0;
}
```
# Example
<b>Input: </b>
```
numBottles = 9
numExchange = 3
```

<b>Output: </b>
```
Total Drinked Bottles : 13
```

<b>Explanation:</b>
- Drink 9 bottles → 9 empty
- Exchange 9 empty → 3 full
- Drink 3 bottles → 3 empty
- Exchange 3 empty → 1 full
- Drink 1 bottle → no more exchanges possible
Total bottles drunk = 13

# 📌 Author
<b>Husnain Ahmad</b>

Aspiring Software Engineer | MERN Stack Learner | DSA Enthusiast
