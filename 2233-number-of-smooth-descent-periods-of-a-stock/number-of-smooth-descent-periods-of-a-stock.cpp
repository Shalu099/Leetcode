class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long count = 1;   // length of current smooth descent

        for (int i = 0; i < prices.size(); i++) {
            if (i > 0 && prices[i] == prices[i - 1] - 1) {
                count++;       // continue smooth descent
            } else {
                count = 1;     // reset
            }
            ans += count;      // add all subarrays ending here
        }

        return ans;
    }
};
