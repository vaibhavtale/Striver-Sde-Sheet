// TC = O(N)
// SC = O(1)

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
      
        // Approach 1: Using a Set
        unordered_set<ListNode*> visited;
        
        while (head) {
            if (visited.count(head) > 0) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        
        return NULL;
        
        // Approach 2: Two Pointers (Floyd's Tortoise and Hare Algorithm)
        if (!head || !head->next) {
            // If the list is empty or has only one node, there can't be a cycle
            return NULL;
        }
        
        ListNode* slow = head; // Pointer to move one node at a time
        ListNode* fast = head; // Pointer to move two nodes at a time

        // Traverse the list to find the meeting point of the slow and fast pointers
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;

            if (fast) {
                // Move the fast pointer again if it's not at the end of the list
                fast = fast->next;
            } else {
                // If the fast pointer reaches the end, there is no cycle
                return NULL;
            }
            
            if (slow == fast) {
                // If the slow and fast pointers meet, there is a cycle
                fast = head; // Move the fast pointer back to the head
                
                // Traverse again from the head and the meeting point to find the node where the cycle begins
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                
                return slow; // Return the node where the cycle begins
            }
        }
        
        return NULL; // If no cycle is found, return NULL
    }
};
