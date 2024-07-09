class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0.0;
        int current_time = 0;

        for (const auto& customer : customers) {
            int arrival_time = customer[0];
            int cooking_time = customer[1];

            // If the chef is idle before the customer arrives, update
            // current_time to the arrival time
            if (current_time < arrival_time) {
                current_time = arrival_time;
            }

            // Calculate the waiting time for this customer
            int waiting_time = (current_time + cooking_time) - arrival_time;
            total_waiting_time += waiting_time;

            // Update the current time after the chef finishes cooking this
            // order
            current_time += cooking_time;
        }

        return total_waiting_time / customers.size();
    }
};
