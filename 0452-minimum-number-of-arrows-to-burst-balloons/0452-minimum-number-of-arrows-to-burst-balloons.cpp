// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//          int n = points.size();
//         int i = 0;
//         int j = 1;
//         int cnt = 0;
//         sort(points.begin(), points.end());
//         while (j < n) {
//             vector<int> currentInterval = points[i];
//             vector<int> nextInterval = points[j];

//             int currentStart = currentInterval[0];
//             int currentEnd = currentInterval[1];

//             int nextStart = nextInterval[0];
//             int nextEnd = nextInterval[1];

//             if (currentEnd <= nextStart) {
//                 i = j;
//                 j++;
//             } else if (currentEnd <= nextEnd) {
//                 j++;
//                 cnt++;
//             } else if (currentEnd > nextEnd) {
//                 i = j;
//                 j++;
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

       
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int i = 0;
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            int currentEnd = points[i][1];
            int nextStart = points[j][0];

            if (currentEnd < nextStart) {
                i = j;
                cnt++;
            }
        }
        return cnt;
    }
};
