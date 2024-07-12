// class Solution {
// public:
//     int removeSubstring(string &str, const string &sub, int value) {
//         size_t pos = str.find(sub);
//         int sum = 0;
//         while (pos != std::string::npos) {
//             sum += value;
//             str.erase(pos, sub.length());
//             pos = str.find(sub);
//         }
//         return sum;
//     }

//     int maximumGain(string s, int x, int y) {
//         int total = 0;
//         if (x > y) {
//             total += removeSubstring(s, "ab", x);
//             total += removeSubstring(s, "ba", y);
//         } else {
//             total += removeSubstring(s, "ba", y);
//             total += removeSubstring(s, "ab", x);
//         }
//         return total;
//     }
// };

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n     = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int removedPairsCount = (n - temp_first.length()) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (temp_first.length() - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

private:
    string removeSubstring(string& s, string& matchStr) {
        stack<char> st;

        for (char &ch : s) {
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string remainStr;
        while (!st.empty()) {
            remainStr.push_back(st.top());
            st.pop();
        }
        reverse(remainStr.begin(), remainStr.end());
        return remainStr;
    }
};
