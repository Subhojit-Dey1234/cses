#include <iostream>
#include<vector>
#include<map>
#include <climits>
#define ll long long
using namespace std;
int main(){
    const ll N=1000005;
    const ll modm = 1e9 + 7;

    vector<vector<ll>> dp(N, vector<ll>(2));
    
    dp[1][0] = 1;
	dp[1][1] = 1;

	for(ll i=2; i< N;i++){
		dp[i][1]=(2*(dp[i-1][1]%modm))%modm + (dp[i-1][0]%modm);
		dp[i][0]=(dp[i-1][1]%modm)+(4*(dp[i-1][0]%modm))%modm;
	}


    ll t; cin >> t;
    while(t--){
        ll n;
        cin >> n;
        /*
        dp[i][p]=Number of ways to fill from 0th position till the ith position.

        dp[i][0] => number of ways for the same such that ith position consist of 2 tiles of width 1 each.
        dp[i][1] => number of ways for the same such that ith position consist of 1 tile of width 2.
        */
		cout<<(dp[n][0]%modm+dp[n][1]%modm)%modm<<"\n";
    }
}