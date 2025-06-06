class Solution {
private:
    void helper(string digits, vector<string>& allCombi, vector<string>& map,
                string currCombi, int idx) {
        if (idx == digits.size()) {
            allCombi.push_back(currCombi);
            return;
        }

        string alphaInDigit = map[digits[idx] - '0'];

        for (char ch : alphaInDigit) {
            currCombi += ch;
            helper(digits, allCombi, map, currCombi, idx + 1);
            currCombi.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> allCombi;
        if (digits.size() == 0)
            return allCombi;
        vector<string> map = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currCombi = "";
        int idx = 0;
        helper(digits, allCombi, map, currCombi, idx);
        return allCombi;
    }
};