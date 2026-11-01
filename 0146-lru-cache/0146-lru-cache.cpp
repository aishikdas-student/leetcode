
class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode) {
        Node* oldnext = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldnext;
        oldnext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldprev = oldNode->prev;
        Node* oldnext = oldNode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        int ans = m[key]->val;
        Node* ansNode = m[key];

        delNode(ansNode);
        addNode(ansNode);

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode;
        }

        if (m.size() == limit) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */