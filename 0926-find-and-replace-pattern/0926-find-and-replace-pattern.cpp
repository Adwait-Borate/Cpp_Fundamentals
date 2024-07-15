// class Solution {
// public:
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//         vector<string> ans;
//         unordered_map<char, int> patternMap = countCharFrequency(pattern);

//         int len = pattern.length();
//         for (auto& i : words) {
//             if (i.length() == len) {
//                 unordered_map<char, int> wordMap = countCharFrequency(i);
//                 bool match = true;
//                 for (int j = 0; j < len; j++) {
//                     if (patternMap[pattern[j]] != wordMap[word[j]]) {
//                         match = false;
//                         break;
//                     }
//                 }
//                 if (match) {
//                     ans.push_back(word);
//                 }
//             }
//         }

//         return ans;
//     }

//     unordered_map<char, int> countCharFrequency(const string& str) {
//         unordered_map<char, int> frequency;
//         for (char c : str) {
//             frequency[c]++;
//         }
//         return frequency;
//     }
// };   // [49/50]


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> ans;

        for (auto& i : words) {
            if (matchesPattern(i, pattern)) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool matchesPattern(const string& word, const string& pattern) {

        unordered_map<char, char> w2p;
        unordered_map<char, char> p2w;

        for (int i = 0; i < word.length();i++) {
            char w = word[i];
            char p = pattern[i];

            if (w2p.count(w) && w2p[w] != p || p2w.count(p) && p2w[p] != w) {
                return false;
            }

            w2p[w] = p;
            p2w[p] = w;
        }

        return true;
    }
};
