// TC = O(N)
// SC = O(1)

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            // If the list is empty or has less than 3 nodes, there can't be a cycle
            return false;
        }
        
        ListNode* slow = head; // Pointer to move one node at a time
        ListNode* fast = head; // Pointer to move two nodes at a time
        
        slow = slow->next;
        fast = fast->next->next;
        
        // Traverse the list until the fast pointer reaches the end or goes out of bounds
        while (fast && fast->next) {
            if (slow->next == fast->next) {
                // If the slow and fast pointers meet, there is a cycle
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If the loop completes without finding a cycle, there is no cycle
        return false;
    }
};
