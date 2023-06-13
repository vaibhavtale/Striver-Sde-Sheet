// TC = O(N)
//SC = O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Base Case: If the list is empty, return the head
        if (!head) return head;

        // Approach I: Calculate the length of the linked list and remove the nth node

        int len = 0;
        ListNode* p = head, *p2 = head;

        // Traverse the list to calculate its length
        while (p) {
            len++;
            p = p->next;
        }

        int k = len - n;

        // If k is 0, remove the head node and return the new head
        if (k == 0) return head->next;

        // Traverse to the node just before the nth node
        while (--k) p2 = p2->next;

        ListNode* todelete = p2->next;
        p2->next = p2->next->next;
        delete todelete;

        // Optimal Approach: Use two pointers to find the node to be removed

        p = head;
        p2 = head;

        // Move the first pointer n positions ahead
        while (p && n--) p = p->next;

        // If the first pointer reaches the end, remove the head node and return the new head
        if (!p) return head->next;

        // Move both pointers until the first pointer reaches the end
        while (p->next) {
            p = p->next;
            p2 = p2->next;
        }

        todelete = p2->next;
        p2->next = p2->next->next;
        delete todelete;

        return head;
    }
};
