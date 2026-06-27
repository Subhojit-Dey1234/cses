# Projects

**Problem:** Given n projects each with start time, end time, and reward — select non-overlapping projects to maximize total reward.

**Approach:** Sort by end time. For each project, binary search for the last compatible project, then `dp[i] = max(skip, take + dp[last_compatible])`.

```cpp
#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

    sort(v.begin(), v.end(), [](const vector<ll>& a, const vector<ll>& b){
        return a[1] < b[1];
    });

    vector<ll> dp(n);
    for(ll i = 0; i < n; i++){
        ll st = v[i][0], cost = v[i][2];
        auto it = lower_bound(v.begin(), v.end(), st, [](const vector<ll>& row, ll val){
            return row[1] < val;
        });

        ll prev = 0;
        if(it != v.begin()){
            ll id = (it - 1) - v.begin();
            prev = dp[id];
        }

        dp[i] = cost + prev;
        if(i > 0) dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;
}
```
