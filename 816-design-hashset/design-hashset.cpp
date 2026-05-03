class MyHashSet {
    vector<bool> mp;
public:
    MyHashSet(){ 
        mp = vector<bool>(1000001, 0);
    }
    void add(int key) {
        mp[key] = true;
    }
    
    void remove(int key) {
        mp[key] = false;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */