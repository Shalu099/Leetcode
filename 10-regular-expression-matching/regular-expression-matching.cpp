class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();

        // dp[i][j] = true means s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;  // Empty string matches empty pattern

        // Handle patterns like a*, a*b*, etc., for empty string
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // '*' cancels previous char
            }
        }

        // Fill the table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // Direct match or '.'
                } else if (p[j - 1] == '*') {
                    if (j >= 2) {
                        // Zero occurrence of previous char
                        dp[i][j] = dp[i][j - 2];

                        // One or more occurrence if s[i-1] matches p[j-2]
                        if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                            dp[i][j] = dp[i][j] || dp[i - 1][j];
                        }
                    }
                }
            }
        }

        return dp[m][n];
    }
};
