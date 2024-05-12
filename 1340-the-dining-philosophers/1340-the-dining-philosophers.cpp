class DiningPhilosophers {
private:
    mutex fork[5];
    mutex table;

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher, function<void()> pickLeftFork,
                    function<void()> pickRightFork, function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        unique_lock<mutex> lckTable(table);
        unique_lock<mutex> lckForkLeft(fork[left]);
        unique_lock<mutex> lckForkRight(fork[right]);
        lckTable.unlock();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};