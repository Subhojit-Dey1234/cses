# Book Shop

**Problem:** Given n books each with a price and page count, and a budget x, maximize the total pages you can buy.

**Approach:** Classic 0/1 Knapsack. `dp[j]` = max pages achievable with budget `j`.

```cpp
#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main(){
    ll n, x;
    cin >> n >> x;
    
    vector<ll> prices(n), pages(n);
    for(ll& p: prices) cin >> p;
    for(ll& p: pages) cin >> p;

    vector<ll> tmp(x+1);
    for(ll i = 1; i <= n; i++){
        vector<ll> curr(x+1);
        for(ll j = 1; j <= x; j++){
            ll with_item = LLONG_MIN;
            if(prices[i-1] <= j) with_item = tmp[j - prices[i-1]] + pages[i-1];
            curr[j] = max(with_item, tmp[j]);
        }
        tmp = curr;
    }
    cout << tmp[x] << endl;
}
```
