class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current;
        unordered_set<int> next;

        for (int num : arr) {
            next.clear();
            next.insert(num);

            for (int x : current) {
                next.insert(x | num);
            }

            current = next;

            for (int x : current) {
                result.insert(x);
            }
        }

        return result.size();
    }
};
