class node {
public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    unordered_map<int, node*> map;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode) {
        node* temp = head->next;
        newNode->next = temp;
        head->next = newNode;
        newNode->prev = head;
        temp->prev = newNode;
    }
    void deleteNode(node* delNode) {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            node* resNode = map[key];
            int res = resNode->val;
            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            map[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            node* exNode = map[key];
            map.erase(key);
            deleteNode(exNode);
        }
        if (map.size() == cap) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */