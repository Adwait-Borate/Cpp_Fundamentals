class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        set<char> uset;
        int maxi = 0;
        int start = 0, end = 0;
        while (start < len && end < len) {
            if (uset.find(s[end]) == uset.end()) {
                uset.insert(s[end]);
                end++;
                maxi = max(maxi, end - start);
            } else {
                uset.erase(s[start]);
                start++;
            }
        }
        return maxi;
    }
};

