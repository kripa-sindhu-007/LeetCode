class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int temp1 = edges[0][0];
        int temp2 = edges[0][1];
        int temp3 = edges[1][0];
        int temp4 = edges[1][1];
        if (temp1 == temp3 || temp1 == temp4)
            return temp1;
        else if (temp2 == temp3 || temp2 == temp4)
            return temp2;
        return -1;
    }
};