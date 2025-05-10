class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0)
        return 0;

        int ans=0,num=x,rem;
        while(num){
            rem=num%10;
            num/=10;

            if(ans>INT_MAX/10)
            return 0;
            ans=ans*10+rem;
        }
        if(x==ans){
            return true;
        }else{
            return false;
        }
    }
};