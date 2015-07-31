#include <iostream>
#include <string>
#include <climits>

using namespace std;

string rev(string s) {
    int i,
        l = s.size();
    
    for(i = 0; i < l / 2; i++) {
        char t = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = t;
    }
    
    return s;
}

//find longest common suffix of between two substrings
void printLongestPalindromeSubstring(string s, string revStr) {
    int maxLen = INT_MIN;
    string res;
    
    int n = s.size();
    int t[n + 1][n + 1];
    
    for(int i = 0; i <= n; i++) {
        t[i][0] = 0;
    }
    
    for(int j = 0; j <= n; j++) {
        t[0][j] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            t[i][j] = (s[i - 1] == revStr[j - 1]) ? 1 + t[i - 1][j - 1] : 0;
            
            if(t[i][j] > maxLen) {
                maxLen = t[i][j];
                res = s.substr(i - maxLen, maxLen);
            }
        }
    }
    
    //print max length suffix
    cout << res << " with length " << maxLen << endl;
}

int main() {
    string s;
    
    getline(cin, s, '\n');
    
    printLongestPalindromeSubstring(s, rev(s));
    
    return 0;
}