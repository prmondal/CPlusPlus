#include <iostream>
#include <string.h>

using namespace std;

string rev(string s) {
    int i, l = s.length();
    
    for(i = 0; i < l / 2; i++) {
        char t = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = t;
    }
    
    return s;
}

//find longest common suffix of between two substrings
void printLongestPalindromeSubstring(string s) {
    int maxLen = 0, n = s.length(), start = -1;
    
    bool t[n][n];
    
    memset(t, false, sizeof(t));
    
    //single length string is palindrome
    for(int i = 0; i < n; i++) {
        t[i][i] = true;
        
        maxLen = 1;
        start = i;
    }
    
    //check for two length string 
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) {
            maxLen = 2;
            start = i;
            
            t[i][i + 1] = true;
        }    
    }
    
    //consider all other lengths
    for(int l = 3; l <= n; l++) {
        for(int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            
            if(s[i] == s[j] && t[i + 1][j - 1]) {
                t[i][j] = true;
                
                maxLen = l;
                start = i;
            }
        }
    }
    
    //print max length suffix
    cout << s.substr(start, maxLen) << " with length " << maxLen << endl;
}

int main() {
    string s = "geeggeeks";//"sabsvbasvbavbsvabvsbavbsvbavbsvbavsbvavsbavvdavhdbsbdjbandabdbabdabjsbjasbavdvavdadbadbjabdsbbdsvdvavad";
    
    //getline(cin, s, '\n');
    
    printLongestPalindromeSubstring(s);
    
    return 0;
}