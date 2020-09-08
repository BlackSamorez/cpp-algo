#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;


int levenstein_distance(string A, string B)
{
    // 2D array of answers - to be filled in.
    vector<vector<int>> L;
    L.resize(A.length() + 1);
    for (int i = 0; i <= A.length(); i++){
        L[i].resize(B.length() + 1);
    }

    // base cases:
    for (int i = 0; i <= A.length(); i++){
        L[i][0] = i;
    }
    for (int k = 0; k <= B.length(); k++){
        L[0][k] = k;
    }

    // recursive cases:
    for (int i = 1; i <= A.length(); i++){
        for (int k = 1; k <= B.length(); k++){
            if (A[i - 1] == B[k - 1]) // Last chars are the same!
                L[i][k] = L[i - 1][k - 1];
            else  // Last chars are different - so we need to add or remove last in a or b.
                L[i][k] = min(min(L[i - 1][k], L[i][k - 1]), L[i - 1][k - 1]) + 1;
        }
    }

    return L[A.length()][B.length()];
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << levenstein_distance(a, b) << "\n";
return 0;
}