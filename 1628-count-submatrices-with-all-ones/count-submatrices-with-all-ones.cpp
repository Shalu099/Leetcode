class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> heights(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            // Step 1: Update heights (like histogram)
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j] += 1;
            }

            // Step 2: Use monotonic stack to count rectangles
            stack<int> st;
            vector<int> sum(n, 0);
            for (int j = 0; j < n; j++) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }
                if (!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + heights[j] * (j - prev);
                } else {
                    sum[j] = heights[j] * (j + 1);
                }
                st.push(j);
                result += sum[j];
            }
        }

        return result;
    }
};
