class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0, contentChildren = 0;

        // Match cookies to children
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { 
                // Cookie satisfies the child's greed
                contentChildren++;
                i++; // Move to the next child
            }
            j++; // Move to the next cookie
        }

        return contentChildren;
    }
};
