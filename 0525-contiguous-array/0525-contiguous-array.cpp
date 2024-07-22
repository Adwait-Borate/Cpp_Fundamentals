// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n=nums.size();
//         int ans=0;
//         vector<int>prefixsum(n);
//         prefixsum[0]=nums[0];
//         for(int i=1;i<n;i++){
//             if(nums[i]==1){
//                 prefixsum[i]=prefixsum[i-1]+nums[i];
//                 if((i+1)==(2*prefixsum[i])){
//                   ans=prefixsum[i];
//                 }
//             }else{
//                 prefixsum[i]=prefixsum[i-1];
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; 
        int maxLength = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 1 ? 1 : -1);
            if (prefixMap.find(prefixSum) != prefixMap.end()) {
                maxLength = max(maxLength, i - prefixMap[prefixSum]);
            } else {
                prefixMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};
