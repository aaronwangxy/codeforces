#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
First ball cannot move left. No ball can stay still. Last ball cannot move right
Must find a value such that every pair of balls swaps

*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;
    int lower = 1e9+1;
    int upper = 0;
    for (int i = 0; i < n; i += 2) {
        lower = min(lower, arr[i]-1);
    }
    for (int i = 1; i < n; i += 2) {
        upper = max(upper, arr[i]+1);
    }
    if (lower >= upper && n % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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