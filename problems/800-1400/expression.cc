#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    vector<int> vals {a+b+c, a*b*c, (a+b)*c, a*(b+c)};

    cout << *max_element(vals.begin(), vals.end()) << "\n";
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