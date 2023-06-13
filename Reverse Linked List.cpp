// TC = O(N)
// SC = O(N)

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
    ListNode* reverseList(ListNode* head) {
        
        // Base Case: If the list is empty or has only one node, return the head as it is already reversed.
        if (!head || !head->next) {
            return head;
        }

        // Using Stack:
        
        stack<ListNode*> st;

        while(head){

            st.push(head);
            head = head->next;
            st.top()->next = NULL;
        }

        ListNode* ans = new ListNode(-1), *p1 = ans;

        while(!st.empty()){

            p1->next = st.top();
            p1 = p1->next;
            st.pop();
        }

        return ans->next;
       

        // Using Three Pointers:

        ListNode* prev = NULL; // Pointer to the previous node
        ListNode* curr = head; // Pointer to the current node

        while (curr) {
            ListNode* nxt = curr->next; // Pointer to the next node
            curr->next = prev; // Reverse the next pointer of the current node to point to the previous node
            prev = curr; // Move the previous pointer to the current node
            curr = nxt; // Move the current pointer to the next node
        }

        return prev; // Return the new head of the reversed list
    }
};
