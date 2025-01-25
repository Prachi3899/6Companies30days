class ThroneInheritance {
private:
    string king; // The name of the king
    unordered_map<string, vector<string>> familyTree; // Adjacency list for the family tree
    unordered_set<string> dead; // Set of deceased individuals

public:
    // Constructor: Initialize with the king's name
    ThroneInheritance(string kingName) : king(kingName) {
        familyTree[king] = {};
    }
    
    // Birth: Add a child to the parent's list
    void birth(string parentName, string childName) {
        familyTree[parentName].push_back(childName);
    }
    
    // Death: Mark a person as deceased
    void death(string name) {
        dead.insert(name);
    }
    
    // Get the inheritance order using DFS
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }

private:
    // Depth-First Search helper function
    void dfs(const string& person, vector<string>& order) {
        if (!dead.count(person)) {
            order.push_back(person); // Add to order if the person is alive
        }
        // Recurse through the person's children
        for (const string& child : familyTree[person]) {
            dfs(child, order);
        }
    }
};
