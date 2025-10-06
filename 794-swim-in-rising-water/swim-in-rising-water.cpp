#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int t = top[0], r = top[1], c = top[2];
            
            if(r == n - 1 && c == n - 1) return t;

            for(auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int newTime = max(t, grid[nr][nc]);
                    if(newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }
        return -1; 
    }
};
