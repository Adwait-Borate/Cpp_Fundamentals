class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        vector<int>vec;
        while(i<=j){
          vec.push_back((nums[i]+nums[j]));
          i++;
          j--;
        }
        int maxi=*max_element(vec.begin(),vec.end());
        return maxi;
    }
};