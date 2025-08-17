class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If we never draw (k == 0) or even the maximum possible sum while drawing can't exceed n
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        std::vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double window = 1.0; // sum of dp[i-1], dp[i-2], ..., dp[i-maxPts] but only for indices < k
        double ans = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = window / maxPts;

            if (i < k) {
                // Still drawing from this state; include it in the window
                window += dp[i];
            } else {
                // We've stopped drawing; this contributes directly to the answer
                ans += dp[i];
            }

            // Remove the term that slides out of the window (only if it was a "drawing" state)
            if (i - maxPts >= 0 && i - maxPts < k) {
                window -= dp[i - maxPts];
            }
        }
        return ans;
    }
};
