#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int path[n + 1][m + 1];

    for (int i = 0; i < m + 1 ; i++){
        path[0][i] = 0;
        path[n][i] = 0;
    }
    for (int i = 0; i < n + 1 ; i++){
        path[i][0] = 0;
        path[i][m] = 0;
    }
    path[0][1] = 1;
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            cin >> path[i][j];
        }
    }
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            if (path[i][j] == 1){
                path[i][j] = path[i - 1][j] + path[i][j - 1];
             }
        }
    }
    if (path[n][m]){
        cout << path[n][m] << "\n";
    } else {
        cout << "Impossible\n";
    }
return 0;
}