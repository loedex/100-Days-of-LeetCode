<div align="center">

# Day 98: Permutations

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-46-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Backtracking-8A2BE2?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

Given an array `nums` of **distinct** integers, return **all the possible permutations**. You can return the answer in **any order**.

### Examples

| Example | Input | Output |
|:-------:|-------|--------|
| 1 | `nums = [1,2,3]` | `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]` |
| 2 | `nums = [0,1]` | `[[0,1],[1,0]]` |
| 3 | `nums = [1]` | `[[1]]` |

### Constraints

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.

---

## Intuition

A **permutation** is an arrangement of all the numbers in some order. For 3 numbers, there are `3 * 2 * 1 = 6` arrangements:

- 3 choices for the first position,
- then 2 choices for the second,
- then 1 choice for the last.

In general, `n` numbers have `n!` permutations.

We can build each permutation **one position at a time**:

> For position `0`, try every number. For position `1`, try every number that is still unused. Continue until every position is filled, then record the result.

This "make a choice, explore, then undo the choice" pattern is called **backtracking**.

The solution uses a neat trick to track which numbers are unused: **swapping**. The array is split into two parts at all times:

```text
[ fixed part | remaining part ]
  0 .. index-1   index .. n-1
```

To choose which number goes into position `index`, we **swap** it from the remaining part into position `index`. That number is now part of the fixed part, and we recurse for the next position.

---

## Approach

**Backtracking with in-place swaps.**

1. `backtrack(index)` decides which number goes into position `index`.
2. **Base case:** if `index == n`, every position is fixed, so the current arrangement of `nums` is a complete permutation. Copy it into `result` and return.
3. **Recursive case:** for each `i` from `index` to `n - 1`:
   - **Choose:** `swap(nums[index], nums[i])`, bringing the candidate into position `index`.
   - **Explore:** call `backtrack(index + 1)`.
   - **Un-choose (backtrack):** swap again to restore the array exactly as it was, so the next candidate starts from a clean state.
4. `permute` calls `backtrack(0)` and returns `result`.

### Why undo the swap?

After exploring one choice, the array must return to its previous state. Otherwise the next iteration of the loop would work on a scrambled array and could skip or repeat permutations. The second `swap` is what makes the algorithm "backtrack".

### Why `i` starts at `index` and not `index + 1`?

When `i == index`, the swap does nothing, which represents the choice "keep the number that is already at this position". Starting at `index` ensures that choice is included.

### Dry Run

**Example 1: `nums = [1,2,3]`**

The recursion tree below shows the array after each choice. Each leaf (at `index = 3`) is a complete permutation.

```text
index 0:  choose 1             choose 2             choose 3
          [1,2,3]              [2,1,3]              [3,2,1]
             |                    |                    |
index 1:  2       3           1       3            2       1
         [1,2,3] [1,3,2]     [2,1,3] [2,3,1]      [3,2,1] [3,1,2]
             |      |            |       |            |       |
index 2:  (forced) (forced)   (forced) (forced)    (forced) (forced)
          [1,2,3] [1,3,2]    [2,1,3]  [2,3,1]     [3,2,1]  [3,1,2]
```

Results are recorded in this order:

| # | Permutation |
|:-:|:-----------:|
| 1 | `[1,2,3]` |
| 2 | `[1,3,2]` |
| 3 | `[2,1,3]` |
| 4 | `[2,3,1]` |
| 5 | `[3,2,1]` |
| 6 | `[3,1,2]` |

All `3! = 6` permutations are produced. The order differs slightly from the example in the problem statement, which is acceptable because the problem allows **any order**.

---

## Solution (C++)

```cpp
class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& result) {
        if (index == (int)nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < (int)nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(index + 1, nums, result);
            swap(nums[index], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};
```

---

## Complexity Analysis

Let `n` be the length of `nums`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n * n!)` | There are `n!` permutations, and each one is copied into the result in `O(n)` time. |
| **Space** | `O(n)` | The recursion depth is `n`, and swapping happens in place. This does not count the output, which itself holds `n * n!` numbers. |

For the maximum input `n = 6`, there are only `6! = 720` permutations, so the solution runs instantly.

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Single element `[1]` | `index` reaches `1` immediately, giving `[[1]]`. |
| Two elements | Produces both orderings, for example `[0,1]` and `[1,0]`. |
| Negative numbers | Irrelevant to the logic, since only positions are swapped. |
| Distinct values guaranteed | No duplicate permutations are produced. With duplicate values (Permutations II), this exact code would repeat permutations. |
| Input array restored | Every swap is undone, so `nums` ends in its original order. |

---

## Key Takeaways

- **Backtracking template:** choose, explore, un-choose. Many problems (subsets, combinations, N-Queens, Sudoku) follow the same pattern.
- **Swapping in place** avoids needing a `used[]` array or building temporary vectors for each choice.
- `result.push_back(nums)` stores a **copy** of the current arrangement, which is important because `nums` keeps changing afterward.
- The total work is tied to the number of permutations, `n!`, which grows very fast. This is why the constraint is only `n <= 6`.

### Alternative Approaches

| Approach | Idea | Notes |
|----------|------|-------|
| **Used array** | Build a temporary list and mark numbers as used with a boolean array. | Easy to read, and produces results in the same order as the examples. Needs `O(n)` extra space. |
| **`std::next_permutation`** | Sort the array, then repeatedly call the standard library function. | Very short, but hides the underlying idea. |
| **Swap backtracking (this solution)** | Swap each candidate into position. | In place, and no extra bookkeeping. |

---

## Related Problems

- Permutations II (LeetCode 47)
- Subsets (LeetCode 78)
- Combinations (LeetCode 77)
- Letter Combinations of a Phone Number (LeetCode 17)
- Next Permutation (LeetCode 31)
- Combination Sum (LeetCode 39)