class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> importance;

        // Calculate importance and pair with indices
        for (int i = 0; i < n; ++i) {
            importance.push_back({aliceValues[i] + bobValues[i], i});
        }

        // Sort by importance in descending order
        sort(importance.rbegin(), importance.rend());

        int aliceScore = 0, bobScore = 0;

        // Simulate the game
        for (int turn = 0; turn < n; ++turn) {
            int index = importance[turn].second;
            if (turn % 2 == 0) {
                // Alice's turn
                aliceScore += aliceValues[index];
            } else {
                // Bob's turn
                bobScore += bobValues[index];
            }
        }

        // Compare scores and return the result
        if (aliceScore > bobScore) return 1;
        if (bobScore > aliceScore) return -1;
        return 0;
    }
};
