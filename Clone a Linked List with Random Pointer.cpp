// TC = O(N)
// SC = O(N)

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create a dummy node as the starting point of the copied list
        Node* ans = new Node(-1);
        Node* res = ans;
        
        // Create a map to store the mapping between original nodes and copied nodes
        std::unordered_map<Node*, Node*> mp2;

        // Iterate through the original list
        Node* temp = head;
        while (temp) {
            // Create a new node with the same value as the original node
            Node* nn = new Node(temp->val);
            
            // Connect the new node to the copied list
            res->next = nn;
            res = res->next;
            
            // Store the mapping between the original node and the copied node in the map
            mp2[temp] = nn; 
            
            // Move to the next node in the original list
            temp = temp->next;
        }

        // Connect the last node of the copied list to NULL
        res->next = NULL;

        // Iterate through the original list again to copy the random pointers
        Node* p1 = head;
        Node* p2 = ans->next;
        while (p1) {
            if (p1->random == NULL) {
                // If the original node has a NULL random pointer, set the copied node's random pointer to NULL as well
                p2->random = NULL;
            } else {
                // Set the copied node's random pointer to the copied node corresponding to the original node's random pointer
                p2->random = mp2[p1->random];
            }

            // Move to the next nodes in both the original and copied lists
            p1 = p1->next;
            p2 = p2->next;
        }

        return ans->next;
    }
};
