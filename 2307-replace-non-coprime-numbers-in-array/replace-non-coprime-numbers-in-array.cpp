class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        
        for (int num : nums) {
            st.push_back(num);
            
            // Keep merging while top two are non-coprime
            while (st.size() > 1) {
                int a = st[st.size() - 2];
                int b = st.back();
                int g = gcd(a, b);
                
                if (g == 1) break; // coprime, stop merging
                
                long long lcm = 1LL * a / g * b;  // avoid overflow
                st.pop_back();
                st.pop_back();
                st.push_back((int)lcm);
            }
        }
        
        return st;
    }
};
