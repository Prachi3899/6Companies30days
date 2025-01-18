class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store (value, node) pairs
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap: smallest value at the top
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // Push the head of each list into the heap
        for (auto list : lists) {
            if (list) minHeap.push(list);
        }

        // Dummy node to simplify result list construction
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Process the heap
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Add the smallest node to the result list
            current->next = smallest;
            current = current->next;

            // Push the next node from the same list into the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        // Return the merged list
        return dummy->next;
    }
};

