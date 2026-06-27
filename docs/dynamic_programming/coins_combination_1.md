# Coins Combinations I

**Problem:** Count the number of ordered ways to produce a sum `x` using given coin denominations (repetition allowed, order matters).

**Approach:** Outer loop over target sums, inner loop over coins → counts ordered sequences.

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
