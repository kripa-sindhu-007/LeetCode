class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);
        stack<char> st;

        for (char ch : s)
            freq[ch - 'a']++;

        for (char c : s) {

            freq[c - 'a']--;

            if (vis[c - 'a'])
                continue;

            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            vis[c - 'a'] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            
            st.pop();
        }
        return ans;
    }
};