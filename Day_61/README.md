# 492. Construct the Rectangle

**Difficulty:** Easy
**Topics:** Math
**LeetCode Link:** https://leetcode.com/problems/construct-the-rectangle/

## 📋 Problem Statement

A web developer needs to know how to design a web page's size. Given a specific rectangular web page's area, your job is to design a rectangular web page, whose length `L` and width `W` satisfy the following requirements:

1. `L * W = area`
2. `L >= W`
3. The difference between `L` and `W` should be as small as possible.

Return an array `[L, W]` where `L` and `W` are the length and width of the web page you designed.

### Example 1
```
Input: area = 4
Output: [2, 2]
```

### Example 2
```
Input: area = 37
Output: [37, 1]
```

### Example 3
```
Input: area = 122122
Output: [427, 286]
```

## 💡 Approach

The key idea: we want `L` and `W` to be as close to each other as possible, while still multiplying to give `area`. That means the best starting point is the **square root of the area** — because if a perfect rectangle (a square) were possible, that's exactly where it would sit.

Step by step:

1. Start with `w = sqrt(area)`, rounded down. This is our "closest to square" guess for the smaller side.
2. Check if `w` divides `area` evenly (`area % w == 0`).
   - If yes, we're done — this `w` is our width.
   - If no, decrease `w` by 1 and check again.
3. Since `w = 1` always divides `area`, this loop is guaranteed to stop eventually.
4. Once we find a valid `w`, compute `l = area / w`. Because we searched **downward** from the square root, `l` will always end up `>= w`, satisfying the problem's condition.

## 🧠 Why This Works

- Every integer has at least one factor pair (even if it's `1 x area`).
- By starting at `sqrt(area)` and moving downward, the **first** valid factor we find gives the pair with the **smallest possible difference** between `L` and `W`.
- Moving upward from `sqrt(area)` instead would give us `W`, but then `L` would end up smaller than `W` — so we'd have to swap them anyway. Searching downward avoids that extra step.

## 🖥️ Solution (C++)

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = std::sqrt(area);

        // Decrement w until we find a value that perfectly divides the area
        while (area % w != 0) {
            w--;
        }

        // Once found, L = area / w. Since we started from sqrt(area) downwards, L >= w
        int l = area / w;

        return {l, w};
    }
};
```

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(√area)` in the worst case — we might walk all the way down from `sqrt(area)` to `1`.
- **Space Complexity:** `O(1)` — only a couple of integer variables are used.

## 🚀 How to Run

1. Copy the `Solution` class into your C++ environment (or paste it directly into LeetCode's editor).
2. Call `constructRectangle(area)` with your desired integer area.
3. It returns a `vector<int>` of size 2: `{L, W}`.

```cpp
Solution sol;
vector<int> result = sol.constructRectangle(4);
// result = {2, 2}
```

## 📝 Notes

- `std::sqrt` returns a `double`; assigning it to an `int` truncates (rounds down), which is exactly the behavior we want here.
- This problem is a good beginner-friendly intro to thinking about factor pairs and why searching from the square root outward (or in this case, downward) is often optimal.