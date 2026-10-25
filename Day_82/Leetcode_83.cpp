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