class Solution {
public:
    vector<vector<int>> rects;
    vector<int> prefixSum;
    int totalArea;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalArea = 0;

        for (auto& rect : rects) {
            int width = rect[2] - rect[0] + 1;
            int height = rect[3] - rect[1] + 1;
            totalArea += width * height;
            prefixSum.push_back(totalArea);
        }
    }

    vector<int> pick() {
        // Pick a rectangle based on weighted random sampling
        int target = rand() % totalArea;
        int rectIndex = lower_bound(prefixSum.begin(), prefixSum.end(), target + 1) - prefixSum.begin();

        // Randomly pick a point in the selected rectangle
        auto& rect = rects[rectIndex];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */