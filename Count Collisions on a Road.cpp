class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int collisions = 0;

        // Step 1: Trim leading 'L' and trailing 'R' as they don't collide
        int left = 0, right = n - 1;
        while (left < n && directions[left] == 'L') left++;
        while (right >= 0 && directions[right] == 'R') right--;

        // Step 2: Count collisions in the remaining substring
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                collisions++;
            }
        }

        return collisions;
    }
};
