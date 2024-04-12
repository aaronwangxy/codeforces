#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;

    set<int> s {s1,s2,s3,s4};
    cout << 4-s.size() << "\n";
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