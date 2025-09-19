#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    unordered_map<string, int> table; // cell -> value
        int evalFormula(string formula) {
        int n = formula.size();
        int num = 0, result = 0, sign = 1;
        string token = "";
        
        for (int i = 0; i <= n; i++) {
            char c = (i < n ? formula[i] : '+'); // sentinel
            
            if (isalnum(c)) {
                token.push_back(c);
            } else {
                if (!token.empty()) {
                    if (isdigit(token[0])) {
                        num = stoi(token);
                    } else {
                        num = (table.count(token) ? table[token] : 0);
                    }
                    result += sign * num;
                    token.clear();
                }
                if (c == '+') sign = 1;
                else if (c == '-') sign = -1;
            }
        }
        return result;
    }
    
public:
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        table[cell] = value;
    }
    
    void resetCell(string cell) {
        table.erase(cell);
    }
    
    int getValue(string formula) {
        return evalFormula(formula);
    }
};

