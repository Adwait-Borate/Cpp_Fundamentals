// class Solution {
// public:
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//         vector<string> ans;
//         unordered_map<char, int> patternMap = countCharFrequency(pattern);

//         int len = pattern.length();
//         for (auto& word : words) {
//             if (word.length() == len) {
//                 unordered_map<char, int> wordMap = countCharFrequency(word);
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
// };


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> ans;

        for (auto& word : words) {
            if (matchesPattern(word, pattern)) {
                ans.push_back(word);
            }
        }

        return ans;
    }

    bool matchesPattern(const string& word, const string& pattern) {
        if (word.length() != pattern.length()) {
            return false;
        }

        unordered_map<char, char> w2p; // word to pattern mapping
        unordered_map<char, char> p2w; // pattern to word mapping

        for (int i = 0; i < word.length(); ++i) {
            char w = word[i];
            char p = pattern[i];

            if (w2p.count(w) && w2p[w] != p) {
                return false;
            }
            if (p2w.count(p) && p2w[p] != w) {
                return false;
            }

            w2p[w] = p;
            p2w[p] = w;
        }

        return true;
    }
};
