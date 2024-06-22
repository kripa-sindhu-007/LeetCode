class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int beg = 0;
        int end = s.size() - 1;
        while (beg < end) {
            if (isVowel(s[beg]) && isVowel(s[end])) {
                swap(s[beg], s[end]);
                beg++;
                end--;
            } else if (!isVowel(s[beg]))
                beg++;
            else if (!isVowel(s[end]))
                end--;
        }
        return s;
    }
};