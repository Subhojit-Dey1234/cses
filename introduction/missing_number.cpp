#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;

    int x = 0;
    for(long long i = 1; i <= n; i++) x = x ^ i;
    n --;

    while(n --){
        long long a;
        cin >> a;
        x = x ^ a;
    }

    cout << x << endl;
}