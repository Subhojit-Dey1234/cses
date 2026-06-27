# Array Description

**Problem:** Given a partially filled array (zeros mean unknown), count how many ways to fill the unknowns with values 1..m such that adjacent elements differ by at most 1.

**State:** `dp[i][x]` = number of valid ways to fill positions 0..i such that position i has value x.

```cpp
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(ll& x : v) cin >> x;

    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));

    if(v[0] == 0)
        for(ll x = 1; x <= m; x++) dp[0][x] = 1;
    else
        dp[0][v[0]] = 1;

    for(ll i = 1; i < n; i++){
        for(ll x = 1; x <= m; x++){
            if(v[i] != 0 && x != v[i]) continue;
            for(ll y = x-1; y <= x+1; y++)
                if(y >= 1 && y <= m)
                    dp[i][x] = (dp[i][x] + dp[i-1][y]) % mod;
        }
    }

    ll cnt = 0;
    for(ll x = 1; x <= m; x++) cnt = (cnt + dp[n-1][x]) % mod;
    cout << cnt << endl;
}
```
