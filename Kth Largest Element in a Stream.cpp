class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);  // Add elements using the add function to maintain heap property
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            // Add the element directly if heap size is less than k
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            // Replace the smallest element if the new value is larger
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();  // The root is the kth largest element
    }
};