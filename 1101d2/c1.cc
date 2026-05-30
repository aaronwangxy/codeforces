#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
Only seat I if there are excess tables
Otherwise, prefer spamming A and E

Maybe: for every number of introverts, how many can we seat?
    - A should be spread out
*/
void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    int num_introverts = 0;
    for (auto c : u) {
        if (c == 'I') {
            num_introverts += 1;
        }
    }

    int ans = 0;
    for (int ni = 0; ni <= min(num_introverts, x); ++ni) {
        int curr_ans = 0;
        int i_tables = ni;
        int a_tables = x - ni;
        int seats_at_non_empty = 0;
        for (auto p : u) {
            if (p == 'I') {
                if (i_tables) {
                    i_tables -= 1;
                    seats_at_non_empty += s - 1;
                    curr_ans += 1;
                }
            }
            if (p == 'A') {
                if (a_tables) {
                    a_tables -= 1;
                    seats_at_non_empty += s - 1;
                    curr_ans += 1;
                } else {
                    if (seats_at_non_empty) {
                        curr_ans += 1;
                        seats_at_non_empty -= 1;
                    }
                }
            }
            if (p == 'E') {
                if (seats_at_non_empty) {
                    seats_at_non_empty -= 1;
                    curr_ans += 1;
                }
            }
        }
        ans = max(ans, curr_ans);
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