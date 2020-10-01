#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;

void great(int *numb, int n, int k, int *sim, int *count, int *path, int len){
    *count = *count + 1;
    //cout << numb[k] <<"\n";
    for (int i = k + 1; i < n; i++){
        int check = 1;
        for (int step = 0; step < len; step++){
            if (sim[path[step] * n + i] == 0){
                check = 0;
            }
        }
        if (check){
            path[len] = i;
            great(numb, n, i, sim, count, path, len + 1);
        }
    }
}


int main(){
    int n;
    cin >> n;
    int numb[n];
    vector<vector<bool>> sim(n, vector<bool>(n));
    for (int i = 0; i < n; i++){
        cin >> numb[i];
    }
    sort(numb, numb + n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //cout << __gcd(numb[i],numb[j]) << " sas\n";
            if (__gcd(numb[i], numb[j]) == 1){
                sim[i][j] = 1;
            } else {
                sim[i][j] = 0;
            }
        }
        sim[i][i] = 1;
    }
    int ommited = 0;
    for (int i = 0; i < n; i++){
        int test = 1;
        for (int j = 0; j < n; j++){
            if (not sim[i][j]){
                test = 0;
            }
        }
        if (test){
            ommited++;
            numb[i] = 0;
        }
    }
    //cout << ommited << " o\n";
    int new_numb[n - ommited];
    int k = 0;
    for (int i = 0; i < n - ommited; i++){
        while (numb[k] == 0){
            k++;
        }
        new_numb[i] = numb[k];
        //cout << new_numb[i] << " new\n";
        k++;
    }
    int new_sim[(n - ommited) * (n - ommited)];
    for (int i = 0; i < n - ommited; i++){
        for (int j = 0; j < n - ommited; j++){
            if (__gcd(new_numb[i], new_numb[j]) == 1){
                new_sim[i * (n - ommited) + j] = 1;
            } else {
                new_sim[i * (n - ommited) + j] = 0;
            }
        }
    }

    int last_sim[n * n];


    int *count = new int;
    *count = 1;
    for (int i = 0; i < n - ommited; i++){
        int path[n - ommited];
        path[0] = i;
        //cout << path[0] <<" sas\n";
        great(new_numb, n - ommited, i, new_sim, count, path, 1);
    }
    //cout << *count << "\n";
    *count = *count * pow(2, ommited);
    cout << *count << "\n";
    delete [] count;
return 0;
}