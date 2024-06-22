class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for (auto it : s) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' ||
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U')
                st.push(it);
        }

        string ans = "";
        for (auto it : s) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' ||
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') {
                char c = st.top();
                ans += c;
                st.pop();
            } else
                ans += it;
        }
        return ans;
    }
};