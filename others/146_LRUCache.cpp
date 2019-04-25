class LRUCache {
private:
    struct ItemNode {
        int key, val;
        ItemNode *next, *prev;
        ItemNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };
    
    int capacity, count;
    // Map from key to the corresponding node.
    unordered_map<int, ItemNode*> table;
    ItemNode *head, *tail;
    
    void moveToHead(ItemNode *node) {
        ItemNode *prev = node->prev, *next = node->next;
        if (prev) {
            prev->next = next;
            if (next)
                next->prev = prev;
        }
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (table.find(key) == table.end())
            return -1;
        
        ItemNode *node = table[key];
        if (node == tail && tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // Move this node to head.
        if (node != head)
            moveToHead(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (table.find(key) != table.end()) {
            // Key already exists.
            ItemNode *node = table[key];
            node->val = value;
            if (node == tail && tail->prev) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            //Move the node to head.
            if (node != head)
                moveToHead(node);
        } else {
            // Create a new node, evict the least recently used node if needed.
            ItemNode *node = new ItemNode(key, value);
            node->next = head;
            if (head)
                head->prev = node;
            head = node;
            if (!tail)
                tail = node;
            table[key] = node;
            
            if (count == capacity) {
                // Remove the tail node.
                if (tail) {
                    ItemNode *prev = tail->prev;
                    if (prev)
                        prev->next = nullptr;
                    table.erase(tail->key);
                    delete tail;
                    tail = prev;
                }
            } else {
                ++count;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
