class RandomizedSet {
private:
    vector<int> elements;
    unordered_map<int, int> valIndex;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valIndex.count(val) > 0)
            return false;
        int idx = elements.size();
        elements.push_back(val);
        valIndex[val] = idx;
        return true;
    }

    bool remove(int val) {
        if (valIndex.count(val) < 1)
            return false;
        int idxToRemove = valIndex[val];
        int lastEle = elements.back();
        elements[idxToRemove] = lastEle;
        valIndex[lastEle] = idxToRemove;
        elements.pop_back();
        valIndex.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % elements.size();
        return elements[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */