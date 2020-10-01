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
    int n, b;
    cin >> n >> b;
    int pr[n], wh[n];
    int c[n + 1][b + 1];
    for (int i = 0; i < n; i++){
        cin >> wh[i] >> pr[i];
    }
    for (int j = 0; j < b + 1; j++){
        c[0][j] = 0;
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 0; j < b + 1; j++){
            if (j >= wh[i - 1]){
                c[i][j] = max(pr[i - 1] + c[i - 1][j - wh[i - 1]], c[i - 1][j]);
            } else {
                c[i][j] = c[i - 1][j];
            }
        }
    }

        cout << c[n][b] << "\n";

    return 0;
}
