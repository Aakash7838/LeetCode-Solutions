class LRUCache {
public:
    struct Node {
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr){}
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;  // most recent
    Node* tail;  // least recent

    LRUCache(int cap){
        capacity = cap;

        // dummy head aur tail
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Node ko front pe move karo
    void moveToFront(Node* node){
        // pehle remove karo
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // head ke baad add karo
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Front pe add karo
    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Tail se remove karo (LRU)
    Node* removeTail(){
        Node* lru = tail->prev;
        lru->prev->next = tail;
        tail->prev = lru->prev;
        return lru;
    }

    int get(int key){
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value){
        // Already exist karta hai
        if(mp.find(key) != mp.end()){
            mp[key]->val = value;
            moveToFront(mp[key]);
            return;
        }

        // Capacity full
        if((int)mp.size() == capacity){
            Node* lru = removeTail();
            mp.erase(lru->key);
            delete lru;
        }

        // Naya node add karo
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addToFront(newNode);
    }
};