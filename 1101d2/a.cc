#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
what value to converge to?
is it always better to merge to an existing value?

goal is to find a value s.t. num values smaller than it == num values greater than it

for a given value, to merge to it it's max(num values smaller than it, num values greater than it)

should they all meet at a point that's in the array? yes (probably)
*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    int ans = INT_MAX;
    for (auto a : arr) {
        int num_smaller = 0;
        int num_larger = 0;
        for (auto a2 : arr) {
            if (a2 < a) {
                num_smaller += 1;
            } else if (a2 > a) {
                num_larger += 1;
            }
        }
        ans = min(ans, max(num_smaller, num_larger));
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