#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end());
        int m = potions.size();

        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell; // ceiling of success/spell
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int count = potions.end() - it;
            result.push_back(count);
        }

        return result;
    }
};
