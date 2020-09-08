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
    vector<int> p = prefix(line);
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    cout << "\n";
return 0;
}