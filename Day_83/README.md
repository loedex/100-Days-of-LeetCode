<div align="center">

# Day 83: Merge Two Sorted Lists

![Platform](https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Problem](https://img.shields.io/badge/Problem-21-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-2ea44f?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## Problem Statement

You are given the heads of two sorted linked lists, `list1` and `list2`.

Merge the two lists into a single **sorted** list. The merged list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.

### Examples

| Input | Output |
|-------|--------|
| `list1 = [1,2,4]`, `list2 = [1,3,4]` | `[1,1,2,3,4,4]` |
| `list1 = []`, `list2 = []` | `[]` |
| `list1 = []`, `list2 = [0]` | `[0]` |

### Constraints

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

---

## Intuition

Both lists are already sorted, so the smallest remaining value is always at the **front** of one of the two lists. We never need to search; we only need to compare the two current heads.

This is the same idea as the merge step of Merge Sort:

1. Compare the nodes at the front of both lists.
2. Take the smaller one and attach it to the result.
3. Move forward in the list we took it from.
4. Repeat until one list runs out, then attach whatever is left of the other.

Because each list is already sorted, the leftover nodes are guaranteed to be greater than or equal to everything already placed, so they can be attached in one step.

---

## Approach

**Iterative merge with a dummy node.**

1. Create a **dummy node** that acts as a fixed starting point for the merged list. This avoids special handling for the "first node" of the result.
2. Keep a pointer `current` that always points to the **last node** of the merged list so far. It starts at the dummy node.
3. While both `list1` and `list2` have nodes:
   - If `list1->val <= list2->val`, attach `list1` to `current->next` and advance `list1`.
   - Otherwise, attach `list2` to `current->next` and advance `list2`.
   - Advance `current` to the node we just attached.
4. When the loop ends, at most one list still has nodes. Attach that remainder directly to `current->next`.
5. Return `dummy.next`, which is the true head of the merged list.

Using `<=` (rather than `<`) keeps the merge **stable**: when values are equal, the node from `list1` comes first.

### Why a dummy node?

Without it, we would have to check whether the merged list is empty every time we attach a node, just to decide what the head is. The dummy node removes that special case and keeps the code short and clean.

### Dry Run

Using `list1 = [1,2,4]` and `list2 = [1,3,4]`:

| Step | list1 head | list2 head | Chosen | Merged so far |
|:----:|:----------:|:----------:|:------:|---------------|
| 1 | 1 | 1 | list1 (tie goes to list1) | 1 |
| 2 | 2 | 1 | list2 | 1 → 1 |
| 3 | 2 | 3 | list1 | 1 → 1 → 2 |
| 4 | 4 | 3 | list2 | 1 → 1 → 2 → 3 |
| 5 | 4 | 4 | list1 (tie goes to list1) | 1 → 1 → 2 → 3 → 4 |
| 6 | null | 4 | loop ends | attach remainder `[4]` |

**Result:** `1 → 1 → 2 → 3 → 4 → 4`

---

## Solution (C++)

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Loop while both lists have nodes remaining
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes from whichever list is not empty
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next;
    }
};
```

---

## Complexity Analysis

Let `n` and `m` be the lengths of `list1` and `list2`.

| Metric | Complexity | Explanation |
|--------|:----------:|-------------|
| **Time** | `O(n + m)` | Each node from both lists is visited exactly once. |
| **Space** | `O(1)` | Only a few pointers and one stack-allocated dummy node are used. The existing nodes are relinked, not copied. |

---

## Edge Cases Considered

| Case | Behavior |
|------|----------|
| Both lists empty | Loop is skipped, `current->next = list2` (null), returns `nullptr`. |
| One list empty | Loop is skipped, the other list is attached as-is. |
| Duplicate values | `<=` keeps the merge stable. |
| Lists of different lengths | The leftover tail of the longer list is attached in a single step. |
| All values in one list smaller than the other | One list is consumed fully, then the other is attached. |

---

## Key Takeaways

- A **dummy node** simplifies linked list construction by removing head-specific edge cases.
- Merging works in linear time because both inputs are **already sorted**.
- This technique is the foundation of **Merge Sort on linked lists** and **Merge K Sorted Lists**.
- Relinking existing nodes (instead of creating new ones) keeps the space complexity at `O(1)`.

---

## Related Problems

- Merge k Sorted Lists (LeetCode 23)
- Sort List (LeetCode 148)
- Merge Sorted Array (LeetCode 88)