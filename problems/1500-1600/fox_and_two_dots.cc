#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

vt<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

bool dfs(int r, int c, pair<int,int> state, char target, vt<vt<char>>& grid, set<pair<int,int>>& visited) {
    if (visited.find(make_pair(r,c)) != visited.end()) return true;
    if (grid[r][c] != target) return false;
    visited.insert(make_pair(r,c));
    for (auto& [dr,dc] : directions) {
        if (dr*state.first != -1 && dc*state.second != -1) {
            if (0<=r+dr && r+dr<grid.size() && 0<=c+dc && c+dc<grid[0].size() && dfs(r+dr,c+dc,{dr,dc},target,grid,visited)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vt<vt<char>> grid(n, vt<char> (m));
    for (auto& r:grid) {
        for (auto& c:r) {
            cin >> c;
        }
    }

    bool cycle = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            set<pair<int,int>> visited;
            if (dfs(i,j,{0,0},grid[i][j], grid,visited)) {
                cycle = true;
            }
        }
    }
    if (cycle) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}