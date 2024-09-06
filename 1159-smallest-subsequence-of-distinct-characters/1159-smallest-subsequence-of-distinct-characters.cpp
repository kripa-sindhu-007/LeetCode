class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);
        stack<char> st;

        for (char c : s)
            freq[c - 'a']++;

        for (char c : s) {

            freq[c - 'a']--;

            if (vis[c - 'a'])
                continue;

            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            vis[c - 'a'] = true;
            st.push(c);
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};