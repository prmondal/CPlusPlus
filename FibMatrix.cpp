#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long f[2][2];

void multiply(long long f[][2], long long m[][2]) {
    long long x, y, w, z;
    
    x = f[0][0] * m[0][0] + f[0][1] * m[1][0];
    y = f[0][0] * m[0][1] + f[0][1] * m[1][1];
    w = f[1][0] * m[0][0] + f[1][1] * m[1][0];
    z = f[1][0] * m[0][1] + f[1][1] * m[1][1];
    
    f[0][0] = x; f[0][1] = y; f[1][0] = w; f[1][1] = z;
}

void power(long long f[][2], long long n) {
    if(n == 0 || n == 1)
        return;
    
    power(f, n / 2);
    multiply(f, f);
    
    if(n % 2 != 0) {
        long long m[][2] = {{1, 1}, {1, 0}};
        multiply(f, m);
    }
}

void fib(long n) {
    //f[0][0] = f[0][1] = f[1][0] = 1; f[1][1] = 0;
    f[0][0] = 1; f[0][1] = f[1][0] = 1; f[1][1] = 0;
    power(f, n - 1);
}

int main() {
    /*for(int i = 1; i <= 20; i++) {
        fib(i, 0, 1);
        cout << f[0][0] << endl;
    }*/
    int t;
    cin >> t;
    while(t-- > 0) {
        long long A, B, N;
        cin >> A >> B >> N;
        
        if(N == 0)
            cout << A << endl;
        else if(N == 1) 
            cout << B << endl;
        else {
            fib(N);
            long long m[][2] = {{B, 0}, {A, 0}};
            multiply(f, m);
            cout << f[0][0] << endl;
        }
    }
    
    return 0;
}
