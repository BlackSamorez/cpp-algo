#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

using namespace std;

int levenstein_distance(string s1, string s2, int I_cost, int D_cost, int R_cost){
    int M = s1.length();
    int N = s2.length();
    vector<vector<int>> D;
    D.resize(M + 1);
    for (int i = 0; i <= M; i++)
        D[i].resize(N + 1);
    // base cases:
    D[0][0] = 0;
    for (int i = 1; i <= M; i++)
        D[i][0] = D[i - 1][0] + D_cost;
    for (int j = 1; j <= N; j++)
        D[0][j] = D[0][j - 1] + I_cost;

    // recursive cases:
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            if (s1[i - 1] != s2[j - 1])
                D[i][j] = min(min(D[i - 1][j] + D_cost, D[i][j - 1] + I_cost), D[i - 1][j - 1] + R_cost);
            else
                D[i][j] = D[i - 1][j - 1];
        }
    }
  return D[M][N];
}


int main()
{
    int I_cost, D_cost, R_cost;
    cin >> I_cost >> D_cost >> R_cost;
    string A, B;
    cin >> A >> B;
    cout << levenstein_distance(A, B, I_cost, D_cost, R_cost ) << "\n";
return 0;
}