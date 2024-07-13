class Solution {
public:
    string findRoot(string& word, unordered_set<string>& uset) {
        for (int l = 1; l <= word.length(); l++) {
            string root = word.substr(0, l);
            if (uset.count(root)) {
                return root;
            }
            
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> uset(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string result;
        while (getline(ss, word, ' ')) {
            result += findRoot(word, uset) + " ";
        }
        result.pop_back();
        return result;
    }
};