// TC = O(max(n, m))
// SC = O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (!headA || !headB) return NULL;

        // Brute Force: Check each node in headA with each node in headB
        
        ListNode* p = headA;

        while (p) {
            ListNode *q = headB;

            while (q) {
                if (q == p) return q;
                q = q->next;
            }
            p = p->next;
        }
       

        // Using Map: Store nodes of headA in a map, then check each node in headB if it exists in the map
        
        unordered_map<ListNode*, bool> mp;

        while (headA) {
            mp[headA] = true;
            headA = headA->next;
        }

        while (headB) {
            if (mp.find(headB) != mp.end()) return headB;
            headB = headB->next;
        }
       

        // Without Extra Space:
        ListNode *p = headA, *q = headB;
        
        // Calculate the lengths of both linked lists
        
        int len = 0, len2 = 0;
        while (headA) {
            len++;
            headA = headA->next;
        }

        while (headB) {
            len2++;
            headB = headB->next;
        }

        // Find the difference in lengths and adjust the pointers to have equal remaining length
        
        int d = abs(len - len2);

        if (len > len2) {
            while (d--) {
                p = p->next;
            }
        }
        else {
            while (d--) {
                q = q->next;
            }
        }
       

        // Traverse both linked lists until a common node is found
        
        while (p && q) {
            if (p == q) return p;
            p = p->next; 
            q = q->next;
        }
       

        // Traverse both linked lists until a common node is found (optimized)
        while (p && q) {
            if (p == q) return p;

            p = p->next;
            q = q->next;

            // If both pointers reach the end without a common node, return NULL
            if (!p && !q) return NULL;

            // Reset the pointer to the head of the other linked list if it reaches the end
            if (p == nullptr) p = headB;
            if (q == nullptr) q = headA;   
        }

        return NULL;
    }
};
