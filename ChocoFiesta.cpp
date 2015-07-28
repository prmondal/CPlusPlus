#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long n;
    cin >> n;
    /*vector<long> list;
    
    for(int i = 0; i < n; i++) {
        long a; cin >> a;
        if(a & 1) continue;
        list.push_back(a);
    }
    
    unsigned long long result;
    result = ((unsigned long long) pow(2.0, list.size()) - 1) % 1000000007;*/
    unsigned long long result = (unsigned long long) pow(2.0, n) ;
    
    cout << result;
    return 0;
}
