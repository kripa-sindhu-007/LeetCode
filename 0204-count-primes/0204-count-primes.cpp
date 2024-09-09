class Solution {
private:
    vector<bool> sieve;
    vector<int> primeCount;

    void helper(int n) {
        sieve = vector<bool>(n, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        primeCount.resize(n);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (sieve[i]) {
                count++;
            }
            primeCount[i] = count;
        }
    }

public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        if (sieve.size() < n) {
            helper(n);
        }

        return primeCount[n - 1];
    }
};
