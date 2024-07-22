// class Solution {
// public:
//     int largestAltitude(vector<int>& gain) {
       
//         int n=gain.size();
//          vector<int>diff(n);
//         diff[0]=0;
//         diff[1]=gain[0];

//         for(int i=2;i<n;i++){
//           diff[i]=diff[i-1]+gain[i-1];
//         }
//         int maxi=*max_element(diff.begin(),diff.end());

//         return maxi; 
//     }
// };

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> diff(n+1); 

        diff[0] = 0;
        diff[1] = gain[0];

        for (int i = 2; i <= n; i++) {
            diff[i] = diff[i - 1] + gain[i - 1];
        }

        int maxi = *max_element(diff.begin(), diff.end());
        return maxi;
    }
};
