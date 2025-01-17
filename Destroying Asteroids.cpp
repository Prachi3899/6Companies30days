class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Sort the asteroids by mass
        sort(asteroids.begin(), asteroids.end());

        long long currentMass = mass; // Use long long to avoid overflow

        // Simulate collisions
        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) {
                currentMass += asteroid; // Gain the mass of the asteroid
            } else {
                return false; // Planet cannot destroy this asteroid
            }
        }

        return true; // All asteroids destroyed
    }
};
