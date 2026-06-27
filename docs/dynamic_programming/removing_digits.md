# Removing Digits

**Problem:** Given n, repeatedly subtract one of its digits until you reach 0. Find the minimum number of steps.

## Brute Force Solution

```cpp
#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;

vector<ll> getTheDigits(ll a){
    vector<ll> digits;
    unordered_set<ll> seen;
    while(a){
        ll r = a % 10;
        if(r != 0 && seen.find(r) == seen.end()){
            digits.push_back(r);
            seen.insert(r);
        }
        a = a / 10;
    }
    return digits;
}

ll getTheNumberOfWays(ll n, vector<ll>& dp){
    if(n < 0) return LLONG_MAX;
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    ll ans = LLONG_MAX;
    auto mp = getTheDigits(n);
    for(auto m : mp){
        ll x = n - m;
        if(x >= 0){
            ll cnt = getTheNumberOfWays(x, dp);
            if(cnt != LLONG_MAX) cnt ++;
            ans = min(cnt, ans);
        }
    }
    return dp[n] = ans;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    cout << getTheNumberOfWays(n, dp) << endl;
}
```


## Optimized Solution

```cpp
#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

vector<ll> getDigits(ll a){
    vector<ll> digits;
    while(a){
        ll r = a % 10;
        if(r != 0) digits.push_back(r);
        a /= 10;
    }
    return digits;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n+1, LLONG_MAX);
    dp[0] = 0;
    for(ll i = 1; i <= n; i++){
        for(ll d : getDigits(i)){
            ll x = i - d;
            if(dp[x] != LLONG_MAX)
                dp[i] = min(dp[i], dp[x] + 1);
        }
    }
    cout << dp[n] << endl;
}
```
