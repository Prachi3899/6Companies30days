class WordDictionary {
private:
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };
    
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }
        
        char ch = word[index];
        if (ch == '.') {
            // Explore all children for '.'
            for (auto& [key, child] : node->children) {
                if (dfs(child, word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            // Explore the specific child
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            return dfs(node->children[ch], word, index + 1);
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
