class Solution {
public:
    // Function to delete `n` nodes after skipping `m` nodes
    Node* linkdelete(Node* head, int n, int m) {
       Node* node = head; 
    while(node!= nullptr) { 
      
      Node* prev = nullptr;
        // Skip m nodes 
        for (size_t i = 0; i < m && node!= nullptr; i++) 
        {
            prev = node;
            node = node->next; 
        }
        
        for (size_t i = 0; i < n && node!= nullptr; i++) { 
            Node* temp = node; 
            node = node->next; 
            delete temp; 
        } 
        
        // Link the previous list with
          // remaining nodes 
        prev->next = node; 
 
    } 
        return head;
    }
};