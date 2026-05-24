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

int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n+1, LLONG_MAX);
    dp[1] = 1;
    dp[0] = 0;
    for(ll i = 2; i <= n; i++){
        vector<ll> mp = getTheDigits(i);
        for(ll m : mp){
            ll x = i - m;
            if(x >= 0){
                ll cnt = dp[x];
                if(cnt != LLONG_MAX) cnt ++;
                dp[i] = min(dp[i], cnt);
            }
        }
    }

    cout << dp[n] << endl;
}