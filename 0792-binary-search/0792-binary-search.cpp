class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low,high;
        int ans=-1;
        int n=nums.size();
        low=0;high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target) {
                ans=mid;
                break;
            }
            else if (nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    
};