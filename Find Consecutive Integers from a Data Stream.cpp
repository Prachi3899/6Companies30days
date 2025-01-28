class DataStream {
private:
    int value;  // The target value to check for
    int k;      // The number of consecutive integers required
    int count;  // Tracks the current streak of `value`

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        this->count = 0;
    }
    
    bool consec(int num) {
        if (num == value) {
            count++; // Increment the streak
        } else {
            count = 0; // Reset the streak
        }
        return count >= k; // Return true if streak is long enough
    }
};
