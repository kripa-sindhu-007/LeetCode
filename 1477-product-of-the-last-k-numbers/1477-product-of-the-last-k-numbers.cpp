class ProductOfNumbers {
public:
    vector<int> queue;
    ProductOfNumbers() {
        // Constructor
    }
    
    void add(int num) {
        queue.push_back(num);
    }
    
    int getProduct(int k) {
        int32_t ans = 1;
        int size = queue.size();
        if (k > size) return 0;  // Avoid out-of-bounds access
        
        for (int i = size - 1; i >= size - k; i--) {
            if (queue[i] == 0) return 0;  // Zero handling: product becomes 0
            ans *= queue[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */