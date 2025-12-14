class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        vector<int> seatPos;
        
        // Store positions of all seats
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seatPos.push_back(i);
            }
        }
        
        int totalSeats = seatPos.size();
        
        // Invalid cases
        if (totalSeats == 0 || totalSeats % 2 != 0) {
            return 0;
        }
        
        long long ways = 1;
        
        // Process each pair of seat-groups
        for (int i = 2; i < totalSeats; i += 2) {
            int left = seatPos[i - 1];
            int right = seatPos[i];
            
            int plantsBetween = right - left - 1;
            ways = (ways * (plantsBetween + 1)) % MOD;
        }
        
        return ways;
    }
};
