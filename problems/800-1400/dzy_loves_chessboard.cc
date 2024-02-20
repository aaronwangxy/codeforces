#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

set<pair<int,int>> visited;
vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int i, int j, vt<vt<char>>& board, int cm) {
    if (0 <= i && i < board.size() && 0 <= j && j < board[0].size()
        && board[i][j] == '.' && visited.find({i,j}) == visited.end()) {
        visited.insert({i,j});
        if (cm) {
            board[i][j] = 'W';
            cm = 0;
        } else {
            board[i][j] = 'B';
            cm = 1;
        }
        for (auto& [dr,dc] : directions) {
            dfs(i + dr, j + dc, board, cm);
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vt<vt<char>> a(n, vt<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dfs(i, j, a, 0);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j];
        }
        cout << endl;
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