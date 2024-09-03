class FrontMiddleBackQueue {
public:
    deque<int> first_half, second_half;
    
    FrontMiddleBackQueue() {
        // constructor
    }

    void balance() {
        // Balance the deques such that first_half.size() == second_half.size() 
        // or first_half.size() == second_half.size() + 1
        if (first_half.size() > second_half.size() + 1) {
            second_half.push_front(first_half.back());
            first_half.pop_back();
        } else if (second_half.size() > first_half.size()) {
            first_half.push_back(second_half.front());
            second_half.pop_front();
        }
    }
    
    void pushFront(int val) {
        first_half.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if (first_half.size() > second_half.size()) {
            second_half.push_front(first_half.back());
            first_half.pop_back();
        }
        first_half.push_back(val);
    }
    
    void pushBack(int val) {
        second_half.push_back(val);
        balance();
    }
    
    int popFront() {
        if (first_half.empty() && second_half.empty()) return -1;

        int result;
        if (!first_half.empty()) {
            result = first_half.front();
            first_half.pop_front();
        } else {
            result = second_half.front();
            second_half.pop_front();
        }
        balance();
        return result;
    }
    
    int popMiddle() {
        if (first_half.empty() && second_half.empty()) return -1;

        int result;
        if (first_half.size() == second_half.size()) {
            result = first_half.back();
            first_half.pop_back();
        } else {
            result = first_half.back();
            first_half.pop_back();
        }
        balance();
        return result;
    }
    
    int popBack() {
        if (first_half.empty() && second_half.empty()) return -1;

        int result;
        if (!second_half.empty()) {
            result = second_half.back();
            second_half.pop_back();
        } else {
            result = first_half.back();
            first_half.pop_back();
        }
        balance();
        return result;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
