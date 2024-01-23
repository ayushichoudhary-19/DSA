#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // since we have to simultaneously rot all oranges, we use bfs
        queue<pair<pair<int, int>, int>> rotten; //{(coordinates x,y), minutes}

        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0; // No fresh oranges, no need to rot anything
        }

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        int tm = 0;

        while (!rotten.empty()) {
            int r = rotten.front().first.first;
            int c = rotten.front().first.second;
            int t = rotten.front().second;
            rotten.pop();
            tm = max(t, tm);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                    fresh--;
                    grid[nrow][ncol] = 2;
                    rotten.push({{nrow, ncol}, t + 1});
                }
            }
        }

        return (fresh == 0) ? tm : -1; // If there are still fresh oranges, return -1; otherwise, return minutes.
    }
};
