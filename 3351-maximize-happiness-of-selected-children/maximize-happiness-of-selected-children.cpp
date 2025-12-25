class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort happiness in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long total = 0;

        for (int i = 0; i < k; i++) {
            int curr = happiness[i] - i;
            if (curr > 0) {
                total += curr;
            }
        }

        return total;
    }
};
