# Coins Combinations II

**Problem:** Count the number of unordered ways to produce a sum `x` using given coin denominations (repetition allowed, order does NOT matter).

**Approach:** Outer loop over coins, inner loop over sums → counts unordered multisets (classic unbounded knapsack counting).

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
