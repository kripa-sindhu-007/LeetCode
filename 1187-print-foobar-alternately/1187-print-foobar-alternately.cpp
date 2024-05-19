class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int x;

public:
    FooBar(int n) {
        this->n = n;
        this->x = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(x!=0) cv.wait(lock);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            x=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(x!=1) cv.wait(lock);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            x=0;
            cv.notify_all();
        }
    }
};