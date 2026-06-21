#include <iostream>
#include<vector>
#include<map>
#include <climits>
#include <algorithm>
#define ll long long

using namespace std;

/*
For example 
    a = 3 b = 5
    output = 3

    - Cut the 3 X 5 rectangle into a square of size 3X3 and a rectangle of size 2X3
    - cut the 2X3 rectangle into a square of size 2X2 and a rectangle of size 2X1
    - Cut the 2X1 rectangle into square of 1X1

    a = 5 b = 10
    - cut the 5X5 and then 5X5 one stroke
*/

/*

dp[i][j] -> stores the minimum number of cuts required to cut an (i x j) rectangle into squares.
- dp[i][i] ( i == j) then no cuts required.
- dp[i][j] ( i != j)
    - horizontally -> dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1) [k -> [1...j]]
    - vertically -> dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1) [ k -> [1..i] ]
*/


int main(){
    ll a, b;
    cin >> a >> b;

    vector<vector<ll>> dp(a+1, vector<ll>(b+1, LLONG_MAX));
    for(ll i = 0; i < a + 1; i++){
        for(ll j = 0; j < b + 1; j ++){
            if(i == j) dp[i][j] = 0;
            else{
                // horizontal cuts
                for(ll k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }

                // vertical cuts
                for(ll k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}