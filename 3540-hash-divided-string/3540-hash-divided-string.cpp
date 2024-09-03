class Solution {
public:
    string stringHash(string s, int k) {
        vector<string> substring;
        int n = s.size();
        
        // Debugging: Check sizes and substrings
        cout << "Original string: " << s << endl;
        cout << "Length of string: " << n << ", k: " << k << endl;
        
        for (int i = 0; i + k <= s.size(); i = i + k) {
            string sub = s.substr(i,k);
            substring.push_back(sub);
            
            // Debugging: Check each substring
            cout << "Substring: " << sub << endl;
        }

        string res = "";
        for (auto it : substring) {
            int hash = 0;
            for (auto i : it) {
                hash += (int)(i-'a');
            }
            // Debugging: Check hash value for each substring
            cout << "Hash for substring \"" << it << "\": " << hash << endl;
            
            // To avoid going beyond the valid character range, use modulus 26
            res += 'a' + (hash % 26);
        }

        // Debugging: Check final result
        cout << "Final result: " << res << endl;
        
        return res;
    }
};