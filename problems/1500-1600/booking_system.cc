#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n;
    vt<int> c(n),p(n);
    for (int i = 0; i < n; ++i) cin >> c[i] >> p[i];
    cin >> k;
    vt<vt<int>> r(k, vt<int>(3));

    // max # of ppl, occupied, table #
    for (int i = 0; i < k; ++i) {
        int capacity;
        cin >> capacity;
        r[i] = {capacity, 0, i+1};
    }

    // value, # of ppl, request #
    vt<vt<int>> requests(n, vt<int>(3));
    for (int i = 0; i < n; ++i) {
        requests[i] = {p[i], c[i], i+1};
    }

    sort(requests.begin(), requests.end());
    sort(r.begin(), r.end());

    ll val = 0;
    int num_accept = 0;
    vt<vt<int>> ans;
    // greedy, go for highest values first
    for (int i = requests.size()-1; i > -1; --i) {
        for (int j = 0; j < r.size(); ++j) {
            if (r[j][0] >= requests[i][1] && r[j][1] == 0) {
                r[j][1] = 1;
                val += requests[i][0];
                num_accept += 1;
                ans.emplace_back(vt<int> {requests[i][2], r[j][2]});
                break;
            }
        }
    }
    cout << num_accept << " " << val << endl;
    for (int i = 0; i < ans.size(); ++i) {
        // Request #, table #
        cout << ans[i][0] << " " << ans[i][1] << endl;
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