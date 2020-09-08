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
    vector <int> v;
    int n=0, x;
 
    while ((cin.peek() != '\n'))
    {
        cin >> x;
        n++;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> delta(n + 1);

    delta[2] = v[1] - v[0];
    if (n > 2){
        delta[3] = v[2] - v[0];
    }
 
    for (int i = 4;i <= n; i++)
    {
        int a; a = delta[i - 2] + v[i - 1] - v[i - 2];
        int b; b = delta[i - 1] + v[i - 1] - v[i - 2];
        delta[i] = min(a, b);
    }
 
    cout << delta[n] << "\n";
 
    return 0;
}