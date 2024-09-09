class MinStack {
    int size;
    vector<pair<int, int>> arr;
    int curr_min = INT_MAX;

public:
    MinStack() { size = 0; }

    void push(int val) {

        curr_min = min(curr_min, val);
        arr.push_back({val, curr_min});
        size += 1;
    }

    void pop() {
        arr.pop_back();
        size -= 1;
        if (size > 0) {
            curr_min = arr[size - 1].second;
        } else {
            curr_min = INT_MAX;
        }
    }

    int top() { return arr[size - 1].first; }

    int getMin() { return arr[size - 1].second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */