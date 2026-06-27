# Coins Combinations II

**Problem:** Count the number of unordered ways to produce a sum `x` using given coin denominations (repetition allowed, order does NOT matter).

**Approach:** Outer loop over coins, inner loop over sums → counts unordered multisets (classic unbounded knapsack counting).


## Brute Force Solution

```cpp
#include <iostream>
#include <vector>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;

ll getTheNumberOfWays(ll target, ll coin_idx, vector<ll>& coins, vector<vector<ll>>& dp){
    if(target == 0) return 1;
    if(target < 0 || coin_idx >= (ll)coins.size()) return 0;
    if(dp[target][coin_idx] != -1) return dp[target][coin_idx];
    
    ll ans = 0;
    ans = (ans + getTheNumberOfWays(target, coin_idx + 1, coins, dp)) % mod;
    ans = (ans + getTheNumberOfWays(target - coins[coin_idx], coin_idx, coins, dp)) % mod;
    
    return dp[target][coin_idx] = ans;
}

int main(){
    ll n, target;
    cin >> n >> target;
    vector<ll> coins(n);
    for(ll &c : coins) cin >> c;
    vector<vector<ll>> dp(target+1, vector<ll>(n, -1));
    
    ll ans = getTheNumberOfWays(target, 0, coins, dp);
    cout << ans << endl;
    return 0;
}
```



## Optimised Solution

```cpp
#include <iostream>
#include<vector>
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

    for(ll i = 0; i < (ll)coins.size(); i++){
        for(ll t = coins[i]; t <= target; t++){
            dp[t] = (dp[t] + dp[t - coins[i]]) % mod;
        }
    }
    cout << dp[target] << endl;
}
```
