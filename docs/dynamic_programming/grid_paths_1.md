# Grid Paths

**Problem:** Count the number of paths from the top-left to the bottom-right of an n×n grid. Some squares are trapped (`*`). You can only move right or down.

```cpp
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> grid[i][j];
    if(grid[0][0] != '*') dp[0][0] = 1;

    const ll mod = 1e9 + 7;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] != '*')
                dp[i][j] = ((i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0)) % mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
}
```
