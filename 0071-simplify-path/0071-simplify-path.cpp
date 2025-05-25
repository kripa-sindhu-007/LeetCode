class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string canonical_path = "";
        string dir = "";
        stringstream ss(path);

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".")
                continue;
            else if (dir == "..") {
                if (!st.empty())
                    st.pop();
            } else
                st.push(dir);
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