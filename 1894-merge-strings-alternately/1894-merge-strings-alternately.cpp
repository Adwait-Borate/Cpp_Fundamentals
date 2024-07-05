// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         string res="";
//         int i=0,j=0;
//         int w1length=word1.length();
//         int w2length=word2.length();

//         while(w1length!=0 || w2length!=0){
//             res+=word1[i];
//             w1length--;
//             i++;
//             res+=word2[j];
//             w2length--;
//             j++;
//         }

//         while(w1length!=0){
//             res+=word1[i];
//             w1length--;
//             i++;
//         }
//          while(w2length!=0){
//             res+=word2[j];
//             w2length--;
//             j++;
//         }
//         return res;
        
//     }
// };
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, j = 0;
        int w1length = word1.length();
        int w2length = word2.length();

        while (w1length != 0 || w2length != 0) {
            if (w1length != 0) {
                res += word1[i];
                i++;
                w1length--;
            }
            if (w2length != 0) {
                res += word2[j];
                j++;
                w2length--;
            }
        }

        return res;
    }
};
