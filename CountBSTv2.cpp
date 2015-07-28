#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5000
unsigned long long cat[MAX + 1];
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
    
   binomial[n][k] = (bin(n - 1, k - 1) + bin(n - 1, k)) % 1000000009;
   return binomial[n][k];
}

unsigned long long catalan(int n) {
    if(n == 0 || n == 1) {
        cat[n] = 1;
        return 1;
    }
    
    if(cat[n]) return cat[n];
    
    for(int i = 0; i < n; i++)
      cat[n] = (cat[n] + (catalan(i) * catalan(n - i - 1) % 1000000009)) % 1000000009;  
    
    return cat[n];
}

int main() {
    for(int i = 1; i <= MAX; i++) {
        catalan(i);
    }
    
    for(int i = 1; i <= MAX; i++)
        for(int j = 1; j <= MAX; j++)
            bin(i, j);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        unsigned long long count = 0;
        
        for(int j = 1; j <= n; j++) {
            count = (count + binomial[n][j] * cat[j]) % 1000000009;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
