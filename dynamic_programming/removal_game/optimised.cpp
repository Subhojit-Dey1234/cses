#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;


/*

Approach:
    Whatever player 1 doesn't get, player 2 gets (every number is eventually taken by someone). So instead of tracking two separate scores, 
    just track the gap between them: (player1's total) - (player2's total). Player 1 wants this gap as big as possible; 
    player 2 wants it as small (as negative) as possible.

    dp[l][r] = difference of score1 and score2 if considering the game played only on interval [l, r].
*/


int main(){
    ll n;
    cin >> n;
    vector<ll> points(n);
    ll total = 0;
    for(ll& x : points){ cin >> x; total += x;}
    
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));

    for(ll l = n-1; l >= 0; l --){
        for(ll r = l; r < n; r ++){
            if(l == r) dp[l][r] = points[l];
            else{
                dp[l][r] = max(points[l] - dp[l+1][r], points[r] - dp[l][r-1]);
            }
        }
    }

    cout << (total + dp[0][n-1]) / 2 << endl;
}