class SmallestInfiniteSet {
public:
    set<int>ele_present;
    int smallest;
    SmallestInfiniteSet() {
        smallest=1;
        
    }
    
    int popSmallest() {
        if(!ele_present.empty()){
            int element=*ele_present.begin();
            ele_present.erase(ele_present.begin());
            return element;
        }
        else return smallest++;
        
    }
    
    void addBack(int num) {
        if(num<smallest)
            ele_present.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */