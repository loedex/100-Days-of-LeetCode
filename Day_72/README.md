# 112. Path Sum

## Problem

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

**LeetCode Link:** [112. Path Sum](https://leetcode.com/problems/path-sum/)

### Example 1

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The path 5 -> 4 -> 11 -> 2 adds up to 22.
```

### Example 2

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

### Example 3

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

### Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

---

## Approach

This is solved with a straightforward **recursive DFS (depth-first search)**.

The core idea: instead of tracking the sum accumulated *so far*, we track the sum *still needed*. At each node, we subtract the node's value from `targetSum`, and pass that remaining value down to its children.

**Steps:**

1. **Empty tree / null node** → There's no path here, so return `false`.
2. **Leaf node** (no left and no right child) → This is the end of a root-to-leaf path, so check if the remaining `targetSum` exactly equals this node's value.
3. **Internal node** → Subtract the current node's value from `targetSum` to get the `remainingSum`, then recursively check the left and right subtrees with that new target. If *either* subtree finds a valid path, the answer is `true`.

This naturally covers every root-to-leaf path in the tree without needing any extra data structures to track sums manually.

## Code

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: empty node
        if (root == nullptr) {
            return false;
        }
        
        // Base case: leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Calculate the remaining sum needed
        int remainingSum = targetSum - root->val;
        
        // Traverse left and right subtrees
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
```

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|-----------|--------------|
| **Time**  | `O(N)` | In the worst case, we visit every node in the tree exactly once. |
| **Space** | `O(H)` | Where `H` is the height of the tree, due to the recursion call stack. This is `O(log N)` for a balanced tree, and `O(N)` for a skewed one. |

## Key Takeaways

- Passing a **remaining sum** downward avoids needing to accumulate a "sum so far" and compare at the end — it keeps the base case check simple (`targetSum == root->val`).
- Always check for the **leaf condition** explicitly — a node with only one child is *not* a leaf, so you can't just check `root->left == nullptr || root->right == nullptr`.
- The `||` (logical OR) between the two recursive calls means we only need **one** valid path to exist, and thanks to short-circuit evaluation, the right subtree isn't even checked if the left one already returns `true`.