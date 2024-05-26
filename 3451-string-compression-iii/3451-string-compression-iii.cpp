class Solution {
public:
    string compressedString(string word) {
        if(word.size()==1) return "1"+word;
        string comp="";
        for(int i=0;i<word.size();i++){
            int count=0;
            while(1){
                if(word[i]==word[i+1] && count<8){
                    count++;
                    i++;
                }
                else break;
                
            }
            comp+=to_string(count+1)+word[i];
        }
        // edge case for last char
        if(comp[comp.size()-1]!=word[word.size()-1]){
            comp+="1";
            comp+=word[word.size()-1];
        }
        return comp;
    }
};