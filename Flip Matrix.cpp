class Solution {
public:
    int m;
    int n;
    int total;
    unordered_map<int, int> mapp;

    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }
    
    vector<int> flip() {
        int r = rand() % total--;

        int x = mapp.count(r)? mapp[r] : r;
        mapp[r] = mapp.count(total)? mapp[total] : total;

        return {x / n, x % n};
    }
    
    void reset() {
        mapp.clear();
        total = m * n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */