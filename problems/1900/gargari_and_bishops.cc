#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> board (n, vt<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    // Idea: Prefix sum array for the diagonals 
    // Value of a square = diagonal + antidiaogonal - square value

    // Forward diagonals
    vt<vt<ll>> psumarr (n, vt<ll> (n, -1));
    for (int i = 0; i < n; ++i) {
        psumarr[0][i] = board[0][i];
        psumarr[i][0] = board[i][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (psumarr[i][j] == -1) {
                int icpy = i;
                int jcpy = j;
                while (0<=icpy && icpy<n && 0<=jcpy && jcpy<n) {
                    psumarr[icpy][jcpy] = psumarr[icpy-1][jcpy-1] + board[icpy][jcpy];
                    icpy += 1;
                    jcpy += 1;
                }
                icpy -= 1;
                jcpy -= 1;
                int icpycpy = icpy;
                int jcpycpy = jcpy;
                while (0<=icpycpy && icpycpy<n && 0<=jcpycpy && jcpycpy<n) {
                    psumarr[icpycpy][jcpycpy] = psumarr[icpy][jcpy];
                    icpycpy -= 1;
                    jcpycpy -= 1;
                }
            }
        }
    }

    // Backward diagonals
    vt<vt<ll>> psumarrb (n, vt<ll> (n,-1));
    for (int i = 0; i < n; ++i) {
        psumarrb[0][i] = board[0][i];
        psumarrb[i][n-1] = board[i][n-1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = n-2; j > -1; --j) {
            if (psumarrb[i][j] == -1) {
                int icpy = i;
                int jcpy = j;
                while (0<=icpy && icpy<n && 0<=jcpy && jcpy<n) {
                    psumarrb[icpy][jcpy] = psumarrb[icpy-1][jcpy+1] + board[icpy][jcpy];
                    icpy += 1;
                    jcpy -= 1;
                }
                icpy -= 1;
                jcpy += 1;
                int icpycpy = icpy;
                int jcpycpy = jcpy;
                while (0<=icpycpy && icpycpy<n && 0<=jcpycpy && jcpycpy<n) {
                    psumarrb[icpycpy][jcpycpy] = psumarrb[icpy][jcpy];
                    icpycpy -= 1;
                    jcpycpy += 1;
                }
            }
        }
    }

    // Let "even" squares be white and "odd" squares be black
    vt<ll> best_w = {0,0,0};
    vt<ll> best_b = {0,0,1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // determine if square is even or odd
            if ((i+j) % 2 == 0) {
                // white
                if (psumarr[i][j] + psumarrb[i][j] - board[i][j] > best_w[0]) {
                    best_w = {psumarr[i][j] + psumarrb[i][j] - board[i][j], i, j};
                }
            } else {
                if (psumarr[i][j] + psumarrb[i][j] - board[i][j] > best_b[0]) {
                    best_b = {psumarr[i][j] + psumarrb[i][j] - board[i][j], i, j};
                }
            }
        }
    }
    cout << best_w[0] + best_b[0] << endl;
    cout << best_w[1] + 1 << " " << best_w[2] + 1 << " " << best_b[1] + 1 << " " << best_b[2] + 1 << endl;
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