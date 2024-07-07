class Solution {
public:
    bool isAnagram(string s, string t) {
        int sl = s.size();
        int tl = t.size();
        if (sl != tl) {
            return false;
        }
        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Compare the sorted strings
        return s == t;
    }
};
