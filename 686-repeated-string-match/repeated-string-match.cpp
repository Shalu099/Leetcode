class Solution {
public:


int KMP_MATCH(string haystack, string needle) {
       int n=haystack.size();
        int m=needle.size();
    int first,second;
         for(int i=0;i<=n-m;i++){
           first=i;
           second=0;
          while(second<m)
          {
            if(haystack[first]!=needle[second])
            {
                break;
            }else
            {
                first++;
                second++;

            }

          }
          if(second==m)
          {
            return 1;
          }
         }
             return 0;
}
    int repeatedStringMatch(string a, string b) {
        if(a==b)
        return 1;
        int repeat=1;
        string temp=a;

        while(temp.size()<b.size())
        {
            temp+=a;
            repeat++;

        }
         // KMP Pattern search
           if(KMP_MATCH(temp,b)==1)
           return repeat;
         //TEMP+a,kmp search
         if(KMP_MATCH(temp+a,b)==1)
         return repeat+1;


         return -1;

    }
};