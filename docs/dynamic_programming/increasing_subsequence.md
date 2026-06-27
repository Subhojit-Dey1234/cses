# Increasing Subsequence

**Problem:** Find the length of the longest strictly increasing subsequence.

**Approach:** Patience sort using `lower_bound` — O(n log n).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> dp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    cout << dp.size() << endl;
}
```
