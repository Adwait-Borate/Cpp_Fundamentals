// class Solution {
// public:
//     vector<string> findAndReplacePattern(vector<string>& words,
//                                          string pattern) {
//         unordered_map<char, int> patternMap;
//         string word="";
//         vector<string>ans;
//         string str="";
//         for (auto& i : pattern) {
//             patternMap[i]++;
//         }

//         unordered_map<char, int> countCharFrequency(string& word) {
//             unordered_map<char, int> frequency;
//             for (char c : word) {
//                 frequency[c]++;
//             }

//             return frequency;
//         }

//         int len = pattern.length();
//         for (int i = 0; i < len; i++) {
//             word=word[i];
//             if (word.length() == len) {
//                unordered_map<char, int> frequency = countCharFrequency(word);
//                for(int j=0;j<len;j++){
//                 if(patternMap[pattern[j]].second==frequency[word[j]].second){
//                     str+=word[j];
//                 }
//                }
//                ans.push_back(str);
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (auto& word : words) {
            if (matchesPattern(word, pattern)) {
                ans.push_back(word);
            }
        }

        return ans;
    }

private:
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

