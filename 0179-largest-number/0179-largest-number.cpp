class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for (int it : nums) {
            num.push_back(to_string(it));
        }

        sort(num.begin(), num.end(),
             [](string& a, string& b) { return a + b > b + a; });

        string ans = "";
        for (string& it : num)
            ans += it;

        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};
