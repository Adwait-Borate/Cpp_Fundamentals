class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minH;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            minH.push(nums[i]);
        }

        while (!minH.empty()) {
            ans.push_back(minH.top());
            minH.pop();
        }

        return ans;
    }
};
