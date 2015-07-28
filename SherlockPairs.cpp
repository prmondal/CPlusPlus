#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    long count,t,n;
    
    cin >> t;
    while(t--) {
        cin >> n;
        long input, result = 0;
        map<long, long> m;
        
        for(int i = 0; i < n; i++) {
            cin >> input;
            m[input]++;
        }
        
        for(map<long, long>::iterator it = m.begin(); it != m.end(); ++it) {
            long v = it->second;
            
            result += v * (v - 1) / 2;
        }
        
        cout << 2 * result << endl;
    }
    return 0;
}
