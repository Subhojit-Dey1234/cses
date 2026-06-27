# Removal Game

**Problem:** Two players alternately pick a number from either end of an array. Both play optimally. Find player 1's maximum score.

**Key insight:** Track the score gap `dp[l][r]` = (player1 score) − (player2 score) for the subarray `[l, r]`. Player 1 maximizes, player 2 minimizes. Final answer = `(total + dp[0][n-1]) / 2`.

```cpp
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> points(n);
    ll total = 0;
    for(ll& x : points){ cin >> x; total += x; }
    
    vector<vector<ll>> dp(n, vector<ll>(n));

    for(ll l = n-1; l >= 0; l--){
        for(ll r = l; r < n; r++){
            if(l == r) dp[l][r] = points[l];
            else dp[l][r] = max(points[l] - dp[l+1][r], points[r] - dp[l][r-1]);
        }
    }

    cout << (total + dp[0][n-1]) / 2 << endl;
}
```
