class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int s_size=s.size();
        int t_size=t.size();

        while(i<s_size){
            if(s[i]==t[j]){
              i++;
              j++;
            }
            else{
                i++;
            }
        }
        int left=t_size-j;
        return left;
    }
};