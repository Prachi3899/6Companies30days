class Solution {
public:
    int findTheWinner(int n, int k) {
        // Create a vector to represent the circle of friends
        vector<int> friends;
        for (int i = 1; i <= n; ++i) {
            friends.push_back(i);
        }
        
        int currentIndex = 0; // Start from the first friend
        
        // Continue until only one friend remains
        while (friends.size() > 1) {
            // Calculate the index of the friend to be removed
            currentIndex = (currentIndex + k - 1) % friends.size();
            friends.erase(friends.begin() + currentIndex); // Remove the friend
        }
        
        // Return the last remaining friend
        return friends[0];
    }
};
