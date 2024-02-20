
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve() {
    int x,n;
    cin >> x >> n;
 
    // Find largest divisor d such that x/d > n
    int MAX = 0;
    for (int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            int d = x/i;
            if (x/d >= n) {
                MAX = max(MAX, d);
            }
            if (x/i >= n) {
                MAX = max(MAX, i);
            }
        }
    }
    cout << MAX << endl;
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