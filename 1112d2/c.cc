#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool valid(int j, int m, vt<int> interval) {
    return !(interval[0] <= j && j <= interval[1]) && !(interval[2] <= m-j+1 && m-j+1 <= interval[3]);
}

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> intervals(n, vt<int>(4));
    for (auto& i : intervals) {
        for (auto& v : i) {
            cin >> v;
        }
    }

    for (int m = n; m > 0; --m) {
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (valid(curr+1, m, intervals[i])) {
                curr += 1;
            }
        }
        if (curr >= m) {
            cout << m << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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