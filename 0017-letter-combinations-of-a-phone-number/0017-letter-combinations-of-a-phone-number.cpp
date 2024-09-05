class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        vector<string> map = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> all_combination;
        string curr = "";

        helper(all_combination, curr, map, 0, digits);
        return all_combination;
    }

private:
    void helper(vector<string>& all_combination, string& curr,
                vector<string>& map, int idx, string& digits) {
        if (idx == digits.size()) {
            all_combination.push_back(curr);
            return;
        }

        string characters = map[digits[idx] - '0'];

        for (char ch : characters) {
            curr += ch;  //choose
            helper(all_combination, curr, map, idx + 1, digits);  //explore
            curr.pop_back();  //backtrack
        }
    }
};