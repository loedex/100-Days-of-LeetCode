# 83. Remove Duplicates from Sorted List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Linked%20List-orange)

## Problem Statement

Given the `head` of a **sorted** linked list, delete all duplicates such that each element appears only once. Return the linked list **sorted** as well.

### Example 1

```
Input:  head = [1,1,2]
Output: [1,2]
```

### Example 2

```
Input:  head = [1,1,2,3,3]
Output: [1,2,3]
```

### Constraints

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be sorted in ascending order.

---

## Approach

Because the list is **sorted**, all duplicate values are adjacent to one another. This means a single pass with one pointer is enough; no extra data structure (such as a hash set) is needed.

### Algorithm

1. If the list is empty (`head == nullptr`), return `nullptr`.
2. Initialize a pointer `current` at `head`.
3. While `current` and `current->next` both exist:
   - If `current->val == current->next->val`, the next node is a duplicate. Unlink it by setting `current->next = current->next->next`, and free the removed node.
   - Otherwise, advance `current` to `current->next`.
4. Return `head`.

> **Note:** `current` is intentionally not advanced after removing a duplicate, since the new `current->next` may also be a duplicate (e.g. `1 -> 1 -> 1 -> 2`).

### Dry Run

Input: `[1, 1, 2, 3, 3]`

| Step | `current` | `current->next` | Action                | List State          |
|------|-----------|-----------------|-----------------------|---------------------|
| 1    | 1         | 1               | Equal, remove next    | 1 → 2 → 3 → 3       |
| 2    | 1         | 2               | Different, move ahead | 1 → 2 → 3 → 3       |
| 3    | 2         | 3               | Different, move ahead | 1 → 2 → 3 → 3       |
| 4    | 3         | 3               | Equal, remove next    | 1 → 2 → 3           |
| 5    | 3         | `nullptr`       | Loop ends             | **1 → 2 → 3**       |

---

## Solution (C++)

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Duplicate found: skip the next node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Optional: free memory
            } else {
                // No duplicate: move forward
                current = current->next;
            }
        }

        return head;
    }
};
```

---

## Complexity Analysis

| Metric | Complexity | Explanation                                                |
|--------|------------|------------------------------------------------------------|
| Time   | **O(n)**   | Each node is visited at most once.                         |
| Space  | **O(1)**   | Only a constant number of pointers is used; list is modified in place. |

---

## Submission Result

| Metric  | Result                      |
|---------|-----------------------------|
| Status  | Accepted (168 / 168 passed) |
| Runtime | 1 ms (beats 9.24%)          |
| Memory  | 16.24 MB (beats 32.06%)     |

---

## Key Takeaways

- Sorted input means duplicates are always adjacent, so one pass is sufficient.
- Only advance the pointer when no duplicate is removed.
- Handle the empty-list edge case up front.

## Link

[LeetCode: Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)