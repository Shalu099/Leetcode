class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        // Order of business lines
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> valid; // (businessOrder, code)

        for (int i = 0; i < code.size(); i++) {
            // Condition 3: must be active
            if (!isActive[i]) continue;

            // Condition 2: valid business line
            if (order.find(businessLine[i]) == order.end()) continue;

            // Condition 1: valid code
            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({order[businessLine[i]], code[i]});
        }

        // Sort by business line order, then by code
        sort(valid.begin(), valid.end());

        // Extract codes
        vector<string> result;
        for (auto& p : valid) {
            result.push_back(p.second);
        }

        return result;
    }
};


