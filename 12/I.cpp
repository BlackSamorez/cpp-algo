#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;


vector<int> prefix(string s) {
    int n = (int)s.length();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 and s[i] != s[j]){
            j = p[j-1];
        }
        if (s[i] == s[j]){
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main()
{
    string line;
    getline(cin, line);
    vector<int> pi = prefix(line);
    
    if (line.length() % (line.length() - pi[line.length() - 1]) == 0){
        cout << line.length() / (line.length() - pi[line.length() - 1]);
    }
    else{
        cout << 1;
    }
    cout << endl;
return 0;
}