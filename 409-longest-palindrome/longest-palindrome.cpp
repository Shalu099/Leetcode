class Solution {
public:
    int longestPalindrome(string s) {
       vector<int>lower(26,0) ,upper(26,0);
       for(int i=0;i<s.size();i++){
        if(s[i]>='a')
        lower[s[i]-'a']++;
        else
        upper[s[i]-'A']++;
       }
       int c=0;
       bool odd=0;
       for(int i=0;i<26;i++){
           if(lower[i]%2==0)
           c+=lower[i];
           else
           {
            c+=lower[i]-1;
            odd=1;

           }
           if(upper[i]%2==0)
           c+=upper[i];
           else
           {
            c+=upper[i]-1;
            odd=1;
           }
       }
       return c+odd;
    }
};