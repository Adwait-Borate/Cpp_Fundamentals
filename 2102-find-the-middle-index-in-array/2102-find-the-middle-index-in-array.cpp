class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i++) {
            if (left == (right - nums[i])) {
                return i;
            }
            left += nums[i];
            right -= nums[i];
        }

        return -1;
    }
};