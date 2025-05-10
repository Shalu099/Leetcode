class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>pop(3000);
        for(auto i :logs){
            pop[i[0]]++;
            pop[i[1]]--;
        }
        int maxi=0;
        int year;
        for(int i=1950;i<=2050;i++){
            pop[i]+=pop[i-1];
            if(pop[i]>maxi){
                maxi=pop[i];
                year=i;
            }
        }
        return year;

    }
};