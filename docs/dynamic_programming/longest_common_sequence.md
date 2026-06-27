# Longest Common Subsequence

**Problem:** Find the longest common subsequence of two arrays and print it.

```cpp
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for(ll& x : a) cin >> x;
    for(ll& x : b) cin >> x;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";
    vector<ll> ans;
    ll i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){ ans.push_back(a[i-1]); i--; j--; }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    for(ll k = ans.size()-1; k >= 0; k--) cout << ans[k] << " ";
}
```
