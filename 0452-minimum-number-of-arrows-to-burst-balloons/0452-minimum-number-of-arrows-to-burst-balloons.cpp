class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int cnt = 1;

        for(int i=1;i<n;i++){
            int currentStart=points[i][0];
            int currentEnd=points[i][1];

            int previousStart=prev[0];
            int previousEnd=prev[1];

            if(currentStart>previousEnd){ 
                cnt++;
                prev=points[i];
            }else{ //OVERLAP 
                prev[0]=max(previousStart,currentStart);
                prev[1]=min(previousEnd,currentEnd);
            }
        }
        return cnt;
    }
};