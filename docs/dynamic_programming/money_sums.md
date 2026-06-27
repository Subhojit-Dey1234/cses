# Money Sums

**Problem:** Given n coins with values, find all distinct money sums you can create using subsets of the coins.

**Approach:** 2D DP where `dp[i][t]` = true if sum `t` is achievable using the first `i` coins.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> coins(n);
    long long s = 0;
    for(long long &c : coins){ cin >> c; s += c; }

    vector<vector<bool>> dp(n+1, vector<bool>(s+1, 0));
    dp[0][0] = 1;
    for(long long i = 1; i < n+1; i++) dp[i][i] = 1;

    long long cnt = 0;
    for(long long i = 1; i < n+1; i++){
        for(long long t = 0; t < s+1; t++){
            dp[i][t] = dp[i-1][t];
            if((t - coins[i-1]) >= 0 && dp[i-1][t - coins[i-1]]) dp[i][t] = 1;
            if(i == n) cnt += dp[n][t];
        }
    }
    cout << (cnt - 1) << "\n";
    for(long long j = 1; j < s+1; j++)
        if(dp[n][j]) cout << j << " ";
}
```
