class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate the squared distance from the circle's center to the closest point
        int distanceSquared = (xCenter - closestX) * (xCenter - closestX) +
                              (yCenter - closestY) * (yCenter - closestY);

        // Compare squared distance with squared radius
        return distanceSquared <= radius * radius;
    }
};
