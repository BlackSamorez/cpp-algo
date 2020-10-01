#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h> 
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	vector<int> ways(n, 0);
	//vector<vector<int>> conn(n, vecyot<int>(n, 0));
	ways[0] = 1;
	for (int i = 0; i < n - 1; i++){
		if (i + num[i] < n){
			if (num[i] != 1){
				ways[i + num[i]] += ways[i];
				ways[i + num[i]] = ways[i + num[i]] % 937;
			}
		}
		ways[i + 1] += ways[i];
		ways[i + 1] = ways[i + 1] % 937;
	}
	cout << ways[n - 1] << "\n";

return 0;
}