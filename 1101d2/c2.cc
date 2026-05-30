#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, x, s;
    string u;
    cin >> n >> x >> s >> u;

    int ans = 0;
    int empty_tables = x;
    int seats_non_empty = 0;
    int a_non_empty = 0;
    for (auto p : u) {
        if (p == 'I') {
            if (empty_tables) {
                empty_tables -= 1;
                seats_non_empty += s - 1;
                ans += 1;
            }
        }
        if (p == 'E') {
            if (seats_non_empty) {
                seats_non_empty -= 1;
                ans += 1;
            } else {
                if (a_non_empty && empty_tables) {
                    a_non_empty -= 1;
                    empty_tables -= 1;
                    seats_non_empty += s - 1;
                    ans += 1;
                }
            }
        }
        if (p == 'A') {
            if (seats_non_empty) {
                seats_non_empty -= 1;
                a_non_empty += 1;
                ans += 1;
            } else {
                if (empty_tables) {
                    empty_tables -= 1;
                    seats_non_empty += s - 1;
                    ans += 1;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}