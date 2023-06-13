// TC = O(N)
// SC = O(1)

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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head; // Slow pointer initially at the head of the list
        ListNode* fast = head; // Fast pointer initially at the head of the list

        while (fast && fast->next) {
            slow = slow->next; // Move the slow pointer by one step
            fast = fast->next->next; // Move the fast pointer by two steps
        }

        return slow; // Return the middle node
    }
};
