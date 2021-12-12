class RandomizedSet {

    vector<int>v;
    unordered_map<int,int>mp;
    int size = 0;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val) != 0)return false;
        mp[val] = size++;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val) == 0)return false;
        int idx = mp[val];
        v[idx] = v[size-1];
        v.pop_back();
        mp[v[idx]] = idx;
        mp.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */