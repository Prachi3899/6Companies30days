class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int totalRequests = 0;

        for (int i = 0; i < n; ++i) {
            int ageX = ages[i];
            if (ageX <= 14) continue; // No one will satisfy the first condition for ages <= 14

            // Find the range of valid ages using binary search
            int minAge = 0.5 * ageX + 7;
            auto lowerBound = upper_bound(ages.begin(), ages.end(), minAge); // First age > minAge
            auto upperBound = upper_bound(ages.begin(), ages.end(), ageX);   // First age > ageX

            // Number of valid candidates
            int count = upperBound - lowerBound;
            if (lowerBound <= ages.begin() + i && ages.begin() + i < upperBound) {
                --count; // Exclude self
            }

            totalRequests += count;
        }

        return totalRequests;
    }
};