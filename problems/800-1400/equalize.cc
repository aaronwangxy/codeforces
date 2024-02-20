#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_set<int> nums;
    for (auto& v : a) nums.insert(v);
    vt<int> fa;
    for (auto& v : nums) fa.push_back(v);
    sort(fa.begin(), fa.end());

    int r;
    int l = 0;
    for (r = 1; r < fa.size(); ++r) {
        if (fa[r] - fa[l] >= n) {
            l += 1;
        }
    }
    cout << r-l << endl;
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