#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main() {
    int a = 0, b = 1;
    string line;
    getline(cin, line);
    
    for (int i = line.length(); i > 0 ; i--){
        if (line[i - 1] == '.'){
            b = 1 * b;
            a = a + b * 1;
        }
        if (line[i - 1] == '|'){
            b = 1 * b;
            a = a + b * 5;
        }
        if (line[i - 1] == ' '){
            b = 20 * b;
        }
    }
    
    cout << a << "\n";    
return 0;
}
