class Solution {
public:
    int findComplement(int n) {
      if(n==0)
        return 1;
        int ans=0,rem;
        long long mul=1;
        
        while(n){
          rem=n%2;
          rem^=1;
          n/=2;
          ans=ans+rem*mul;
          mul*=2;
        }
        return ans;
    }
};