class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end());
        string result = "";

        backtrack(nums, numSet, "", n, result);

        return result;
    }

private:
    void backtrack(vector<string>& nums, unordered_set<string>& numSet, string current, int n, string& result) {
        if (current.size() == n) {
            if (numSet.find(current) == numSet.end()) {
                result = current;
            }
            return;
        }

        for (char c : {'0', '1'}) {

            current.push_back(c);
            backtrack(nums, numSet, current, n, result);
            current.pop_back();

        }
    }
};
