#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;

    int mx = 1;

    int l = 1, n = a.size();
    for(int i = 1; i < n; i++){
        if(a[i-1] == a[i]) l ++;
        else{
            mx = max(mx, l);
            l = 1;
        }
    }

    mx = max(mx, l);
    cout << mx << endl;
}