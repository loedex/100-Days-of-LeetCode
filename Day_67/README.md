# 2. Add Two Numbers

**Difficulty:** Medium
**Topics:** Linked List, Math, Recursion
**LeetCode:** [Problem 2](https://leetcode.com/problems/add-two-numbers/)

## Problem Statement

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number `0` itself.

### Example 1

```
Input:  l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807
```

### Example 2

```
Input:  l1 = [0], l2 = [0]
Output: [0]
```

### Example 3

```
Input:  l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

## Approach

Since the digits are stored in reverse order, the head of each list is the **least significant digit**. That's actually convenient — it means we can add the numbers exactly the way we'd add them by hand, from right to left, just by walking both lists from the start.

Here's the step-by-step idea:

1. Create a **dummy head node**. This is a small trick that saves us from writing special-case code for the very first node of the result list — we just build the list after it and return `dummyHead->next` at the end.
2. Use a `current` pointer to keep track of the last node we've added to the result list.
3. Keep a `carry` variable, starting at `0`, for when a digit sum is 10 or more.
4. Loop as long as **either** list still has nodes, **or** there's a leftover carry to add:
   - Grab the current digit from `l1` (or `0` if `l1` has run out).
   - Grab the current digit from `l2` (or `0` if `l2` has run out).
   - Compute `sum = val1 + val2 + carry`.
   - The new digit to store is `sum % 10`.
   - The new carry is `sum / 10`.
   - Attach a new node with that digit to the result list and move `current` forward.
   - Advance `l1` and `l2` if they still have nodes left.
5. Return `dummyHead->next` (the real head of the result), and clean up the dummy node.

This one pass handles everything: lists of different lengths, and a final carry that spills over into a brand new digit (like in Example 3).

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Deallocate dummy node memory
        return result;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(max(m, n))`, where `m` and `n` are the lengths of `l1` and `l2`. We visit each node of both lists exactly once.
- **Space Complexity:** `O(max(m, n))` for the newly created result list (this doesn't count as "extra" space in most conventions, since it's the required output).

## Why the Dummy Head Node?

If you're new to linked lists, the `dummyHead` trick is worth remembering — it shows up in a lot of linked-list problems. Without it, you'd need an `if` check to handle "is this the first node I'm creating?" separately from every other node. With a dummy node sitting before the real list, every node — including the first — gets attached the exact same way, via `current->next = ...`. At the end, we just skip past the dummy with `dummyHead->next` to get the real answer.

## Key Takeaways

- Reverse digit order in the input actually simplifies this problem — no need to reverse anything yourself.
- The `carry` variable is what makes this feel like elementary-school addition, just automated.
- The loop condition `l1 || l2 || carry` is the subtle but important part: it's what correctly handles a leftover carry after both lists are exhausted (e.g., `5 + 5 = 10` produces an extra `1` node).