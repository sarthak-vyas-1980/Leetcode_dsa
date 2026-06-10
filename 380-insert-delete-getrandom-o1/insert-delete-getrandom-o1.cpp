class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        arr.push_back(val);
        mp[val] = arr.size()-1;  //Map stores the index of values for O(1) searching while deletion.
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;

        int ind = mp[val];
        int endVal = arr.back();
        arr[ind] = endVal;
        arr.pop_back();

        mp[endVal] = ind;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */