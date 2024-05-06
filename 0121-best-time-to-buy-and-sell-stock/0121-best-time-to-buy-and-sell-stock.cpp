class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_min=prices[0];
        int max_profit=INT_MIN;

        for(int it:prices){
            max_profit=max(max_profit,it-prev_min);
            prev_min=min(prev_min,it);
        }
        
        return max_profit;
    }
};