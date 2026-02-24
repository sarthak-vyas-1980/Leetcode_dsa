class Node {
    public: 
    Node* prev;
    Node* next;
    int val;
    Node(int d){
        prev = NULL;
        next = NULL;
        this->val = d;
    }
};
    void insertAtHead(Node* &head, Node* &tail, int key){
        Node* temp = new Node(key);
        if(head == NULL){
            head = temp;
            tail = temp;
            head->next = NULL;
            head->prev = NULL;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = NULL;
    }
    int deleteAtTail(Node* &head, Node* &tail){
        int ans = tail->val;
        if(tail == head){
            head = NULL;
            tail = NULL;
            return ans;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        if(tail == NULL) head = NULL;
        return ans;
    }
    void riseToTop(Node* &head, Node* &tail, int key){
        if(head == tail || head->val == key) return ;
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL && curr->val!=key){
            prev = curr;
            curr = curr->next;
        }
        if(curr->next == NULL) deleteAtTail(head, tail);
        else{
            prev->next = curr->next;
            curr->next->prev = prev;
            delete curr;
        }
        insertAtHead(head, tail, key);
    }
class LRUCache {
    unordered_map<int, int> hp;
    Node* lru;           //head
    Node* lruTail;
    int size;
public:
    LRUCache(int capacity) {
        lru = NULL;
        lruTail = NULL;
        this->size = capacity;
    }
    int get(int key) {
        if(hp.count(key)){
            riseToTop(lru, lruTail, key);
            return hp[key];
        }
        return -1;
    }
    void put(int key, int value) {
        if(hp.count(key)){
            hp[key] = value;
            riseToTop(lru, lruTail, key);
            return ;
        }
        //else
        hp[key] = value;
        insertAtHead(lru, lruTail, key);
        if(hp.size()>size){
            int delKey = deleteAtTail(lru, lruTail);
            hp.erase(delKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */