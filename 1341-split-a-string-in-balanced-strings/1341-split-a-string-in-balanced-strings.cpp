class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int n = s.size();
        int L = 0;
        int R = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                L++;
            } else {
                R++;
            }
            if (L == R) {
                count++;
            }
        }
        return count;
    }
};