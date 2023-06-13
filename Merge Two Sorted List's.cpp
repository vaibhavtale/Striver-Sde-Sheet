// TC = O(N)
// SC = O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;   // If list1 is empty, return list2
        if (!list2) return list1;   // If list2 is empty, return list1

        ListNode* p1 = list1;   // Pointer for list1
        ListNode* p2 = list2;   // Pointer for list2
        ListNode* merged = new ListNode(-1);   // Dummy node for the merged list
        ListNode* m = merged;   // Pointer for the current node in the merged list

        // Merge the lists by comparing the values of the nodes
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                m->next = p1;
                m = m->next;
                p1 = p1->next;
            } else {
                m->next = p2;
                m = m->next;
                p2 = p2->next;
            }
        }

        // Attach the remaining nodes of list1 to the merged list
        while (p1) {
            m->next = p1;
            m = m->next;
            p1 = p1->next;
        }

        // Attach the remaining nodes of list2 to the merged list
        while (p2) {
            m->next = p2;
            m = m->next;
            p2 = p2->next;
        }

        return merged->next;   // Return the merged list (excluding the dummy node)
    }
};
