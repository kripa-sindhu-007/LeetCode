class Solution {
public:
    int getLucky(string s, int k) {
        string st;
        for (char ch : s) {
            int temp = ch - 'a' + 1;
            st += to_string(temp);
        }
        // long long int_val=stoi(st);

        int ans;
        while (k--) {
            ans = 0;
            for (char ch : st) {
                ans = ans + (int)(ch - '0');
            }
            st = to_string(ans);
        }
        return ans;
    }
};