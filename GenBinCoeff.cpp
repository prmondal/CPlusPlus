#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000
#define MOD 1000000009

unsigned long long binomial[MAX + 1][MAX + 1];

unsigned long long bin(int n, int k) {
   if(n < k)
     return 0;
    
   if(k == 0 || k == n) {
       binomial[n][k] = 1;
       return 1;
   }
   
   if(binomial[n][k])
     return binomial[n][k];
    
   binomial[n][k] = (bin(n - 1, k - 1) % MOD + bin(n - 1, k) % MOD) % MOD;
   return binomial[n][k];
}

int main() {
    for(int i = 1; i <= MAX; i++)
        for(int j = 1; j <= MAX; j++)
            bin(i, j);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        for(int i = 0; i <= n; i++)
            if(i != n) cout << bin(n, i) << " ";
            else cout << bin(n, i);
            
        cout << endl;
    }
    
    return 0;
}
