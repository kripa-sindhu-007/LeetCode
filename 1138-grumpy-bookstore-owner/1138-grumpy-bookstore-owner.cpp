class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, count = 0, notGrumpy = 0;
        for (int r = 0; r < customers.size(); r++) {
            if (grumpy[r] == 0)
                res += customers[r];
            else
                count += customers[r];
            notGrumpy = max(notGrumpy, count);
            if (r + 1 >= minutes && grumpy[r + 1 - minutes])
                count -= customers[r + 1 - minutes];
        }
        return res + notGrumpy;
    }
};