// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         int carry=0;
//         int sum=0;
//         int n1len=num1.size();
//         int n2len=num2.size();
//         string ans="";
//         while(n1len>0 && n2len>0){
//             int n1=num1[n1len-1]-'0';
//             int n2=num2[n2len-1]-'0';
//             int sum=n1+n2+carry;
//             ans+=to_string(sum%10);
//             carry=sum/10;
//             n1len--;
//             n2len--;
//             sum=0;
//         }

//         while(n1len){
//             int add1=carry+num1[n1len-1]-'0';
//             ans+=num1[n1len-1];
//         }

//         while(n2len){
//             int add2=carry+num2[n2len-1]-'0';
//             ans+=num2[n2len-1];
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int n1len = num1.size();
        int n2len = num2.size();
        string ans = "";

        while (n1len > 0 && n2len > 0) {
            int n1 = num1[n1len - 1] - '0';
            int n2 = num2[n2len - 1] - '0';
            int sum = n1 + n2 + carry;
            ans += to_string(sum % 10);
            carry = sum / 10;
            n1len--;
            n2len--;
            sum=0;
        }

        while (n1len > 0) {
            int add1 = carry + (num1[n1len - 1] - '0');
            ans += to_string(add1 % 10);
            carry = add1 / 10;
            n1len--;
        }

        while (n2len > 0) {
            int add2 = carry + (num2[n2len - 1] - '0');
            ans += to_string(add2 % 10);
            carry = add2 / 10;
            n2len--;
        }

        if (carry > 0) {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
