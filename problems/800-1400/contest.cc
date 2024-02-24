#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

int pts(int a, int t) {
    return max(3*a/10, a-a/250*t);
}

void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int M = pts(a,c);
    int V = pts(b,d);
    if (M < V) {
        cout << "Vasya\n";
    } else if (M > V) {
        cout << "Misha\n";
    } else {
        cout << "Tie\n";
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