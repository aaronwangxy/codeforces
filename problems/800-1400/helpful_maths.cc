#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    vt<int> a;
    for (auto c:s) {
        if (c != '+') {
            a.emplace_back(c - '0');
        }
    }
    sort(a.begin(), a.end());

    string ans;
    for (int i = 0; i < a.size(); ++i) {
        ans += (a[i] + '0');
        ans += "+";
    }
    cout << ans.substr(0,ans.size()-1) << "\n";
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