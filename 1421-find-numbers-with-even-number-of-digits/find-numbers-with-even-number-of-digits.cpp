class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            // int digitcount=0;
            // while(nums[i]>0){
            //     nums[i]/=10;
            //     digitcount++;
            // }
            int length=to_string(nums[i]).length();
            if(length%2==0)
            count++;
        }
        return count;
    }
};