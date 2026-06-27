# Minimizing Coins

**Problem:** Given coin denominations and a target sum, find the minimum number of coins needed to reach the sum. Output -1 if impossible.

## Solution 1 — Bottom-up DP

```cpp
#include <iostream>
#include<vector>
#include <climits>
using namespace std;

int main(){
    long long n, target;
    cin >> n >> target;
    vector<long long> coins(n);
    vector<long long> dp(target + 1, LLONG_MAX);
    for(long long &c : coins) cin >> c;
    dp[0] = 0;
    for(long long t = 1; t <= target; t ++){
        for(long long i = 0; i < n; i++){
            if(t - coins[i] < 0) continue;
            long long d = dp[t - coins[i]];
            if(d != LLONG_MAX) d++;
            dp[t] = min(dp[t], d);
        }
    }

    if(dp[target] == LLONG_MAX) cout << -1 << endl;
    else cout << dp[target] << endl;
}
```

## Solution 2 — Top-down Memoization

```cpp
#include <iostream>
#include<vector>
#include <climits>
using namespace std;

long long solve(long long target, vector<long long>& coins, vector<long long>& dp){
    if(target < 0L) return LLONG_MAX;
    if(target == 0L) return 0;
    if(dp[target] != -1) return dp[target];

    long long ans = LLONG_MAX;
    for(long long i = 0; i < (long long)coins.size(); i++){
        long long sub = solve(target - coins[i], coins, dp);
        if(sub != LLONG_MAX) sub++;
        ans = min(ans, sub);
    }
    return dp[target] = ans;
}

int main(){
    long long n, target;
    cin >> n >> target;
    vector<long long> coins(n);
    vector<long long> dp(target + 1, -1);
    for(long long &c : coins) cin >> c;
    long long ans = solve(target, coins, dp);
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}
```
