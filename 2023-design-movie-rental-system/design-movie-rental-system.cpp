#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    // price lookup
    unordered_map<long long, int> price; 
    
    // available[ movie ] = set of (price, shop)
    unordered_map<int, set<pair<int,int>>> available; 
    
    // rented = set of (price, shop, movie)
    set<tuple<int,int,int>> rented;

    // hash function for (shop,movie) pair
    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price[encode(shop, movie)] = p;
            available[movie].insert({p, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            for (auto &p : available[movie]) {
                res.push_back(p.second);
                if (res.size() == 5) break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int p = price[encode(shop, movie)];
        available[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = price[encode(shop, movie)];
        rented.erase({p, shop, movie});
        available[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &t : rented) {
            auto [p, shop, movie] = t;
            res.push_back({shop, movie});
            if (res.size() == 5) break;
        }
        return res;
    }
};
