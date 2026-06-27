# Rectangle Cutting

**Problem:** Given an a×b rectangle, cut it into squares using the minimum number of cuts.

**Approach:** `dp[i][j]` = min cuts to cut an i×j rectangle into squares. Try all horizontal and vertical cuts.

```cpp
#include <iostream>
#include<vector>
#include<map>
#include <climits>
#include <algorithm>
#define ll long long

using namespace std;
/*

dp[i][j] -> stores the minimum number of cuts required to cut an (i x j) rectangle into squares.
- dp[i][i] ( i == j) then no cuts required.
- dp[i][j] ( i != j)
    - horizontally -> dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1) [k -> [1...j]]
    - vertically -> dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1) [ k -> [1..i] ]
*/


int main(){
    ll a, b;
    cin >> a >> b;

    vector<vector<ll>> dp(a+1, vector<ll>(b+1, LLONG_MAX));
    for(ll i = 0; i < a + 1; i++){
        for(ll j = 0; j < b + 1; j ++){
            if(i == j) dp[i][j] = 0;
            else{
                // horizontal cuts
                for(ll k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }

                // vertical cuts
                for(ll k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}
```
