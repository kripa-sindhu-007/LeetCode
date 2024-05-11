class Solution {
public:
    int scoreOfString(string s) {
        int score=0;

        for(int i=0;i<s.size()-1;i++){
            score+=abs(int(s[i]-'0')-int(s[i+1]-'0'));
        }
        return score;
        
    }
};