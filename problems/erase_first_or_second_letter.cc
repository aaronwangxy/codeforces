#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> seen(n);
    seen[0] = 1;
    unordered_set<char> mys;
    mys.insert(s[0]);

    for (int i = 1; i < n; ++i) {
        seen[i] = seen[i-1];
        if (mys.find(s[i]) == mys.end()) {
            mys.insert(s[i]);
            seen[i] += 1;
        }
    }

    int unique = 0;
    for (int i = 0; i < n; ++i) {
        unique += seen[n-1-i];
    }
    cout << unique << endl;
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