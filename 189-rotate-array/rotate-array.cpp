class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        auto reverse=[&](int s,int e){
            while(s<e){
                swap(nums[s++],nums[e--]);
            }
        };
        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);
    }
};