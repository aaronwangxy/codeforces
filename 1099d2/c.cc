#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    unordered_map<int, int> steps_to_reach;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> path;
        int steps = 0;
        int a = arr[i];
        if (a == 1) {
            path[1] = 0;
            path[2] = 1;
        } else {
            while (a != 1) {
                path[a] = steps;
                steps += 1;
                if (a % 2) {
                    a += 1;
                } else {
                    a /= 2;
                }
            }
            path[1] = steps;
        }
        if (i == 0) {
            steps_to_reach = path;
            continue;
        }
        vt<int> to_remove;
        for (auto it = steps_to_reach.begin(); it != steps_to_reach.end(); ++it) {
            auto target = it->first;
            if (path.find(target) == path.end()) {
                to_remove.push_back(target);
            } else {
                steps_to_reach[target] += path[target];
            }
        }
        for (auto v : to_remove) {
            steps_to_reach.erase(v);
        }
    }

    int ans = INT_MAX;
    for (auto it = steps_to_reach.begin(); it != steps_to_reach.end(); ++it) {
        auto steps = it->second;
        ans = min(ans, steps);
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