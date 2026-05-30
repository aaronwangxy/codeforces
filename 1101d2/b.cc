#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
binary search for max and validate in linear? nlogn
    - doesn't work for populating array of n
    - need some linear sweep
length
1: just the first element

maybe: maintain something cumulative
note: decreasing, can never increase
*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    ll cum_sum = arr[0];
    ll excess_frosting = 0;
    vt<ll> ans(n);
    ans[0] = arr[0];
    ll curr_max = arr[0];
    for (int i = 1; i < n; ++i) {
        // what's max height for this prefix?
        // something between arr[i] and curr_max, have some excess_frosting
        // can decrease curr_max by k to get k*i more excess frosting
        // looking for a k that maximizes min(arr[i] + excess_frosting + k*i, curr_max - k)
        // solve for k s.t. arr[i] + excess_frosting + k*i = curr_max - k (ideal)
        //      k*(i+1) = curr_max - arr[i] - excess_frosting
        // check k above and below for what maximizes that min
        cum_sum += arr[i];
        if (arr[i] + excess_frosting >= curr_max) {
            ans[i] = curr_max;
            excess_frosting = excess_frosting - (curr_max - arr[i]);
            continue;
        }
        // i = 1
        // (should be 2 with excess 0)
        // i = 2
        // should be 1
        int k = (curr_max - arr[i] - excess_frosting) / (i+1);
        int k2 = k + 1;
        ans[i] = max(arr[i] + excess_frosting + k*i, curr_max - k2);
        curr_max = ans[i];
        excess_frosting = cum_sum - (i+1)*curr_max;
    }

    for (auto a : ans) cout << a <<  " ";
    cout << "\n";
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