# Increasing Array

**Problem:** Given an array of n integers, make it non-decreasing by increasing elements. Find the minimum total increase needed.

```cpp
#include <iostream>
using namespace std;

int main(){
    long long n, prev;
    cin >> n;

    cin >> prev;
    n--;

    long long ans = 0;
    while(n--){
        long long curr;
        cin >> curr;

        int c = curr;

        if(curr < prev){
            ans += (prev - curr);
            c = prev;
        }
        prev = c;
    }

    cout << ans << endl;
}
```
