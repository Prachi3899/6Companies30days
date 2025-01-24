class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> dll; // Doubly linked list to store {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // Hash map to store key -> iterator to DLL

    void moveToFront(int key, int value) {
        dll.erase(cache[key]); // Remove old node
        dll.push_front({key, value}); // Add updated node to the front
        cache[key] = dll.begin(); // Update hash map with new position
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        int value = cache[key]->second; // Retrieve value
        moveToFront(key, value); // Move the node to the front
        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If key already exists, update value and move to front
            moveToFront(key, value);
        } else {
            // If key does not exist
            if (dll.size() == capacity) {
                // Remove least recently used (tail)
                auto lru = dll.back();
                cache.erase(lru.first); // Remove from hash map
                dll.pop_back(); // Remove from list
            }
            // Insert new key-value pair at the front
            dll.push_front({key, value});
            cache[key] = dll.begin();
        }
    }
};