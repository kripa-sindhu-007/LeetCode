class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        if(words.size()!=pattern.size()) return false;

        unordered_map<char,string> patt_to_word;
        unordered_map<string,char> word_to_patt;

        for(int i=0;i<pattern.size();i++){
            char curr_pattern=pattern[i];
            string curr_word=words[i];

            if(patt_to_word.count(curr_pattern)){
                if(patt_to_word[curr_pattern]!=curr_word) return false;
            }else{
                if(word_to_patt.count(curr_word)){
                    if(word_to_patt[curr_word]!=curr_pattern) return false;
                }
            }
            patt_to_word[curr_pattern]=curr_word;
            word_to_patt[curr_word]=curr_pattern;
        }
        return true;
        
    }
};