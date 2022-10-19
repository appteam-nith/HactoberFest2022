#include<bits/stdc++.h>
using namespace std;

void LCS(string s1, string s2) {
    int n = s1.length(), m= s2.length();
    int a[n+1][m+1];
    for(int i =0; i<=n;i++) {
        a[i][0] = 0;
    }
    for(int i =0; i<=m;i++) {
        a[0][1] = 0;
    }

    for(int i = 0; i<=n; i++) {
        for(int j=0; j<= m; j++) {
            if(i==0|| j==0) { 
                a[i][j]=0;
            } else if(s1[i-1] == s2[j-1]) {
                a[i][j] = 1+a[i-1][j-1];
            } else {
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    cout << a[n][m] <<"\n";
    int index = a[n][m];
    string b ="";
    int i = n, j=m;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {  
            b = s1[i-1] + b;
            i--; j--;
        }else if (a[i-1][j] > a[i][j-1]) i--;
        else j-- ;
    }
    cout << b <<"\n";

}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    LCS(s1,s2);


}