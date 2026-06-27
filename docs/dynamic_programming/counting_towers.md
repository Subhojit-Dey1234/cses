# Counting Towers

**Problem:** Count the number of ways to build a tower of height n using 2×1 blocks (placed either horizontally or vertically). Output modulo 10^9+7.

**State:**
- `dp[i][0]` = ways where column i has two separate width-1 tiles
- `dp[i][1]` = ways where column i has one width-2 tile

```cpp
#include <iostream>
#include<vector>
#define ll long long
using namespace std;

int main(){
    const ll N = 1000005;
    const ll mod = 1e9 + 7;

    vector<vector<ll>> dp(N, vector<ll>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(ll i = 2; i < N; i++){
        dp[i][1] = (2*(dp[i-1][1] % mod)) % mod + (dp[i-1][0] % mod);
        dp[i][0] = (dp[i-1][1] % mod) + (4*(dp[i-1][0] % mod)) % mod;
    }

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << (dp[n][0] % mod + dp[n][1] % mod) % mod << "\n";
    }
}
```
