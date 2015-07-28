#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll count = 0;
        
        if(n & 1) { 
            cout << count << endl;
            continue;
        }
        else
            count++;
        
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                if(i % 2 == 0) {
                    count++;
                }
            } else 
                continue;
            
            ll o = n / i;
            if(o & 1 || o == i) continue;
            
            if(o % 2 == 0) count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
