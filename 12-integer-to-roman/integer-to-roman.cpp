class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string>notation={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX", "V", "IV","I"};
      vector<int>val={1000,900,500,400,100,90,50,40,10,9,5,4,1};

      for(int pos=0;num>0;pos++){
        while(num>=val[pos]){
            roman+=notation[pos];
            num-=val[pos];

        }
      }
      return roman;
    }
};