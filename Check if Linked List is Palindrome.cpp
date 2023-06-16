// TC = O(N)
// SC = O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0; // Variable to store the length of the list

        ListNode *p = head, *p2 = head;

        // Calculate the length of the list
        while (p) {
            len++;
            p = p->next;
        }

        int dist = (len % 2) ? (len + 1) / 2 : len / 2; // Calculate the distance to the middle node

        // Move p2 to the middle node
        for (int i = 0; i < dist; i++) {
            p2 = p2->next;
        }

        ListNode* prev = NULL; // Pointer to track the previous node
        ListNode* curr = p2; // Pointer to reverse the second half of the list

        // Reverse the second half of the list
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Compare the reversed second half with the first half of the list
        while (prev) {
            if (head->val != prev->val) {
                return false; // If values are not equal, it's not a palindrome
            }
            head = head->next;
            prev = prev->next;
        }

        return true; // If all values match, it's a palindrome
    }
};
