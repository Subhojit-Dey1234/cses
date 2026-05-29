#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;

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
            ll with_consider = LLONG_MIN;
            if(prices[i-1] <= j) with_consider = tmp[j - prices[i-1]] + pages[i-1];
            curr[j] = max(with_consider, tmp[j]);
        }
        tmp = curr;
    }


    cout << tmp[x] << endl;
}