#include <iostream>
#include<vector>
#include<map>
#include <climits>
#include<algorithm>

#define ll long long
using namespace std;
int main(){
    ll n; cin >> n;

    vector<vector<ll>> v(n, vector<ll>(3));
    for(int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    // sorting with the ending point greater than. Increasing order of the ending one
    sort(v.begin(), v.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] < b[1];
    });

    vector<ll> dp(n);
    for(ll i = 0; i < n; i++){
        ll st = v[i][0], cost = v[i][2];
        
        // what is the nearest ending_point from the current start
        auto it = lower_bound(v.begin(), v.end(), st, [](const vector<ll>& row, ll val) {
            return row[1] < val;
        });

        ll prev = 0;
        if(it != v.begin()){
            // lower_bound gives first end >= st so go one back it - 1
            ll id = (it - 1) - v.begin(); // last project with end < st
            prev = dp[id];
        }

        dp[i] = cost + prev; // take the current one
        if(i > 0) dp[i] = max(dp[i], dp[i-1]); // skip or take
    }

    cout << dp[n-1] << endl;
}