class Solution {
public:
    int minOperations(int k) {
        if (k == 1)
            return 0;
        int mini = INT_MAX;
        for (int i = 1; i < k; i++) {
            int diff = i - 1, diff2 = k - i, tmp = diff2 % i;
            mini = min(mini, diff + diff2 / i + (tmp ? 1 : 0));
        }
        return mini;
    }
};