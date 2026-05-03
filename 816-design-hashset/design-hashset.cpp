#include   <list>
class MyHashSet {
    list<int> l;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        if(contains(key)) return ;
        l.push_back(key);
    }
    
    void remove(int key) {
        auto it = l.begin();
        while(it != l.end()){
            if(*it == key){ 
                l.erase(it);
                break;
            }
            it++;
        }
    }
    
    bool contains(int key) {
        auto it = l.begin();
        while(it != l.end()){
            if(*it == key) return true;
            it++;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */