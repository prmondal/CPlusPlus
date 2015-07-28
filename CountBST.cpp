#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5000
unsigned long long cat[MAX + 1];
unsigned long long binomial[2 * MAX + 1][2 * MAX + 1];

unsigned long long bin(int n, int k) {
   if(n < k)
     return 0;
    
   if(k == 0 || k == n) {
       binomial[n][k] = 1;
       return 1;
   }
   
   if(binomial[n][k])
     return binomial[n][k];
    
   binomial[n - 1][k - 1] = bin(n - 1, k - 1);
   binomial[n - 1][k] = bin(n - 1, k);
   
   return binomial[n - 1][k - 1] + binomial[n - 1][k];
}

unsigned long long catalan(int n) {
    return (bin(2 * n, n) / (n + 1)) % 1000000009;
}

int main() {
    for(int i = 1; i <= MAX; i++) {
        cat[i] = catalan(i);
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        unsigned long long count = 0;
        
        for(int j = 1; j <= n; j++) {
            count += binomial[n][j] * cat[j];
        }
        
        cout << count % 1000000009 << endl;
    }
    
    return 0;
}
