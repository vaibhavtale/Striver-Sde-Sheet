// TC = O(n * k)
// SC = O(K)

/* Node structure used in the program */
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/* Function to merge two sorted linked lists */
Node* merge(Node* first, Node* second){
    // If first linked list is empty, return second linked list
    if(!first) return second;
    
    // If second linked list is empty, return first linked list
    if(!second) return first;
    
    Node *dummy = new Node(-1), *p = dummy;
    
    // Merge the two linked lists in sorted order
    while(first && second){
        if(first->data <= second->data){
            p->bottom = first;
            first = first->bottom;
        }
        else{
            p->bottom = second;
            second = second->bottom;
        }
        p = p->bottom;
    }
    
    // Append any remaining nodes from the first or second list
    if(first) p->bottom = first;
    else p->bottom = second;
    
    return dummy->bottom;
}

/* Function which returns the root of the flattened linked list */
Node *flatten(Node *root){
    // If the root is empty or has no next node, return the root
    if(!root || root->next == NULL) return root;
    
    // Recursively flatten the next node
    root->next = flatten(root->next);
    
    // Merge the current root with the flattened next node
    merge(root, root->next);
    
    return root;
}
