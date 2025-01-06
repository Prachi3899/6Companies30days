class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return dfs(price, special, needs, memo);
    }
    
private:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        // Generate a hash key for the current state of needs
        string key = encode(needs);
        if (memo.count(key)) return memo[key];
        
        // Cost without any special offers
        int cost = 0;
        for (int i = 0; i < needs.size(); ++i) {
            cost += needs[i] * price[i];
        }
        
        // Try all special offers
        for (const auto& offer : special) {
            vector<int> newNeeds = needs;
            bool valid = true;
            for (int i = 0; i < needs.size(); ++i) {
                newNeeds[i] -= offer[i];
                if (newNeeds[i] < 0) { // Offer exceeds current needs
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cost = min(cost, offer.back() + dfs(price, special, newNeeds, memo));
            }
        }
        
        // Memoize and return the result
        memo[key] = cost;
        return cost;
    }
    
    // Helper function to encode the state of needs as a string
    string encode(const vector<int>& needs) {
        string key;
        for (int n : needs) {
            key += to_string(n) + ",";
        }
        return key;
    }
};