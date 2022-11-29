class RandomizedSet {
public:
    unordered_set<int> rset;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(rset.find(val)==rset.end()){
            rset.insert(val);
            return true;
        }
        else{
            return false;
        }
        
    }
    
    bool remove(int val) {
        if(rset.find(val)==rset.end()){
            return false;
        }
        else{
            rset.erase(rset.find(val));
            return true;
        }
    }
    
    int getRandom() {
        auto it = rset.begin();
        int random = rand() % rset.size();
        advance(it,random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */