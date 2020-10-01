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
	vector<int> color(n);
	vector<int> paint(n);
	vector<int> ways(n, 0);
	for (int i = 0; i < n; i++){
		cin >> color[i];
	}
	for (int i = 0; i < n; i++){
		cin >> paint[i];
	}
	ways[n - 1] = 1;
	for (int i = n - 1; i > 1; i--){
		if (color[i - 1] == color[i] or paint[i - 1] == color[i]){
			ways[i - 1] += ways[i];
			ways[i] = ways[i] % 947;
		}
		if (color[i - 2] == color[i] or paint[i - 2] == color[i]){
			ways[i - 2] += ways[i];
			ways[i] = ways[i] % 947;
		}
	}
	if (color[0] == color[1] or paint[0] == color[1]){
		ways[0] += ways[1];
		ways[0] = ways[0] % 947;
	}
	cout << ways[0] << "\n";
return 0;
}