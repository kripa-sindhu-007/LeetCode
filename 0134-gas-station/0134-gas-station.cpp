class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost = 0;
        int curr_cost = 0;
        int starting_idx = 0;

        for (int i = 0; i < gas.size(); i++) {
            curr_cost += gas[i] - cost[i];
            if (curr_cost < 0) {
                starting_idx = i + 1;
                curr_cost = 0;
            }
            total_cost += gas[i] - cost[i];
        }
        return (total_cost < 0) ? -1 : starting_idx;
    }
};