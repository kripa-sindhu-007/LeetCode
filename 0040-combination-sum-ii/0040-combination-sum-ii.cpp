class Solution {
public:
     void solve(vector<int>& candidates, int target, vector<vector<int>>& result,
               vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            //combination.clear();
            return;
        }
        for (int i = start; i < candidates.size();++i) {

           if(i>start && candidates[i]==candidates[i-1]) continue;
           if(candidates[i]>target) break;
           combination.push_back(candidates[i]);
           solve(candidates,target-candidates[i],result,combination,i+1);
           combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, result, combination, 0);
        // set<vector<int>> temp;
        // for(auto it:result) temp.insert(it);     //very bad approch but works :)
        // result.clear();
        // for(auto it:temp) result.push_back(it);
        return result;
    }
};