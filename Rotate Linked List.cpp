// TC = O(N)
// SC = O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, no rotation is needed
            return head;
        }

        int len = 1; // Variable to store the length of the list

        ListNode* tail = head; // Variable to track the tail of the list
        ListNode* result = NULL; // Variable to store the rotated list

        // Traverse to the end of the list and calculate its length
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        tail->next = head; // Connect the tail with the head to form a circular list

        k %= len; // Adjust k to handle cases where k > len (reduces unnecessary rotations)

        // Find the new tail position (len - k)th node from the start
        for (int i = 0; i < len - k; i++) {
            tail = tail->next;
        }

        result = tail->next; // The (len - k)th node becomes the new head of the rotated list
        tail->next = NULL; // Disconnect the list at the new tail position

        return result; // Return the rotated list
    }
};
