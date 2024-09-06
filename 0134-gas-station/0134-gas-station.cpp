class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, curr_gas = 0;
        int idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i] - cost[i];
            curr_gas += gas[i] - cost[i];

            if (curr_gas < 0) {
                idx = i + 1;
                curr_gas = 0;
            }
        }

        return (total_gas < 0) ? -1 : idx;
    }
};