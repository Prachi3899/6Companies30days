class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; // Start with one slot for the root
        int n = preorder.size();
        
        for (int i = 0; i < n; ++i) {
            if (preorder[i] == ',') {
                continue; // Skip commas
            }
            
            // Move to the next node
            if (slots == 0) {
                return false; // No slots available for this node
            }
            
            // Check if current node is a null node
            if (preorder[i] == '#') {
                --slots; // Null node consumes one slot
            } else {
                // It's a number, consume one slot and add two new slots
                while (i < n && preorder[i] != ',') {
                    ++i; // Skip the full number
                }
                --slots;
                slots += 2;
            }
        }
        
        return slots == 0; // All slots must be filled
    }
};
