class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        int remaining;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<j && s[i]==ch){
                i++;
            }

            while(j>=i && s[j]==ch){
                j--;
            }

           
            

        }
         remaining=j-i+1;
        return remaining;
    }
};