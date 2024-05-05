class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int i=1;i<=numRows;i++){
            vector<int>row;
            row.push_back(1);
            int val=1;

            for(int j=1;j<i;j++){
                
                val*=i-j;
                val/=j;
                row.push_back(val);
            }
            result.push_back(row);
        }
        return result;
    }
};