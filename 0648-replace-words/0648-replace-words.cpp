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

        string word;
        string result;
        int start = 0;

        for (int i = 0; i <= sentence.length(); ++i) {
            if (i == sentence.length() || sentence[i] == ' ') {
                word = sentence.substr(start, i - start);
                result += findRoot(word, uset) + " ";
                start = i + 1;
            }
        }
        result.pop_back();

        return result;
    }
};
