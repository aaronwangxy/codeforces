#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
If it's an odd number, then it will go to 1 and forever stay at 1.
If it's an even number, it will alternate between 0 and 2
*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    int num_1 = 0;
    int num_0 = 0;
    int num_2 = 0;

    int mx = *max_element(arr.begin(), arr.end());
    int num_ops = mx / 2;

    for (auto a : arr) {
        if (a % 2) {
            num_1 += 1;
        } else {
            int num_ops_to_0 = a / 2;
            int rem = num_ops - num_ops_to_0;
            if (rem % 2) {
                num_2 += 1;
            } else {
                num_0 += 1;
            }
        }
    }

    cout << max(max(num_0, num_2), num_1) << "\n";
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