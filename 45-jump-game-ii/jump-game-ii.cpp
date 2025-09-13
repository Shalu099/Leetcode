class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int farthest = 0;   // farthest we can reach in current step
        int end = 0;        // end of the current jump range
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            if (i == end) {   // we reached end of current jump range
                jumps++;
                end = farthest;
            }
        }
        
        return jumps;
    }
};
