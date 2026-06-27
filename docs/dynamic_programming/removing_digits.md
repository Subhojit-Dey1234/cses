# Removing Digits

**Problem:** Given n, repeatedly subtract one of its digits until you reach 0. Find the minimum number of steps.

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
