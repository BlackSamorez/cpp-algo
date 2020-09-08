#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair <int, int>> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end() );
    v.erase(unique(v.begin(), v.end()), v.end());
    int right = 0;
    for (int i=0; i < v.size(); i++){
        if (v[i].first + v[i].second == n - 1){
            right++;
        }
    }
    cout << right << "\n";
return 0;
}