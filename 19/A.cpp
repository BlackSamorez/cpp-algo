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
    vector<int> input(n);
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    input.erase(unique(input.begin(), input.end()), input.end());
    cout << input.size() << "\n";
return 0;
}