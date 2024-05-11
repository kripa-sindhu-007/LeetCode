class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {

        int total_rec=1;

        sort(points.begin(),points.end());

        int start_rec=points[0][0];

        for(auto it:points){
            if(it[0]<=start_rec+w) continue;
            else {
                start_rec=it[0];
                total_rec++;
            }
        }


        return total_rec;
        
    }
};