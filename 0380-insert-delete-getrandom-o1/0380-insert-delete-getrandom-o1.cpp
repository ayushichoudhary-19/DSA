class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> vec;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false; 
        else {
            vec.push_back(val);
            m[val]=vec.size()-1;
            return true;}
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()) {
            int removeIndex=m[val]; 
    //copy last value of vec to this removable index and pop for O(1) removal
            int lastVal=vec.back();
            vec[removeIndex]=lastVal;
            vec.pop_back();
            //now that we have changes position of last value in vec to 
            //position removeIndex so change the mapping also
            m[lastVal]=removeIndex;
            //erase removed value's mapping
            m.erase(val); 
            return true;}
        else return false;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */