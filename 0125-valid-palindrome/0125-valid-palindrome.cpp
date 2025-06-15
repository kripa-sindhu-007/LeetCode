class Solution {
public:
    bool isPalindrome(string s) {
        string new_string = "";
        for (char ch : s) {
            if (!isalnum(ch))
                continue;
            else
                new_string += tolower(ch);
        }
        return check(new_string);
    }

private:
    bool check(string s) {
        int beg = 0;
        int end = s.length() - 1;
        while (beg < end) {
            if (s[beg++] != s[end--])
                return false;
        }
        return true;
    }
};