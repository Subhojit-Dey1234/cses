# Coins Combinations I

**Problem:** Count the number of ordered ways to produce a sum `x` using given coin denominations (repetition allowed, order matters).

**Approach:** Outer loop over target sums, inner loop over coins → counts ordered sequences.

## Brute Force Solution

```cpp
#include <iostream>
#include<vector>
#include<map>
#include <climits>
#define ll long long

using namespace std;

ll getTheNumberOfWays(ll target, vector<ll>& coins, vector<ll>& dp){
    const ll mod = 1e9 + 7;
    if(target == 0L) return 1;
    if(target < 0L) return -1;

    if(dp[target] != -1) return dp[target];
    
    ll ans = 0;
    for(ll i = 0; i < (ll) coins.size(); i ++){
        ll cnt = getTheNumberOfWays(target - coins[i], coins, dp);
        if(cnt >= 0) ans = (ans + cnt)%mod;
    }
    return dp[target] = ans;
}


int main(){
    ll n, target;
    cin >> n >> target;
    vector<ll> coins(n);
    vector<ll> dp(target + 1, -1);
    for(ll &c : coins) cin >> c;
    ll ans = getTheNumberOfWays(target, coins, dp);
    cout << ans << endl;
}
```


## Optimized Solution
```cpp
#include <iostream>
#include<vector>
#include <climits>
#define ll long long
using namespace std;

int main(){
    ll n, target;
    const ll mod = 1e9 + 7;
    cin >> n >> target;
    vector<ll> coins(n);
    vector<ll> dp(target + 1);
    for(ll &c : coins) cin >> c;
    dp[0] = 1;

    for(ll t = 1; t <= target; t++){
        for(ll i = 0; i < (ll)coins.size(); i++){
            if(t < coins[i]) continue;
            dp[t] = (dp[t] + dp[t - coins[i]]) % mod;
        }
    }
    cout << dp[target] << endl;
}
```
