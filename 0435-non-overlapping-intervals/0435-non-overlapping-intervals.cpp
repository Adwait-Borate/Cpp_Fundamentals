class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i=0;
        int j=1;
        int cnt=0;
        sort(intervals.begin(),intervals.end());
        while(j<n){
            vector<int>currentInterval=intervals[i];
            vector<int>nextInterval=intervals[j];

            int currentStart=currentInterval[0];
            int currentEnd=currentInterval[1];

            int nextStart=nextInterval[0];
            int nextEnd=nextInterval[1];

            if(currentEnd<=nextStart){
                i=j;
                j++;
            }else if(currentEnd<=nextEnd){
                j++;
                cnt++;
            }else if(currentEnd>nextEnd){
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};