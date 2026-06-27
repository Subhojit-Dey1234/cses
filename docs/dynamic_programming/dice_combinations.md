# Dice Combinations

**Problem:** Count the number of ways to construct sum `n` by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

**Constraints:** 1 ≤ n ≤ 10^6

**Approach:** `dp[i]` = number of ways to reach sum `i`. For each `i`, try subtracting each dice value 1–6.

## Solution 1 — Bottom-up DP

```cpp
#include <iostream>
#include<vector>
using namespace std;

int main(){
    long long n;
    const long long mod = 1e9 + 7;
    cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    
    for(long long i = 1; i <= n; i++){
        for(long long dice = 1; dice <= 6; dice ++){
            if(i - dice >= 0) dp[i] = (dp[i] + dp[i - dice]) % mod;
        }
    }
    cout << dp[n] << endl;
}
```

## Solution 2 — Top-down Memoization

```cpp
#include <iostream>
#include<vector>
using namespace std;

long long getTheNumberOfCombinations(long long n, vector<long long>& dp){
    const long long mod = 1e9 + 7;
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];

    long long cnt = 0;
    for(int i = 1; i <= 6; i++){
        cnt = (cnt + getTheNumberOfCombinations(n - i, dp)) % mod;
    }
    return dp[n] = cnt;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(n+1, -1);
    cout << getTheNumberOfCombinations(n, dp) << endl;
}
```
