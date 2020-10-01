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
    int number;
    vector<int> v;
    int count = 0;
    for (int i = 0; i < n; i++){
        cin >> number;
        if ((number % 4 == 0) && (number / 1000 != 4) && (number / 1000 != 5)){
            v.push_back(number);
            count++;
        } else if ((number % 7 == 0) && (number / 1000 != 7) && (number / 1000 != 1)){
            v.push_back(number);
            count++;
        } else if((number % 9 == 0) && (number / 1000 != 9) && (number / 1000 != 8)){
            v.push_back(number);
            count++;
        }
    }
    for (int i = 0; i < count; i++){
        cout << v[i] << "\n";
    }
    if (count == 0){
        cout << "0\n";
    }
return 0;
}