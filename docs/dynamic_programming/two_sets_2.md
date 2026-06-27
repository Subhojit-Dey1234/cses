# Two Sets II

**Problem:** Count the number of ways to divide numbers `1..n` into two sets with equal sum. Output modulo 10^9+7.

**Approach:** If total sum is odd, answer is 0. Otherwise count subsets summing to `total/2` using 0/1 knapsack.

## Solution 1 — Bottom-up DP

```cpp
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;
    ll total = (n * (n+1)) / 2;
    if(total % 2){ cout << 0 << endl; return 0; }

    ll target = total / 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(target+1, 0));
    ll mod = 1e9 + 7;

    dp[0][0] = 1;
    for(ll x = 1; x <= n; x++){
        for(ll t = 1; t <= target; t++){
            if(t < x) dp[x][t] = dp[x-1][t];
            else dp[x][t] = (dp[x-1][t - x] + dp[x-1][t]) % mod;
        }
    }
    cout << dp[n][target] << endl;
}
```

## Solution 2 — Memoization

```cpp
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll f(ll x, ll n, ll total, vector<vector<ll>>& dp){
    const ll mod = 1e9 + 7;
    if(x > n) return 0;
    if(total < 0) return 0;
    if(total == 0) return 1;
    if(dp[x][total] != -1) return dp[x][total];
    return dp[x][total] = (f(x+1, n, total-x, dp) + f(x+1, n, total, dp)) % mod;
}

int main(){
    ll n;
    cin >> n;
    ll total = (n * (n+1)) / 2;
    if(total % 2){ cout << 0 << endl; return 0; }
    vector<vector<ll>> dp(n + 1, vector<ll>(total/2 + 1, -1));
    cout << f(1, n, total / 2, dp) << endl;
}
```
