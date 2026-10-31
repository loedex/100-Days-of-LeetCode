<div align="center">

# Day 85: Same Tree

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-100-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Runtime](https://img.shields.io/badge/Runtime-0%20ms%20(100%25)-brightgreen?style=for-the-badge)

</div>

---

## Problem Statement

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are **structurally identical**, and the nodes have the **same value**.

### Examples

| Example | Input | Output | Explanation |
|:-------:|-------|:------:|-------------|
| 1 | `p = [1,2,3]`, `q = [1,2,3]` | `true` | Same structure and same values. |
| 2 | `p = [1,2]`, `q = [1,null,2]` | `false` | `2` is a left child in `p` but a right child in `q`. |
| 3 | `p = [1,2,1]`, `q = [1,1,2]` | `false` | The structure matches, but the values differ. |

### Constraints

- The number of nodes in both trees is in the range `[0, 100]`.
- `-10^4 <= Node.val <= 10^4`

---

## Intuition

Two trees are the same only if **every corresponding pair of nodes** matches. That means checking two things at each position:

1. **Structure:** both nodes exist, or both are missing.
2. **Value:** the two nodes hold the same number.

A tree is a naturally recursive structure: each node is the root of a smaller tree. So the question "Are these two trees the same?" can be broken into smaller versions of itself:

> Two trees are the same if their roots match, **and** their left subtrees are the same, **and** their right subtrees are the same.

This is a perfect fit for **recursion**.

---

## Approach

**Recursive depth-first comparison.**

For each pair of nodes `(p, q)`, apply these rules in order:

| Order | Condition | Result | Reason |
|:-----:|-----------|:------:|--------|
| 1 | Both `p` and `q` are `null` | `true` | Two empty trees are identical. This is the **base case**. |
| 2 | Only one is `null`, or `p->val != q->val` | `false` | The structure or the value differs. |
| 3 | Otherwise | Recurse | Compare the left subtrees **and** the right subtrees. |

The final answer is `true` only if **both** recursive calls return `true`, which is why they are joined with `&&`.

### Why does the order of the checks matter?

The second condition uses `!p || !q || p->val != q->val`. Because `||` stops at the first true condition (**short-circuit evaluation**), `p->val` and `q->val` are only accessed when both pointers are non-null. This prevents a null pointer dereference.

The first check (`!p && !q`) removes the "both null" case first, so by the time we reach the second check, a null pointer means exactly **one** of them is null.

### Dry Run

Using Example 2: `p = [1,2]` and `q = [1,null,2]`

```text
    p        q
    1        1
   /          \
  2            2
```

| Call | `p` | `q` | Check | Result |
|------|:---:|:---:|-------|:------:|
| `isSameTree(1, 1)` | 1 | 1 | Both non-null, values equal, so recurse | continue |
| `isSameTree(p->left, q->left)` | 2 | null | One node is null | `false` |

The left call returns `false`, so `false && ...` is `false`. The right subtrees are never compared (short-circuit), and the final answer is **`false`**.

---

## Solution (C++)

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are identical
        if (!p && !q) {
            return true;
        }
        // If one is null and the other is not, or values don't match
        if (!p || !q || p->val != q->val) {
            return false;
        }
        
        // Recursively compare left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

---

## Complexity Analysis

Let `n` be the number of nodes in the smaller of the two trees, and `h` the height of the tree.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n)` | Each pair of nodes is visited at most once. The recursion stops early at the first mismatch. |
| **Space** | `O(h)` | Space comes from the recursion call stack. This is `O(log n)` for a balanced tree and `O(n)` in the worst case (a skewed tree). |

---

## Submission Result

| Metric | Result |
|--------|--------|
| **Status** | Accepted (68 / 68 test cases passed) |
| **Runtime** | 0 ms, beats 100.00% of C++ submissions |
| **Memory** | 12.90 MB, beats 44.20% of C++ submissions |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Both trees empty | Returns `true` (base case). |
| One tree empty, the other not | Returns `false`. |
| Same structure, different values | Returns `false` at the first value mismatch. |
| Same values, different structure | Returns `false` when one node is `null` and the other is not. |
| Single-node trees | Compares the two values, then both children are `null`, so it returns `true` if equal. |
| Negative values | Handled naturally by the `!=` comparison. |

---

## Key Takeaways

- Recursion mirrors the shape of a tree, so many tree problems reduce to "check the node, then solve the left and right subtrees."
- Always handle the **null base cases first** to avoid dereferencing null pointers.
- Short-circuit evaluation (`||` and `&&`) makes the solution both **safe** and **efficient**, since it stops at the first mismatch.
- The same pattern applies to related problems such as Symmetric Tree and Subtree of Another Tree.

### Alternative Approach

An **iterative** solution uses a queue (BFS) or a stack (DFS) that holds pairs of nodes, comparing them one pair at a time. It has the same `O(n)` time complexity and avoids deep recursion on very skewed trees.

---

## Related Problems

- Symmetric Tree (LeetCode 101)
- Subtree of Another Tree (LeetCode 572)
- Invert Binary Tree (LeetCode 226)
- Maximum Depth of Binary Tree (LeetCode 104)