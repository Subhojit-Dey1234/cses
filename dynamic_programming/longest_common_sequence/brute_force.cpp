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
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for(ll& x : a) cin >> x;
    for(ll& x : b) cin >> x;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for(ll i = 1; i < n+1; i++){
        for(ll j = 1; j < m+1; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;
    vector<ll> ans;
    ll i = n, j = m;

    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i --;
            j --;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i --;
        else j --;
    }
    
    for(ll i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
}