class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        
        queue<TreeNode*> q;
        q.push(root);
        string result = "[";
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        
        // Remove trailing comma and close the bracket
        result.pop_back();
        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        
        // Remove brackets and split by commas
        data = data.substr(1, data.size() - 2);
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Process left child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
            }
            
            // Process right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->right = new TreeNode(stoi(item));
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};