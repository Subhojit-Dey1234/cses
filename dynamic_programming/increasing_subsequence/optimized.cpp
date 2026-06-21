#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> dp;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);

        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    cout << dp.size() << endl;
}
