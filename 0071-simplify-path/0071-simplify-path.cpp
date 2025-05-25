class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string canonical_path = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/')
                continue;
            string temp = "";
            while (i < path.size() && path[i] != '/') {
                temp += path[i++];
            }

            if (temp == ".")
                continue;
            else if (temp == "..") {
                if (!st.empty())
                    st.pop();
            } else
                st.push(temp);
        }
        while (!st.empty()) {
            canonical_path = '/' + st.top() + canonical_path;
            st.pop();
        }
        if (!canonical_path.size())
            return "/";
        else
            return canonical_path;
    }
};