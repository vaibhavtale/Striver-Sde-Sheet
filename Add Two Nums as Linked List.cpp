// TC = O(max(N, M))
// SC = O(max(N, M))

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
        
        // Base Case: If one list is empty, return the other list
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* p1 = l1, *p2 = l2, *result = new ListNode(-1), *p3 = result;

        int carry = 0;

        // Traverse both lists and add the corresponding digits
        while (p1 && p2) {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            p3->next = temp;
            p3 = p3->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        // If there are remaining nodes in l1, add them to the result
        while (p1) {
            int sum = p1->val + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            p3->next = temp;
            p3 = p3->next;
            p1 = p1->next;
        }

        // If there are remaining nodes in l2, add them to the result
        while (p2) {
            int sum = p2->val + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            p3->next = temp;
            p3 = p3->next;
            p2 = p2->next;
        }

        // If there is a remaining carry, add it as a new node to the result
        if (carry) p3->next = new ListNode(carry);

        return result->next;
    }
};
